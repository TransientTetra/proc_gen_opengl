#ifndef PROC_GEN_OPENGL_TERRAIN_COLORER_HPP
#define PROC_GEN_OPENGL_TERRAIN_COLORER_HPP

#include <vector>
#include <view/opengl_interfacing/vertex.hpp>
#include <model/terrain.hpp>
#include <view/opengl_interfacing/mesh.hpp>

class TerrainColorer
{
private:
	float maxHeight;
	float minHeight;
	glm::vec3 highColor;
	glm::vec3 lowColor;

public:
	TerrainColorer();

	glm::vec3 getPointColor(glm::vec3 point);
};

#endif //PROC_GEN_OPENGL_TERRAIN_COLORER_HPP
