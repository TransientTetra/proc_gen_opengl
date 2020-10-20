#include "controller/terrain_translator.hpp"

TerrainTranslator::TerrainTranslator(Terrain *terrain)
: terrain(terrain)
{}

void TerrainTranslator::updateMesh(Mesh *mesh)
{
	updateVertices(mesh->getVertices());
	updateIndices(mesh->getIndices());
	mesh->update();
}

void TerrainTranslator::updateVertices(std::vector<Vertex> &vertices)
{
	vertices.clear();
	for (auto&& point : terrain->getPoints())
	{
		vertices.emplace_back(Vertex(point));
	}

	for(int i = terrain->getNPointsWidth(); i < vertices.size() - terrain->getNPointsWidth(); i++)
	{
		glm::vec3 v = vertices.at(i).getPosition();
		glm::vec3 v_left = vertices.at(i - 1).getPosition();
		glm::vec3 v_right = vertices.at(i + 1).getPosition();
		glm::vec3 v_up = vertices.at(i - terrain->getNPointsWidth()).getPosition();
		glm::vec3 v_down = vertices.at(i + terrain->getNPointsWidth()).getPosition();
		glm::vec3 v_up_right = vertices.at(i - terrain->getNPointsWidth() + 1).getPosition();
		glm::vec3 v_down_left = vertices.at(i + terrain->getNPointsWidth() - 1).getPosition();

		// t1 = v + v_left + v_up
		// t2 = v + v_up + v_up_right
		// t3 = v + v_up_right + v_right
		// t4 = v + v_right + v_down
		// t5 = v + v_down + v_down_left
		// t6 = v + v_down_left + v_left

		glm::vec3 t1_norm = calcTriangleNormal(v, v_left, v_up);
		glm::vec3 t2_norm = calcTriangleNormal(v, v_up, v_up_right);
		glm::vec3 t3_norm = calcTriangleNormal(v, v_up_right, v_right);
		glm::vec3 t4_norm = calcTriangleNormal(v, v_right, v_down);
		glm::vec3 t5_norm = calcTriangleNormal(v, v_left, v_down_left);
		glm::vec3 t6_norm = calcTriangleNormal(v, v_down_left, v_left);

		glm::vec3 norm = glm::normalize(t1_norm + t2_norm + t3_norm + t4_norm + t5_norm + t6_norm);

		vertices.at(i).setNormal(norm);
	}
}

void TerrainTranslator::updateIndices(std::vector<unsigned int> &indices)
{
	indices.clear();
	unsigned int currIndex = 0;
	unsigned int nPointsWidth = terrain->getNPointsWidth();
	for (int i = 0; i < terrain->getNPointsLength() - 1; ++i)
	{
		for (int j = 0; j < nPointsWidth - 1; ++j)
		{
			indices.emplace_back(currIndex + nPointsWidth);
			indices.emplace_back(currIndex + 1);
			indices.emplace_back(currIndex);

			indices.emplace_back(currIndex + 1);
			indices.emplace_back(currIndex + nPointsWidth);
			indices.emplace_back(currIndex + nPointsWidth + 1);
			currIndex += 1;
		}
		currIndex += 1;
	}
}

glm::vec3 TerrainTranslator::calcTriangleNormal(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3)
{
	glm::vec3 edge1 = v2 - v1;
	glm::vec3 edge2 = v3 - v1;

	return glm::normalize(glm::cross(edge1, edge2));
}