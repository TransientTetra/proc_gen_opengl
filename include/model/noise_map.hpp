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
	NoiseMap(unsigned int width, unsigned int length, std::unique_ptr<Noise> noise,
		  unsigned int nGridsWidth, unsigned int nGridsLength);
};


#endif //PROC_GEN_OPENGL_NOISE_MAP_HPP
