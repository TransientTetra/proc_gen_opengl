#include "model/chunk_manager.hpp"

ChunkManager::ChunkManager(GenerationAlgorithm algo, float edgeDistanceTrigger, unsigned int nChunksRadius,
			   float chunkSize, const std::vector<unsigned int> &chunksResolutions)
: algo(algo), edgeDistanceTrigger(edgeDistanceTrigger), nChunksRadius(nChunksRadius), chunkSize(chunkSize),
	chunksResolutions(chunksResolutions)
{
	chunks.emplace_back(10, 10, 1, 0);
}

ChunkManager::~ChunkManager()
{

}

void ChunkManager::update(float trackerX, float trackerY)
{

}

const std::vector<Terrain> &ChunkManager::getChunks() const
{
	return chunks;
}
