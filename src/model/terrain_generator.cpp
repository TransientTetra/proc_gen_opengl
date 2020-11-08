#include "model/terrain_generator.hpp"

TerrainGenerator::TerrainGenerator(GenerationAlgorithm algo)
: algo(algo)
{}

TerrainGenerator::TerrainGenerator()
: algo(FLAT)
{}

TerrainGenerator::~TerrainGenerator()
{

}
