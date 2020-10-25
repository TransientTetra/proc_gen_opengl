#include "controller/terrain_translator.hpp"

TerrainTranslator::TerrainTranslator(Terrain *terrain)
: terrain(terrain)
{
}

void TerrainTranslator::updateMesh(Mesh *mesh)
{
	updateVertices(mesh->getVertices());
	updateIndices(mesh->getIndices());
	mesh->update();
}

void TerrainTranslator::updateVertices(std::vector<Vertex> &vertices)
{
	vertices.clear();
	for(int i = 0; i < terrain->getPoints().size(); i++)
	{
		glm::vec3 v;
		glm::vec3 v_left;
		glm::vec3 v_right;
		glm::vec3 v_up;
		glm::vec3 v_down;
		glm::vec3 v_up_right;
		glm::vec3 v_down_left;

		v = terrain->getPoints().at(i);

		if(i > 0)
		{
			v_left = terrain->getPoints().at(i - 1);
		}

		if(i > terrain->getNPointsWidth() - 1)
		{
			v_up = terrain->getPoints().at(i - terrain->getNPointsWidth());
			v_up_right = terrain->getPoints().at(i - terrain->getNPointsWidth() + 1);
		}
		else if(i > terrain->getNPointsWidth() - 2)
		{
			v_up_right = terrain->getPoints().at(i - terrain->getNPointsWidth() + 1);
		}

		if(i < terrain->getPoints().size() - 1)
		{
			v_right = terrain->getPoints().at(i + 1);
		}

		if(i < terrain->getPoints().size() - terrain->getNPointsWidth())
		{
			v_down = terrain->getPoints().at(i + terrain->getNPointsWidth());
			v_down_left = terrain->getPoints().at(i + terrain->getNPointsWidth() - 1);
		}
		else if(i < terrain->getPoints().size() - terrain->getNPointsWidth() + 1)
		{
			v_down_left = terrain->getPoints().at(i + terrain->getNPointsWidth() - 1);
		}

		// t1 = v + v_left + v_up
		// t2 = v + v_up + v_up_right
		// t3 = v + v_up_right + v_right
		// t4 = v + v_right + v_down
		// t5 = v + v_down + v_down_left
		// t6 = v + v_down_left + v_left

		// todo calculate normal vectors only for existing triangles
		glm::vec3 t1_norm = calcTriangleNormal(v, v_left, v_up);
		glm::vec3 t2_norm = calcTriangleNormal(v, v_up, v_up_right);
		glm::vec3 t3_norm = calcTriangleNormal(v, v_up_right, v_right);
		glm::vec3 t4_norm = calcTriangleNormal(v, v_right, v_down);
		glm::vec3 t5_norm = calcTriangleNormal(v, v_left, v_down_left);
		glm::vec3 t6_norm = calcTriangleNormal(v, v_down_left, v_left);

		glm::vec3 norm = -glm::normalize(t1_norm + t2_norm + t3_norm + t4_norm + t5_norm + t6_norm);

		float diff = (v.y - minHeight) / (maxHeight - minHeight);
		diff = diff < .0f ? .0f : diff > 1.0f ? 1.0f : diff;

		glm::vec3 col = glm::vec3(
			highColor.r > lowColor.r ? (highColor.r - lowColor.r) * diff + lowColor.r : lowColor.r - (lowColor.r - highColor.r) * diff,
			highColor.g > lowColor.g ? (highColor.g - lowColor.g) * diff + lowColor.g : lowColor.g - (lowColor.g - highColor.g) * diff,
			highColor.b > lowColor.b ? (highColor.b - lowColor.b) * diff + lowColor.b : lowColor.b - (lowColor.b - highColor.b) * diff
			);


		vertices.emplace_back(Vertex(v, norm, col));
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