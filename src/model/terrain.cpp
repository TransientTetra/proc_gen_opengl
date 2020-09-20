#include <memory>
#include <model/sinusoidal_map.hpp>
#include <model/noise_map.hpp>
#include <model/perlin_noise.hpp>
#include "model/terrain.hpp"

Terrain::Terrain(float width, float length, float scale)
: width(width), length(length), level(0), heightMap(std::make_unique<HeightMap>(2, 2))
{
	heightMap = std::make_unique<NoiseMap>(256, 256, std::make_unique<PerlinNoise>(2020), 50);
	calculatePoints(scale);
}

void Terrain::calculatePoints(float scale)
{
	for (int i = 0; i < getNPointsLength(); ++i)
	{
		for (int j = 0; j < getNPointsWidth(); ++j)
		{
			float x = j * width / (getNPointsWidth() - 1) - width / 2;
			float y = scale * heightMap->at(i, j) + level;
			float z = i * length / (getNPointsLength() - 1) - length / 2;
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

const std::vector<glm::vec3> &Terrain::getPoints() const
{
	return points;
}
