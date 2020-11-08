#ifndef PROC_GEN_OPENGL_TERRAIN_GENERATOR_HPP
#define PROC_GEN_OPENGL_TERRAIN_GENERATOR_HPP


#include <generation_algorithm.hpp>

class TerrainGenerator
{
protected:
	GenerationAlgorithm algo;
public:
	TerrainGenerator();

	TerrainGenerator(GenerationAlgorithm algo);

	virtual ~TerrainGenerator();
};


#endif //PROC_GEN_OPENGL_TERRAIN_GENERATOR_HPP
