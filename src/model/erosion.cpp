#include "model/erosion.hpp"

void Erosion::addAt(Terrain &terrain, unsigned int x, unsigned int y, float val)
{
	const glm::vec3& pos = terrain.at(x, y).getPosition();
	glm::vec3 newPos = pos + glm::vec3(0, val, 0);
	terrain.at(x, y).setPosition(newPos);
}

void Erosion::subtractAt(Terrain &terrain, unsigned int x, unsigned int y, float val)
{
	addAt(terrain, x, y, -val);
}
