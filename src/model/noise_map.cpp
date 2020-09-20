#include "model/noise_map.hpp"

NoiseMap::NoiseMap(unsigned int width, unsigned int length, std::unique_ptr<Noise> noise, float noiseScale)
: noise(std::move(noise))
{
	this->width = width;
	this->length = length;
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			points.emplace_back(this->noise->eval(static_cast<float>(j) / noiseScale,
					 static_cast<float>(i) / noiseScale));
		}
	}
}
