#ifndef PROC_GEN_OPENGL_CUBE_HPP
#define PROC_GEN_OPENGL_CUBE_HPP


#include "entity.hpp"

class Cube : public Entity
{
private:
protected:
	float width;
	float height;
	float depth;
public:
	Cube(Point position, float width, float height, float depth);
};


#endif //PROC_GEN_OPENGL_CUBE_HPP
