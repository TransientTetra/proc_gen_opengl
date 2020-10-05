#ifndef PROC_GEN_OPENGL_CUBE_HPP
#define PROC_GEN_OPENGL_CUBE_HPP


#include "entity.hpp"

class Cube : public Entity
{
private:
protected:
	float width; //x axis
	float height; //y axis
	float depth; //z axis
public:
	Cube(glm::vec3 position, float width, float height, float depth);
};


#endif //PROC_GEN_OPENGL_CUBE_HPP
