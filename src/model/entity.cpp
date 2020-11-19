#include "model/entity.hpp"

Entity::Entity()
: position(glm::vec3(0, 0, 0))
{
}

Entity::Entity(glm::vec3 position)
: position(position)
{
}

const glm::vec3 &Entity::getPosition() const
{
	return position;
}

void Entity::setPosition(const glm::vec3 &position)
{
	Entity::position = position;
}

const std::vector<Vertex> &Entity::getVertices() const
{
	return vertices;
}

const std::shared_ptr<Mesh> &Entity::getMesh() const
{
	return mesh;
}

const std::vector<unsigned int> &Entity::getIndices() const
{
	return indices;
}

void Entity::setMesh(const std::shared_ptr<Mesh> &mesh)
{
	Entity::mesh = mesh;
}
