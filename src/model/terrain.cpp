#include <memory>
#include <model/sinusoidal_map.hpp>
#include <model/noise_map.hpp>
#include <model/perlin_noise.hpp>
#include "model/terrain.hpp"

Terrain::Terrain(float width, float length, float scale, float level)
: width(width), length(length), yOffset(level), scale(scale), heightMap(std::make_unique<HeightMap>(2, 2)),
	xOffset(0), zOffset(0)
{
	calculatePoints();
}

Terrain::Terrain(float length, float width, float scale, float xOffset, float yOffset, float zOffset)
: width(width), length(length), yOffset(yOffset), scale(scale), heightMap(std::make_unique<HeightMap>(2, 2)),
	xOffset(xOffset), zOffset(zOffset)
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
	points.clear();
	for (int i = 0; i < getNPointsLength(); ++i)
	{
		for (int j = 0; j < getNPointsWidth(); ++j)
		{
			float x = (j * width / (getNPointsWidth() - 1) - width / 2) + xOffset;
			float y = scale * heightMap->at(i, j) + yOffset;
			float z = (i * length / (getNPointsLength() - 1) - length / 2) + zOffset;
			points.emplace_back(glm::vec3(x, y, z));
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
	return yOffset;
}

unsigned int Terrain::getNPointsLength() const
{
	return heightMap->getLength();
}

unsigned int Terrain::getNPointsWidth() const
{
	return heightMap->getWidth();
}

const std::vector<glm::vec3> &Terrain::getPoints() const
{
	return points;
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
	Terrain::yOffset = level;
	calculatePoints();
}

void Terrain::setScale(float scale)
{
	Terrain::scale = scale;
	calculatePoints();
}
