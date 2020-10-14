#include "controller/terrain_translator.hpp"

TerrainTranslator::TerrainTranslator(Terrain *terrain)
: terrain(terrain)
{}

std::vector<Vertex> TerrainTranslator::getVertices()
{
	std::vector<Vertex> ret;
	for (auto point : terrain->getPoints())
	{
		ret.emplace_back(Vertex(point));
	}
	return ret;
}

std::vector<unsigned int> TerrainTranslator::getIndices()
{
	unsigned int currIndex = 0;
	std::vector<unsigned int> ret;
	unsigned int nPointsWidth = terrain->getNPointsWidth();
	for (int i = 0; i < terrain->getNPointsLength() - 1; ++i)
	{
		for (int j = 0; j < nPointsWidth - 1; ++j)
		{
			ret.emplace_back(currIndex + nPointsWidth);
			ret.emplace_back(currIndex + 1);
			ret.emplace_back(currIndex);

			ret.emplace_back(currIndex + 1);
			ret.emplace_back(currIndex + nPointsWidth);
			ret.emplace_back(currIndex + nPointsWidth + 1);
			currIndex += 1;
		}
		currIndex += 1;
	}
	return ret;
}

std::unique_ptr<Mesh> TerrainTranslator::getMesh()
{
	return std::make_unique<Mesh>(getVertices(), getIndices(), GL_STATIC_DRAW);
}

