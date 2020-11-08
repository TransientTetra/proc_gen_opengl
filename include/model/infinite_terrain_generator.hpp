#ifndef PROC_GEN_OPENGL_INFINITE_TERRAIN_GENERATOR_HPP
#define PROC_GEN_OPENGL_INFINITE_TERRAIN_GENERATOR_HPP


#include <vector>
#include "terrain_generator.hpp"

class InfiniteTerrainGenerator : public TerrainGenerator
{
private:
	float edgeDistanceTrigger;
	unsigned int nChunks; // number of chunks; >= 0
	std::vector<unsigned int> chunksResolutions;
public:
};


#endif //PROC_GEN_OPENGL_INFINITE_TERRAIN_GENERATOR_HPP
