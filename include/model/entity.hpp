#ifndef PROC_GEN_OPENGL_ENTITY_HPP
#define PROC_GEN_OPENGL_ENTITY_HPP


#include <vector>
#include <glm/glm.hpp>
#include <view/opengl_interfacing/vertex.hpp>
#include <view/opengl_interfacing/mesh.hpp>

class Entity
{
protected:
	glm::vec3 position;
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::shared_ptr<Mesh> mesh;
public:
	Entity();
	Entity(glm::vec3 position);

	const glm::vec3 &getPosition() const;
	void setPosition(const glm::vec3 &position);

	const std::vector<Vertex> &getVertices() const;

	const std::vector<unsigned int> &getIndices() const;

	const std::shared_ptr<Mesh> &getMesh() const;
};


#endif //PROC_GEN_OPENGL_ENTITY_HPP
