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

const std::vector<glm::vec3> &Entity::getVertices() const
{
	return vertices;
}

const std::vector<unsigned int> &Entity::getIndices() const
{
	return indices;
}
