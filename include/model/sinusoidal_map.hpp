#ifndef PROC_GEN_OPENGL_SINUSOIDAL_MAP_HPP
#define PROC_GEN_OPENGL_SINUSOIDAL_MAP_HPP


#include "height_map.hpp"

class SinusoidalMap : public HeightMap
{
private:
protected:
public:
	SinusoidalMap(unsigned int width, unsigned int length, unsigned int nWavesWidth, unsigned int nWavesLength);
};


#endif //PROC_GEN_OPENGL_SINUSOIDAL_MAP_HPP
