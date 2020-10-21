#include "view/opengl_interfacing/lightsource.hpp"

Lightsource::Lightsource(glm::vec3 position, glm::vec3 color)
{
	this->position = position;
	this->color = color;
}

Lightsource::~Lightsource()
{

}

const glm::vec3& Lightsource::getPosition() const
{
	return position;
}

const glm::vec3& Lightsource::getColor() const
{
	return color;
}