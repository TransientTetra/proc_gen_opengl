#include "view/opengl_interfacing/light_source.hpp"

LightSource::LightSource(glm::vec3 position, glm::vec3 color)
{
	this->position = position;
	this->color = color;
}

LightSource::~LightSource()
{

}

const glm::vec3& LightSource::getPosition() const
{
	return position;
}

const glm::vec3& LightSource::getColor() const
{
	return color;
}