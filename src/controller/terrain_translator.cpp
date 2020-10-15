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
