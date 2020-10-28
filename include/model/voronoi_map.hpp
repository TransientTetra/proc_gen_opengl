#ifndef PROC_GEN_OPENGL_VORONOI_MAP_HPP
#define PROC_GEN_OPENGL_VORONOI_MAP_HPP


#include <random>
#include "height_map.hpp"

class VoronoiMap : public HeightMap
{
private:
	std::mt19937 generator;
	std::uniform_real_distribution<float> heightDistribution;
	std::uniform_int_distribution<unsigned int> widthDistribution;
	std::uniform_int_distribution<unsigned int> lengthDistribution;
public:
	VoronoiMap(unsigned int width, unsigned int length, unsigned int seed, unsigned int nRandomPoints,
	    float levelDiff, float gapWidth, float gapHeight);
};


#endif //PROC_GEN_OPENGL_VORONOI_MAP_HPP