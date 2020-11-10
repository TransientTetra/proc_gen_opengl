#include "view/opengl_interfacing/vertex.hpp"

Vertex::Vertex(glm::vec3 position, glm::vec3 normal, glm::vec3 color)
: position(position), normal(normal), color(color)
{

}

const glm::vec3 &Vertex::getPosition() const
{
	return position;
}

void Vertex::setPosition(const glm::vec3 &position)
{
	Vertex::position = position;
}

const glm::vec3 &Vertex::getNormal() const
{
	return normal;
}

void Vertex::setNormal(const glm::vec3 &normal)
{
	Vertex::normal = normal;
}

const glm::vec3 &Vertex::getColor() const
{
	return color;
}

void Vertex::setColor(const glm::vec3 &color)
{
	Vertex::color = color;
}
