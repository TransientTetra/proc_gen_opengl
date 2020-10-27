#ifndef PROC_GEN_OPENGL_TERRAIN_TRANSLATOR_HPP
#define PROC_GEN_OPENGL_TERRAIN_TRANSLATOR_HPP


#include <vector>
#include <view/opengl_interfacing/vertex.hpp>
#include <model/terrain.hpp>
#include <view/opengl_interfacing/mesh.hpp>
#include "controller/terrain_colorer.hpp"

class TerrainTranslator
{
private:
	Terrain* terrain;
	TerrainColorer colorer;
	std::vector<Vertex> getVertices();
	std::vector<unsigned int> getIndices();
	void updateVertices(std::vector<Vertex> &vertices);
	void updateIndices(std::vector<unsigned int> &indices);
	glm::vec3 calcTriangleNormal(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3);

public:
	explicit TerrainTranslator(Terrain *terrain);

	void updateMesh(Mesh *mesh);
};


#endif //PROC_GEN_OPENGL_TERRAIN_TRANSLATOR_HPP
