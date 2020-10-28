#include "model/voronoi_map.hpp"

VoronoiMap::VoronoiMap(unsigned int width, unsigned int length, unsigned int seed, unsigned int nRandomPoints,
		       float levelDiff, float gapWidth, float gapHeight)
: HeightMap(width, length), generator(seed), heightDistribution(-1, 1), widthDistribution(0, width - 1),
	lengthDistribution(0, length - 1)
{
	nRandomPoints = nRandomPoints > width * length ? width * length : nRandomPoints;
	std::vector<std::pair<unsigned, unsigned>> partitionPoints;
	std::vector<float> partitionHeights;
	for (unsigned int i = 0; i < nRandomPoints; ++i)
	{
		unsigned int x = widthDistribution(generator);
		unsigned int y = lengthDistribution(generator);
		float h = heightDistribution(generator) * levelDiff;
		partitionPoints.emplace_back(x, y);
		partitionHeights.emplace_back(h);
	}

	for (unsigned i = 0; i < length; ++i)
	{
		for (unsigned  j = 0; j < width; ++j)
		{
			setAt(j, i, partitionHeights.at(getClosest(j, i, partitionPoints)));
		}
	}
}

unsigned VoronoiMap::getClosest(unsigned int x, unsigned int y, const std::vector<std::pair<unsigned int, unsigned int>> &points)
{
	unsigned ret = 0;
	float min = width + 1;
	for (unsigned i = 0; i < points.size(); ++i)
	{
		unsigned px = points.at(i).first;
		unsigned py = points.at(i).second;
		float dist = sqrtf((x - px) * (x - px) + (y - py) * (y - py));
		if (dist < min)
		{
			min = dist;
			ret = i;
		}
	}
	return ret;
}
