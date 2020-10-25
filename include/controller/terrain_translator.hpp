#ifndef PROC_GEN_OPENGL_TERRAIN_TRANSLATOR_HPP
#define PROC_GEN_OPENGL_TERRAIN_TRANSLATOR_HPP


#include <vector>
#include <view/opengl_interfacing/vertex.hpp>
#include <model/terrain.hpp>
#include <view/opengl_interfacing/mesh.hpp>

class TerrainTranslator
{
private:
	Terrain* terrain;
	std::vector<Vertex> getVertices();
	std::vector<unsigned int> getIndices();
	void updateVertices(std::vector<Vertex> &vertices);
	void updateIndices(std::vector<unsigned int> &indices);
	glm::vec3 calcTriangleNormal(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3);

	const float maxHeight = 2.0f;
	const float minHeight = -2.0f;
	const glm::vec3 highColor = glm::vec3(1.0f, .0f, .0f);
	const glm::vec3 lowColor = glm::vec3(.0f, 1.0f, .0f);

public:
	explicit TerrainTranslator(Terrain *terrain);

	void updateMesh(Mesh *mesh);
};


#endif //PROC_GEN_OPENGL_TERRAIN_TRANSLATOR_HPP
