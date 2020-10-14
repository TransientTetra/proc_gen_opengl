#include <model/noise_map.hpp>
#include <model/perlin_noise.hpp>
#include <model/white_noise.hpp>
#include <model/sinusoidal_map.hpp>
#include "controller/world_manipulator.hpp"

WorldManipulator::WorldManipulator(World *world)
: world(world)
{}

WorldManipulator::~WorldManipulator()
{

}

void WorldManipulator::setTerrainAlgorithm(GenerationAlgorithm algorithm, std::string seed,
					   int nVerticesSide, float horizontalScale,
					   unsigned int nOctaves, float persistence, float lacunarity,
					   unsigned int nWavesWidth, unsigned int nWavesLength)
{
	unsigned int seedI = 0;
	for (char c : seed)
		seedI += c;
	std::unique_ptr<HeightMap> heightMap;
	std::unique_ptr<Noise> noise;
	switch (algorithm)
	{
		case PERLIN_NOISE:
			noise = std::make_unique<PerlinNoise>(seedI);
			heightMap = std::make_unique<NoiseMap>(nVerticesSide, nVerticesSide, std::move(noise),
					  horizontalScale, nOctaves, persistence, lacunarity);
			break;
		case WHITE_NOISE:
			noise = std::make_unique<WhiteNoise>(seedI);
			heightMap = std::make_unique<NoiseMap>(nVerticesSide, nVerticesSide, std::move(noise),
					  horizontalScale, nOctaves, persistence, lacunarity);
			break;
		case SINUSOIDAL:
			heightMap = std::make_unique<SinusoidalMap>(nVerticesSide, nVerticesSide,
					       nWavesWidth, nWavesLength);
			break;
		case FLAT:
		default:
			heightMap = std::make_unique<HeightMap>(nVerticesSide, nVerticesSide);
			break;
	}
	world->getTerrain()->setHeightMap(std::move(heightMap));
}

void WorldManipulator::setTerrainWidth(float width)
{
	world->getTerrain()->setWidth(width);
}

void WorldManipulator::setTerrainLength(float length)
{
	world->getTerrain()->setLength(length);
}

void WorldManipulator::setTerrainScale(float scale)
{
	world->getTerrain()->setScale(scale);
}
