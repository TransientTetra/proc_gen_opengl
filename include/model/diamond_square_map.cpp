#include <complex>
#include "diamond_square_map.hpp"

DiamondSquareMap::DiamondSquareMap(unsigned int width, unsigned int length, unsigned int seed, float persistence)
: HeightMap(), generator(seed), distribution(-1.f, 1.f)
{
	DiamondSquareMap::width = width;
	DiamondSquareMap::length = length;
	unsigned int squareSide = findSmallestSquareSide();
	DiamondSquareMap::width = squareSide;
	DiamondSquareMap::length = squareSide;
	points = std::vector<float>(squareSide * squareSide);
	setAt(0, 0, distribution(generator));
	setAt(squareSide - 1, 0, distribution(generator));
	setAt(0, squareSide - 1, distribution(generator));
	setAt(squareSide - 1, squareSide - 1, distribution(generator));

	unsigned int tileWidth = squareSide - 1;
	while (tileWidth > 1)
	{

		unsigned int halfSide = tileWidth / 2;

		//diamond
		for (unsigned int i = 0; i < squareSide - 1; i += tileWidth)
		{
			for (unsigned int j = 0; j < squareSide - 1; j += tileWidth)
			{
				float val = static_cast<float>(at(i, j) + at(i + tileWidth, j) + at(i, j + tileWidth)
					+ at(i + tileWidth, j + tileWidth)) / 4;
				setAt(i + halfSide, j + halfSide, val);
			}
		}

		//square
		for (unsigned int i = 0; i < halfSide - 1; i += halfSide)
		{
			for (unsigned int j = (i + halfSide) % tileWidth; j < squareSide - 1; j += tileWidth)
			{
				float val = static_cast<float>(
					at((i - halfSide + squareSide - 1) % (squareSide - 1), j) +
					at((i + halfSide) % (squareSide - 1), j) +
					at(i, (j + halfSide) % (squareSide - 1)) +
					at(i, (j - halfSide + squareSide - 1) % (squareSide - 1))) / 4;
				setAt(i, j, val);
				if (i == 0)
					setAt(squareSide - 1, j, val);
				if (j == 0)
					setAt(i, squareSide - 1, val);
			}
		}
		tileWidth /= 2;
	}

//	//cutting of a portion of the square
//	std::vector<float> temp(width * length);
//	for (int i = 0; i < length; ++i)
//	{
//		for (int j = 0; j < width; ++j)
//		{
//			temp[j * width + i] = at(i, j);
//		}
//	}
//	DiamondSquareMap::width = width;
//	DiamondSquareMap::length = length;
//	points = temp;
}

unsigned int DiamondSquareMap::findSmallestSquareSide()
{
	//diamond square algo operates on squares with side of 2^n + 1
	unsigned int squareW = std::pow(2, std::ceil(std::log2l(width - 1))) + 1;
	unsigned int squareH = std::pow(2, std::ceil(std::log2l(length - 1))) + 1;
	return std::max(squareW, squareH);
}
