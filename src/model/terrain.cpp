#include <model/entity_mesh_generator.hpp>
#include <model/terrain_colorer.hpp>
#include "model/terrain.hpp"

Terrain::Terrain(float width, float length, float scale)
: width(width), length(length), scale(scale), heightMap(std::make_unique<HeightMap>(2, 2))
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
	indices.clear();
	unsigned int currIndex = 0;
	unsigned int nPointsWidth = getNPointsWidth();
	unsigned int nPointsLength = getNPointsLength();
	TerrainColorer colorer;

	//todo make this multithreaded
	for (unsigned int i = 0; i < nPointsLength; ++i)
	{
		for (unsigned int j = 0; j < nPointsWidth; ++j)
		{
			float x = (j * width / (nPointsWidth - 1) - width / 2) + position.x;
			float y = scale * heightMap->at(i, j) + position.y;
			float z = (i * length / (nPointsLength - 1) - length / 2) + position.z;
			glm::vec3 pos(x, y, z);
			vertices.emplace_back(pos, glm::vec3(0, 0, 0), colorer.getPointColor(pos));
			if (i < nPointsLength - 1 and j < nPointsWidth - 1)
			{
				indices.emplace_back(currIndex + nPointsWidth);
				indices.emplace_back(currIndex + 1);
				indices.emplace_back(currIndex);

				indices.emplace_back(currIndex + 1);
				indices.emplace_back(currIndex + nPointsWidth);
				indices.emplace_back(currIndex + nPointsWidth + 1);
				currIndex += 1;
			}
		}
		if (i < nPointsLength - 1)
			currIndex += 1;
	}
	updateNormals();
	EntityMeshGenerator emg(this);
	mesh = emg.createMesh();
}

float Terrain::getLength() const
{
	return length;
}

float Terrain::getWidth() const
{
	return width;
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

void Terrain::setScale(float scale)
{
	Terrain::scale = scale;
	calculatePoints();
}

void Terrain::updateNormals()
{
	//todo make this multithreaded
	unsigned int nPointsWidth = getNPointsWidth();
	unsigned int nPointsLength = getNPointsLength();
	//calculating normal for each triangle and then adding them to vertex normals
	for (unsigned int i = 0; i < indices.size(); i += 3)
	{
		Vertex* v1 = &(vertices.at(indices.at(i)));
		Vertex* v2 = &(vertices.at(indices.at(i + 1)));
		Vertex* v3 = &(vertices.at(indices.at(i + 2)));
		glm::vec3 faceNormal = calcTriangleNormal(v1->getPosition(), v2->getPosition(), v3->getPosition());
		v1->setNormal(v1->getNormal() + faceNormal);
		v2->setNormal(v2->getNormal() + faceNormal);
		v3->setNormal(v3->getNormal() + faceNormal);
	}
	//normalizing the normals
	for (auto&& vertex : vertices)
		vertex.setNormal(glm::normalize(vertex.getNormal()));
}

glm::vec3 Terrain::calcTriangleNormal(const glm::vec3 &v1, const glm::vec3 &v2, const glm::vec3 &v3)
{
	return glm::normalize(glm::cross(v2 - v1, v3 - v1));
}
