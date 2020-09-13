#ifndef PROC_GEN_OPENGL_TERRAIN_HPP
#define PROC_GEN_OPENGL_TERRAIN_HPP


#include <vector>
#include <glm/glm.hpp>

class Terrain
{
private:
protected:
	unsigned int length; //z axis
	unsigned int width; //x axis
	std::vector<glm::vec3> vertices;

public:
	Terrain(unsigned int width, unsigned int length);
};


#endif //PROC_GEN_OPENGL_TERRAIN_HPP
