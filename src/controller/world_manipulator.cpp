#include <model/noise_map.hpp>
#include <model/perlin_noise.hpp>
#include <model/white_noise.hpp>
#include <model/sinusoidal_map.hpp>
#include <model/diamond_square_map.hpp>
#include <model/voronoi_map.hpp>
#include <model/hydraulic_erosion.hpp>
#include <model/entity_mesh_generator.hpp>
#include <model/height_map_file_operator.hpp>
#include <model/terrain_to_height_map_converter.hpp>
#include "controller/world_manipulator.hpp"

WorldManipulator::WorldManipulator(World *world)
: world(world)
{}

WorldManipulator::~WorldManipulator()
{

}

void WorldManipulator::setTerrainAlgorithm(GenerationAlgorithm algorithm, HeightMapOperation operation,
					   const std::string& seed, int nVerticesSide, float horizontalScale,
					   unsigned int nOctaves, float persistence, float lacunarity,
					   unsigned int nWavesWidth, unsigned int nWavesLength,
					   unsigned int nPartitions, float levelDiff)
{
	unsigned int seedI = 0;
	for (auto&& c : seed)
		seedI += c;
	std::unique_ptr<HeightMap> heightMap;
	std::unique_ptr<Noise> noise;
	bool heightMapInitialized = false;
	if (algorithm & FLAT)
	{
		heightMapInitialized = true;
		heightMap = std::make_unique<HeightMap>(nVerticesSide, nVerticesSide);
	}
	if (algorithm & PERLIN_NOISE)
	{
		noise = std::make_unique<PerlinNoise>(seedI);
		if (not heightMapInitialized)
		{
			heightMapInitialized = true;
			heightMap = std::make_unique<NoiseMap>(nVerticesSide, nVerticesSide, std::move(noise),
							       horizontalScale, nOctaves, persistence, lacunarity);
		}
		else
		{
			NoiseMap temp(nVerticesSide, nVerticesSide, std::move(noise),
				      horizontalScale, nOctaves, persistence, lacunarity);
			if (operation == ADDITION)
				heightMap->add(temp);
			if (operation == MULTIPLICATION)
				heightMap->multiply(temp);
		}
	}
	if (algorithm & WHITE_NOISE)
	{
		noise = std::make_unique<WhiteNoise>(seedI);
		if (not heightMapInitialized)
		{
			heightMapInitialized = true;
			heightMap = std::make_unique<NoiseMap>(nVerticesSide, nVerticesSide, std::move(noise),
							       horizontalScale, nOctaves, persistence, lacunarity);
		}
		else
		{
			NoiseMap temp(nVerticesSide, nVerticesSide, std::move(noise),
				      horizontalScale, nOctaves, persistence, lacunarity);
			if (operation == ADDITION)
				heightMap->add(temp);
			if (operation == MULTIPLICATION)
				heightMap->multiply(temp);
		}
	}
	if (algorithm & SINUSOIDAL)
	{
		if (not heightMapInitialized)
		{
			heightMapInitialized = true;
			heightMap = std::make_unique<SinusoidalMap>(nVerticesSide, nVerticesSide,
								    nWavesWidth, nWavesLength);
		}
		else
		{
			SinusoidalMap temp(nVerticesSide, nVerticesSide,
					   nWavesWidth, nWavesLength);
			if (operation == ADDITION)
				heightMap->add(temp);
			if (operation == MULTIPLICATION)
				heightMap->multiply(temp);
		}
	}
	if (algorithm & DIAMOND_SQUARE)
	{
		if (not heightMapInitialized)
		{
			heightMapInitialized = true;
			heightMap = std::make_unique<DiamondSquareMap>(nVerticesSide, nVerticesSide, seedI,
								       persistence);
		}
		else
		{
			DiamondSquareMap temp(nVerticesSide, nVerticesSide, seedI,
					 persistence);
			if (operation == ADDITION)
				heightMap->add(temp);
			if (operation == MULTIPLICATION)
				heightMap->multiply(temp);
		}
	}
	if (algorithm & VORONOI)
	{
		if (not heightMapInitialized)
		{
			heightMapInitialized = true;
			heightMap = std::make_unique<VoronoiMap>(nVerticesSide, nVerticesSide, seedI, nPartitions,
								 levelDiff);
		}
		else
		{
			VoronoiMap temp(nVerticesSide, nVerticesSide, seedI, nPartitions,
					levelDiff);
			if (operation == ADDITION)
				heightMap->add(temp);
			if (operation == MULTIPLICATION)
				heightMap->multiply(temp);
		}
	}
	if (not heightMapInitialized)
		heightMap = std::make_unique<HeightMap>(nVerticesSide, nVerticesSide);

	if (algorithm & DIAMOND_SQUARE) heightMap->normalize(-1, 1);
	world->getTerrain().setHeightMap(std::move(heightMap));
}

void WorldManipulator::setTerrainWidth(float width)
{
	world->getTerrain().setWidth(width);
}

void WorldManipulator::setTerrainLength(float length)
{
	world->getTerrain().setLength(length);
}

void WorldManipulator::setTerrainScale(float scale)
{
	world->getTerrain().setScale(scale);
}

void WorldManipulator::erodeTerrainHydraulic(const std::string& seed, unsigned int nDroplets, float dropletInertia,
					float evaporateSpeed, float depositSpeed, float erosionSpeed,
					unsigned int dropletRadius)
{
	unsigned int seedI = 0;
	for (auto&& c : seed)
		seedI += c;
	HydraulicErosion erosion(seedI, nDroplets, dropletInertia, evaporateSpeed, depositSpeed, erosionSpeed, dropletRadius);
	erosion.erode(world->getTerrain());
	world->getTerrain().updateNormals();
	EntityMeshGenerator meshGenerator(&(world->getTerrain()));
	world->getTerrain().setMesh(meshGenerator.createMesh());
}

void WorldManipulator::saveTerrain(const std::string& filename)
{
	HeightMapFileOperator o;
	TerrainToHeightMapConverter c;
	HeightMap h(c.convert(world->getTerrain()));
	o.saveHeightMap(filename, h);
}

void WorldManipulator::loadTerrain(const std::string& filename)
{
	HeightMapFileOperator o;
	HeightMap loadedHeightMap = o.loadHeightMap(filename);
	std::unique_ptr<HeightMap> m = std::make_unique<HeightMap>(loadedHeightMap);
	world->getTerrain().setHeightMap(std::move(m));
}
