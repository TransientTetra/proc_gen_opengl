#include "model/sinusoidal_map.hpp"
#include <cmath>

SinusoidalMap::SinusoidalMap(unsigned int width, unsigned int length, float scale, float min, float max)
{
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			points.emplace_back(sin(i));
		}
	}
}
