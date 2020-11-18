#include <iostream>
#include "model/hydraulic_erosion.hpp"

HydraulicErosion::HydraulicErosion(unsigned int seed, unsigned int nDroplets, unsigned int dropletLifetime,
				   float dropletInitialSpeed, float dropletInitialVolume)
: seed(seed), nDroplets(nDroplets), generator(seed), dropletLifetime(dropletLifetime),
dropletInitialSpeed(dropletInitialSpeed), dropletInitialVolume(dropletInitialVolume)
{}

void HydraulicErosion::erode(Terrain &terrain)
{
	unsigned int mapWidth = terrain.getNPointsWidth();
	unsigned int mapHeight = terrain.getNPointsLength();
	std::uniform_real_distribution<float> distributionW(0, mapWidth - 1);
	std::uniform_real_distribution<float> distributionH(0, mapHeight - 1);
	for (unsigned i = 0; i < nDroplets; ++i)
	{
		//rain droplet at random point on map
		float x = distributionW(generator);
		float y = distributionH(generator);

		//guarantee no droplet exactly on border, effectively making distributions open intervals
		//as opposed to half open intervals they are by default
		while (x == 0 or x == mapWidth - 1) x = distributionW(generator);
		while (y == 0 or y == mapHeight - 1) y = distributionW(generator);

		Droplet droplet(glm::vec2(x, y), dropletInitialSpeed, dropletInitialVolume);

		for (unsigned lifetime = 0; lifetime < dropletLifetime; ++lifetime)
		{
			//calculate droplet height and direction of flow
			Droplet oldDroplet = droplet;

			float dropletHeight = getDropletHeight(droplet, terrain);
			droplet.direction = droplet.direction * dropletInertia
					    - getDropletDirection(droplet, terrain)
					      * (1 - dropletInertia);
			if (droplet.direction != glm::vec2(0, 0))
				droplet.direction = glm::normalize(droplet.direction);

			//update droplet position (1 unit regardless of speed so as not to skip over sections of map)
			droplet.position += droplet.direction;
			droplet.updateOffsets();

			//check if droplet stopped or crossed over the edge
			if (droplet.direction == glm::vec2(0, 0) or droplet.position.x <= 0 or droplet.position.y <= 0
			    or droplet.position.x >= mapWidth - 1 or droplet.position.y >= mapHeight - 1)
				break;

			//find new height and get deltaH
			float newHeight = getDropletHeight(droplet, terrain);
			float deltaH = newHeight - dropletHeight;

			//calculate droplet sediment capacity (higher when moving fast down a slope and contains a lot of water)
			float sedimentCapacity = std::max(-deltaH * droplet.speed * droplet.water * sedimentCapacityFactor, minSedimentCapacity);

			//if carrying more sediment than capacity or flowing up a slope
			//deposit fraction of sediment to surrounding nodes
			if (deltaH > 0 or droplet.sediment > sedimentCapacity)
			{
				//calculate amount of sediment to deposit
				float depositAmount;
				if (deltaH > 0) //flowing uphill
					depositAmount = std::min(deltaH, droplet.sediment);
				else
					depositAmount = (droplet.sediment - sedimentCapacity) * depositSpeed;

				deposit(oldDroplet, terrain, depositAmount);
				droplet.sediment -= depositAmount;
			}

			//else erode fraction of droplet's remaining capacity from the soil distributed over the radius of droplet
			//don't erode more than deltaH
			else
			{
				float erosionAmount =
					std::min((sedimentCapacity - droplet.sediment) * erosionSpeed, -deltaH);
				erodeSingle(oldDroplet, terrain, erosionAmount);
				droplet.sediment += erosionAmount;
			}

			//update droplet
			droplet.speed = std::sqrt(std::max(0.f, droplet.speed * droplet.speed + deltaH * gravity));
			droplet.water *= 1 - evaporateSpeed;
		}
	}
}

float HydraulicErosion::getDropletHeight(const Droplet &droplet, Terrain &terrain)
{
	unsigned dropletIntX = static_cast<unsigned>(droplet.position.x);
	unsigned dropletIntY = static_cast<unsigned>(droplet.position.y);
	float hUL = terrain.at(dropletIntX, dropletIntY).getPosition().y;
	float hUR = terrain.at(dropletIntX + 1, dropletIntY).getPosition().y;
	float hLL = terrain.at(dropletIntX, dropletIntY + 1).getPosition().y;
	float hLR = terrain.at(dropletIntX + 1, dropletIntY + 1).getPosition().y;

	float ulWeight = (1 - droplet.offsets.x) * (1 - droplet.offsets.y);
	float urWeight = droplet.offsets.x * (1 - droplet.offsets.y);
	float llWeight = (1 - droplet.offsets.x) * droplet.offsets.y;
	float lrWeight = droplet.offsets.x * droplet.offsets.y;
	return hUL * ulWeight + hUR * urWeight + hLL * llWeight + hLR * lrWeight;
}

glm::vec2 HydraulicErosion::getDropletDirection(const Droplet &droplet, Terrain &terrain)
{
	unsigned dropletIntX = static_cast<unsigned>(droplet.position.x);
	unsigned dropletIntY = static_cast<unsigned>(droplet.position.y);
	float hUL = terrain.at(dropletIntX, dropletIntY).getPosition().y;
	float hUR = terrain.at(dropletIntX + 1, dropletIntY).getPosition().y;
	float hLL = terrain.at(dropletIntX, dropletIntY + 1).getPosition().y;
	float hLR = terrain.at(dropletIntX + 1, dropletIntY + 1).getPosition().y;
	float x = (hUR - hUL) * (1 - droplet.offsets.y) + (hLR - hLL) + droplet.offsets.y;
	float y = (hLL - hUL) * (1 - droplet.offsets.x) + (hLR - hUR) + droplet.offsets.x;
	return glm::vec2(x, y);
}

void HydraulicErosion::deposit(const Droplet &droplet, Terrain &terrain, float amount)
{
	unsigned dropletIntX = static_cast<unsigned>(droplet.position.x);
	unsigned dropletIntY = static_cast<unsigned>(droplet.position.y);

	float ulWeight = (1 - droplet.offsets.x) * (1 - droplet.offsets.y);
	float urWeight = droplet.offsets.x * (1 - droplet.offsets.y);
	float llWeight = (1 - droplet.offsets.x) * droplet.offsets.y;
	float lrWeight = droplet.offsets.x * droplet.offsets.y;

	addAt(terrain, dropletIntX, dropletIntY, amount * ulWeight);
	addAt(terrain, dropletIntX + 1, dropletIntY, amount * urWeight);
	addAt(terrain, dropletIntX, dropletIntY + 1, amount * llWeight);
	addAt(terrain, dropletIntX + 1, dropletIntY + 1, amount * lrWeight);
}

void HydraulicErosion::erodeSingle(const Droplet &droplet, Terrain &terrain, float amount)
{
	unsigned dropletIntX = static_cast<unsigned>(droplet.position.x);
	unsigned dropletIntY = static_cast<unsigned>(droplet.position.y);

	float ulWeight = (1 - droplet.offsets.x) * (1 - droplet.offsets.y);
	float urWeight = droplet.offsets.x * (1 - droplet.offsets.y);
	float llWeight = (1 - droplet.offsets.x) * droplet.offsets.y;
	float lrWeight = droplet.offsets.x * droplet.offsets.y;

	subtractAt(terrain, dropletIntX, dropletIntY, amount * ulWeight);
	subtractAt(terrain, dropletIntX + 1, dropletIntY, amount * urWeight);
	subtractAt(terrain, dropletIntX, dropletIntY + 1, amount * llWeight);
	subtractAt(terrain, dropletIntX + 1, dropletIntY + 1, amount * lrWeight);
}

Droplet::Droplet(const glm::vec2 &position, float speed, float water)
: position(position), speed(speed), water(water), direction(glm::vec2(0, 0)), sediment(0)
{
	updateOffsets();
}

void Droplet::updateOffsets()
{
	unsigned dropletIntX = static_cast<unsigned>(position.x);
	unsigned dropletIntY = static_cast<unsigned>(position.y);
	offsets = glm::vec2(position.x - dropletIntX, position.y - dropletIntY);
}
