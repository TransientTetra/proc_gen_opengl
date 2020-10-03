#ifndef PROC_GEN_OPENGL_ENTITY_HPP
#define PROC_GEN_OPENGL_ENTITY_HPP


#include <vector>
#include <glm/glm.hpp>

class Entity
{
protected:
	glm::vec3 position;
	std::vector<glm::vec3> vertices;
	std::vector<unsigned int> indices;
public:
	Entity();
	Entity(glm::vec3 position);

	const glm::vec3 &getPosition() const;

	void setPosition(const glm::vec3 &position);

	const std::vector<glm::vec3> &getVertices() const;

	const std::vector<unsigned int> &getIndices() const;
};


#endif //PROC_GEN_OPENGL_ENTITY_HPP
