#include "model/entity.hpp"

Entity::Entity()
: position(Point(0, 0, 0)), nVertices(0)
{
}

Entity::Entity(Point position)
: position(position), nVertices(0)
{
}

const Point &Entity::getPosition() const
{
	return position;
}

void Entity::setPosition(const Point &position)
{
	Entity::position = position;
}
