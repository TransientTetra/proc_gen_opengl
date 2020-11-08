#ifndef PROC_GEN_OPENGL_CHUNK_MANAGER_HPP
#define PROC_GEN_OPENGL_CHUNK_MANAGER_HPP


#include <vector>
#include <generation_algorithm.hpp>
#include "terrain.hpp"

class ChunkManager
{
private:
	GenerationAlgorithm algo;
	float edgeDistanceTrigger; //how far from chunk side does new generation trigger
	unsigned int nChunksRadius; //number of chunks in radius; >= 1
	float chunkSize; //size of chunk side
	std::vector<unsigned int> chunksResolutions;
	std::vector<Terrain> chunks;
public:
	ChunkManager(GenerationAlgorithm algo, float edgeDistanceTrigger, unsigned int nChunksRadius,
		     float chunkSize, const std::vector<unsigned int> &chunksResolutions);

	virtual ~ChunkManager();

	void update(float trackerX, float trackerY);

	const std::vector<Terrain> &getChunks() const;
};


#endif //PROC_GEN_OPENGL_CHUNK_MANAGER_HPP
