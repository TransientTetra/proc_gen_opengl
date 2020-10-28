#include "model/voronoi_map.hpp"

VoronoiMap::VoronoiMap(unsigned int width, unsigned int length, unsigned int seed, unsigned int nRandomPoints,
		       float levelDiff, float gapWidth, float gapHeight)
: HeightMap(width, length), generator(seed), heightDistribution(-1, 1), widthDistribution(0, width - 1),
	lengthDistribution(0, length - 1)
{
}
