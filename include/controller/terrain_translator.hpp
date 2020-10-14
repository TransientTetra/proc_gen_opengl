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
public:
	TerrainTranslator(Terrain *terrain);

	std::unique_ptr<Mesh> getMesh();
};


#endif //PROC_GEN_OPENGL_TERRAIN_TRANSLATOR_HPP
