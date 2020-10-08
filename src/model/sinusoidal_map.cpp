#include "model/sinusoidal_map.hpp"
#include <cmath>

SinusoidalMap::SinusoidalMap(unsigned int width, unsigned int length,
			     unsigned int nWavesWidth, unsigned int nWavesLength)
{
	this->width = width;
	this->length = length;
	float cosPeriod = 2 * M_PI;
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			points.emplace_back(-cos((static_cast<float>(i) / length) * nWavesWidth * cosPeriod)
			* -cos((static_cast<float>(j) / width) * nWavesLength * cosPeriod));
		}
	}
}
