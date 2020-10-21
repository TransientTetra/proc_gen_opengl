#ifndef PROC_GEN_OPENGL_DIAMOND_SQUARE_MAP_HPP
#define PROC_GEN_OPENGL_DIAMOND_SQUARE_MAP_HPP


#include "height_map.hpp"
#include "white_noise.hpp"

class DiamondSquareMap : public HeightMap
{
private:
	std::mt19937 generator;
	std::uniform_real_distribution<float> distribution;

	unsigned int findSmallestSquareSide();
public:
	DiamondSquareMap(unsigned int width, unsigned int length, unsigned int seed, float persistence);
};


#endif //PROC_GEN_OPENGL_DIAMOND_SQUARE_MAP_HPP
