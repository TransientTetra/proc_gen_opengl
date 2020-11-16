#include "model/hydraulic_erosion.hpp"

HydraulicErosion::HydraulicErosion(unsigned int seed, unsigned int nDroplets, unsigned int dropletLifetime)
: seed(seed), nDroplets(nDroplets), generator(seed), dropletLifetime(dropletLifetime)
{}

void HydraulicErosion::erode(Terrain &terrain)
{
	unsigned int mapWidth = terrain.getNPointsWidth();
	unsigned int mapHeight = terrain.getNPointsLength();
	std::uniform_int_distribution<int> distributionW(0, mapWidth - 1);
	std::uniform_int_distribution<int> distributionH(0, mapHeight - 1);
	for (unsigned i = 0; i < 70000; ++i)
	{
		//rain droplet at random point on map
		unsigned x = distributionW(generator);
		unsigned y = distributionH(generator);
		for(unsigned lifetime = 0; lifetime < dropletLifetime; ++lifetime)
		{
			//calculate droplet height and direction of flow
			Vertex& currVertex = terrain.at(x, y);
			glm::vec3 currPos = currVertex.getPosition();
			currVertex.setPosition(glm::vec3(currPos.x, -2, currPos.z));

			//update droplet position (1 unit regardless of speed so as not to skip over sections of map)

			//find new height and get deltaH

			//calculate droplet sediment capacity (higher when moving fast down a slope and contains a lots of water)

			//if carrying more sediment than capacity or flowing up a slope
			//deposit fraction of sediment to surrounding nodes

			//else erode fraction of droplet's remaining capacity from the soil distributed over the radius of droplet
			//don't erode more than deltaH

			//update droplet's speed
		}
	}
}
