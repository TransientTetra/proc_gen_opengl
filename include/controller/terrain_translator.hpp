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

public:
	explicit TerrainTranslator(Terrain *terrain);

	void updateMesh(Mesh *mesh);
};


#endif //PROC_GEN_OPENGL_TERRAIN_TRANSLATOR_HPP
