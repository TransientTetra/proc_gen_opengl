#include "view/opengl_interfacing/light.hpp"

Light::Light()
{

}

Light::Light(glm::vec3 position, glm::vec3 color)
{
	this->position = position;
	this->color = color;
}

Light::~Light()
{

}

glm::vec3 Light::getPosition()
{
	return position;
}

glm::vec3 Light::getColor()
{
	return color;
}