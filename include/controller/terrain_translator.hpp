#ifndef PROC_GEN_OPENGL_TERRAIN_TRANSLATOR_HPP
#define PROC_GEN_OPENGL_TERRAIN_TRANSLATOR_HPP


#include <vector>
#include <view/opengl_interfacing/vertex.hpp>
#include <model/terrain.hpp>

class TerrainTranslator
{
private:
protected:
public:
	std::vector<Vertex> getVertices(const Terrain &terrain);
	std::vector<unsigned int> getIndices(const Terrain &terrain);
};


#endif //PROC_GEN_OPENGL_TERRAIN_TRANSLATOR_HPP
