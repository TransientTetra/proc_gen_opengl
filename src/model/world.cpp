#include "model/world.hpp"

void World::addEntity(std::shared_ptr<Entity> entity)
{
	entities.push_back(entity);
}
