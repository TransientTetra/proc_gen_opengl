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
//	updateNormals();
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
//	for(unsigned int i = 0; i < vertices.size(); i++)
//	{
//		Vertex* v;
//		Vertex* v_left;
//		Vertex* v_right;
//		Vertex* v_up;
//		Vertex* v_down;
//		Vertex* v_up_right;
//		Vertex* v_down_left;
//		v = &(vertices.at(i));
//
//		if (i > 0)
//		{
//			v_left = &(vertices.at(i - 1));
//		}
//
//		if (i > nPointsWidth - 1)
//		{
//			v_up = &(vertices.at(i - nPointsWidth));
//			v_up_right = &(vertices.at(i - nPointsWidth + 1));
//		}
//		else if (i > nPointsWidth - 2)
//		{
//			v_up_right = &(vertices.at(i - nPointsWidth + 1));
//		}
//
//		if (i < vertices.size() - 1)
//		{
//			v_right = &(vertices.at(i + 1));
//		}
//
//		if (i < vertices.size() - nPointsWidth)
//		{
//			v_down = &(vertices.at(i + nPointsWidth));
//			v_down_left = &(vertices.at(i + nPointsWidth - 1));
//		}
//		else if (i < vertices.size() - nPointsWidth + 1)
//		{
//			v_down_left = &(vertices.at(i + nPointsWidth - 1));
//		}
//
//		// t1 = v + v_left + v_up
//		// t2 = v + v_up + v_up_right
//		// t3 = v + v_up_right + v_right
//		// t4 = v + v_right + v_down
//		// t5 = v + v_down + v_down_left
//		// t6 = v + v_down_left + v_left
//
//		// todo calculate normal vectors only for existing triangles
//		glm::vec3 t1_norm = calcTriangleNormal(v->getPosition(), v_left->getPosition(), v_up->getPosition());
//		glm::vec3 t2_norm = calcTriangleNormal(v->getPosition(), v_up->getPosition(), v_up_right->getPosition());
//		glm::vec3 t3_norm = calcTriangleNormal(v->getPosition(), v_up_right->getPosition(), v_right->getPosition());
//		glm::vec3 t4_norm = calcTriangleNormal(v->getPosition(), v_right->getPosition(), v_down->getPosition());
//		glm::vec3 t5_norm = calcTriangleNormal(v->getPosition(), v_left->getPosition(), v_down_left->getPosition());
//		glm::vec3 t6_norm = calcTriangleNormal(v->getPosition(), v_down_left->getPosition(), v_left->getPosition());
//
//		glm::vec3 norm = -glm::normalize(t1_norm + t2_norm + t3_norm + t4_norm + t5_norm + t6_norm);
//
//		vertices.at(i).setNormal(norm);
//	}
}

glm::vec3 Terrain::calcTriangleNormal(const glm::vec3 &v1, const glm::vec3 &v2, const glm::vec3 &v3)
{
	return glm::normalize(glm::cross(v2 - v1, v3 - v1));
}
