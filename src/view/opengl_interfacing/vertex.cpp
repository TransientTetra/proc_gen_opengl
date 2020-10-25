#include "view/opengl_interfacing/vertex.hpp"

Vertex::Vertex(glm::vec3 position)
: position(position)
{

}

//Vertex::Vertex(glm::vec3 position, glm::vec3 normal)
//: position(position), normal(normal)
//{
//
//}

Vertex::Vertex(glm::vec3 position, glm::vec3 normal, glm::vec3 color)
: position(position), normal(normal), color(color)
{

}

glm::vec3 Vertex::getPosition()
{
	return position;
}


void Vertex::setNormal(glm::vec3 normal)
{
	this->normal = normal;
}