#include "model/world.hpp"

void World::addEntity(std::shared_ptr<Entity> entity)
{
	entities.push_back(entity);
}

const std::vector<std::shared_ptr<Entity>> &World::getEntities() const
{
	return entities;
}
