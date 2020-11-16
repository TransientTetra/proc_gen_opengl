#ifndef PROC_GEN_OPENGL_EROSION_HPP
#define PROC_GEN_OPENGL_EROSION_HPP


#include "terrain.hpp"

class Erosion
{
private:
protected:
public:
	virtual void erode(Terrain &terrain) = 0;
};


#endif //PROC_GEN_OPENGL_EROSION_HPP
