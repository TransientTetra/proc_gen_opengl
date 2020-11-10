#ifndef PROC_GEN_OPENGL_VERTEX_HPP
#define PROC_GEN_OPENGL_VERTEX_HPP


#include <glm/glm.hpp>

class Vertex
{
private:
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
public:
	Vertex(glm::vec3 position, glm::vec3 normal, glm::vec3 color);

	const glm::vec3 &getPosition() const;

	void setPosition(const glm::vec3 &position);

	const glm::vec3 &getNormal() const;

	void setNormal(const glm::vec3 &normal);

	const glm::vec3 &getColor() const;

	void setColor(const glm::vec3 &color);
};


#endif //PROC_GEN_OPENGL_VERTEX_HPP
