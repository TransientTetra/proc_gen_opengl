#include "controller/terrain_translator.hpp"

std::vector<Vertex> TerrainTranslator::getVertices(const Terrain &terrain)
{
	std::vector<Vertex> ret;
	for (auto point : terrain.getPoints())
	{
		ret.emplace_back(Vertex(point));
	}
	return ret;
}

std::vector<unsigned int> TerrainTranslator::getIndices(const Terrain &terrain)
{
	unsigned int currIndex = 0;
	std::vector<unsigned int> ret;
	unsigned int nPointsWidth = terrain.getNPointsWidth();
	for (int i = 0; i < terrain.getNPointsLength() - 1; ++i)
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
