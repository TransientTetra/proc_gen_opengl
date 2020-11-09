#include <memory>
#include <model/sinusoidal_map.hpp>
#include <model/noise_map.hpp>
#include <model/perlin_noise.hpp>
#include "model/terrain.hpp"

Terrain::Terrain(float width, float length, float scale, float level)
: width(width), length(length), level(level), scale(scale), heightMap(std::make_unique<HeightMap>(2, 2))
{
	calculatePoints();
}

void Terrain::setHeightMap(std::unique_ptr<HeightMap> heightMap)
{
	Terrain::heightMap = std::move(heightMap);
	calculatePoints();
}

void Terrain::calculatePoints()
{
	vertices.clear();
	for (int i = 0; i < getNPointsLength(); ++i)
	{
		for (int j = 0; j < getNPointsWidth(); ++j)
		{
			float x = (j * width / (getNPointsWidth() - 1) - width / 2) + position.x;
			float y = (scale * heightMap->at(i, j) + level) + position.y;
			float z = (i * length / (getNPointsLength() - 1) - length / 2) + position.z;
			vertices.emplace_back(glm::vec3(x, y, z), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		}
	}
}

float Terrain::getLength() const
{
	return length;
}

float Terrain::getWidth() const
{
	return width;
}

float Terrain::getLevel() const
{
	return level;
}

unsigned int Terrain::getNPointsLength() const
{
	return heightMap->getLength();
}

unsigned int Terrain::getNPointsWidth() const
{
	return heightMap->getWidth();
}

void Terrain::setLength(float length)
{
	Terrain::length = length;
	calculatePoints();
}

void Terrain::setWidth(float width)
{
	Terrain::width = width;
	calculatePoints();
}

void Terrain::setLevel(float level)
{
	Terrain::level = level;
	calculatePoints();
}

void Terrain::setScale(float scale)
{
	Terrain::scale = scale;
	calculatePoints();
}
