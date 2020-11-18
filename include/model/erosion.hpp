#ifndef PROC_GEN_OPENGL_EROSION_HPP
#define PROC_GEN_OPENGL_EROSION_HPP


#include "terrain.hpp"

class Erosion
{
protected:
	virtual void addAt(Terrain &terrain, unsigned int x, unsigned int y, float val);
	virtual void subtractAt(Terrain &terrain, unsigned int x, unsigned int y, float val);
public:
	virtual void erode(Terrain &terrain) = 0;
};


#endif //PROC_GEN_OPENGL_EROSION_HPP
