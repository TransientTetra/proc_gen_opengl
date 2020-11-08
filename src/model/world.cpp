#include "model/world.hpp"

World::World()
{
	terrain = std::make_unique<Terrain>(10, 10, 1, 0);
}

void World::addEntity(std::shared_ptr<Entity> entity)
{
	entities.push_back(entity);
}

const std::vector<std::shared_ptr<Entity>> &World::getEntities() const
{
	return entities;
}

void World::setTerrain(std::unique_ptr<Terrain> terrain)
{
	this->terrain = std::move(terrain);
}

std::unique_ptr<Terrain> &World::getTerrain()
{
	return terrain;
}
