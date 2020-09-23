#ifndef PROC_GEN_OPENGL_NOISE_MAP_HPP
#define PROC_GEN_OPENGL_NOISE_MAP_HPP


#include <memory>
#include "height_map.hpp"
#include "noise.hpp"

class NoiseMap : public HeightMap
{
private:
	std::unique_ptr<Noise> noise;
protected:
public:
	//persistence can only be between 0 and 1; is clamped in implementation
	NoiseMap(unsigned int width, unsigned int length, std::unique_ptr<Noise> noise,
		  float horizontalScale, unsigned int nOctaves = 1.f, float persistence = .5f, float lacunarity = 2.f);
};


#endif //PROC_GEN_OPENGL_NOISE_MAP_HPP
