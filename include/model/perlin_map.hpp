#ifndef PROC_GEN_OPENGL_PERLIN_MAP_HPP
#define PROC_GEN_OPENGL_PERLIN_MAP_HPP


#include "height_map.hpp"

class PerlinMap : public HeightMap
{
private:
protected:
public:
	PerlinMap(unsigned int width, unsigned int length, float scale, float min, float max);
};


#endif //PROC_GEN_OPENGL_PERLIN_MAP_HPP
