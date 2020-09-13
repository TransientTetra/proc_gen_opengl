#ifndef PROC_GEN_OPENGL_TERRAIN_HPP
#define PROC_GEN_OPENGL_TERRAIN_HPP


#include <vector>
#include <glm/glm.hpp>
#include "height_map.hpp"

class Terrain
{
private:
protected:
	float length; //z axis
	float width; //x axis
	float level; //y axis

	HeightMap heightMap;
	std::vector<glm::vec3> points;

	void calculatePoints();
public:
	Terrain(float width, float length);

	float getLength() const;

	float getWidth() const;

	float getLevel() const;

	unsigned int getNPointsLength() const;

	unsigned int getNPointsWidth() const;
	const std::vector<glm::vec3> &getPoints() const;

};


#endif //PROC_GEN_OPENGL_TERRAIN_HPP
