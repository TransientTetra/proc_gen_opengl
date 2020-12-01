#include "model/terrain_to_height_map_converter.hpp"

HeightMap TerrainToHeightMapConverter::convert(Terrain& terrain)
{
	unsigned width = terrain.getNPointsWidth();
	unsigned height = terrain.getNPointsLength();
	HeightMap ret(width, height);

	for (unsigned y = 0; y < height; ++y)
	{
		for (unsigned x = 0; x < width; ++x)
		{
			ret.setAt(x, y, terrain.at(x, y).getPosition().y);
		}
	}
	return ret;
}
