#include "model/point.hpp"

Point::Point(float x, float y, float z)
: x(x), y(y), z(z)
{
}

Point::Point(const Point &other)
: x(other.x), y(other.y), z(other.z)
{
}

void Point::operator=(Point const &other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

