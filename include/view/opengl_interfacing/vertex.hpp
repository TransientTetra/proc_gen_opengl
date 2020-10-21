#ifndef PROC_GEN_OPENGL_VERTEX_HPP
#define PROC_GEN_OPENGL_VERTEX_HPP


#include <glm/glm.hpp>

class Vertex
{
private:
	glm::vec3 position;
	glm::vec3 normal;
public:
	Vertex(glm::vec3 position, glm::vec3 normal);
	Vertex(glm::vec3 position);

	glm::vec3 getPosition();

	void setNormal(glm::vec3 normal);
};


#endif //PROC_GEN_OPENGL_VERTEX_HPP
