#include "model/noise_map.hpp"

NoiseMap::NoiseMap(unsigned int width, unsigned int length, std::unique_ptr<Noise> noise, float horizontalScale,
		   unsigned int nOctaves, float persistence, float lacunarity)
: noise(std::move(noise))
{
	nOctaves = nOctaves < 1 ? 1 : nOctaves;
	persistence = persistence < 0.f ? 0.f : persistence > 1.f ? 1.f : persistence;
	lacunarity = lacunarity < 1 ? 1 : lacunarity;

	this->width = width;
	this->length = length;
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			float currHeight = 0;
			float amplitude = 1;
			float frequency = 1;
			for (int k = 0; k < nOctaves; ++k)
			{
				float noiseVal = this->noise->eval
						((static_cast<float>(j) * frequency) / horizontalScale,
						(static_cast<float>(i) * frequency) / horizontalScale);

				currHeight += noiseVal * amplitude;
				amplitude *= persistence;
				frequency *= lacunarity;
			}
			points.emplace_back(currHeight);
		}
	}
}
