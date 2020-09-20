#ifndef PROC_GEN_OPENGL_TERRAIN_HPP
#define PROC_GEN_OPENGL_TERRAIN_HPP


#include <vector>
#include <glm/glm.hpp>
#include <memory>
#include "height_map.hpp"

//terrain translates 2d heightmap to 3d terrain
class Terrain
{
private:
protected:
	float length; //z axis
	float width; //x axis
	float level; //y axis

	std::unique_ptr<HeightMap> heightMap;
	std::vector<glm::vec3> points;

	void calculatePoints(int scale);
public:
	Terrain(float width, float length, int scale);

	float getLength() const;

	float getWidth() const;

	float getLevel() const;

	unsigned int getNPointsLength() const;

	unsigned int getNPointsWidth() const;
	const std::vector<glm::vec3> &getPoints() const;

};


#endif //PROC_GEN_OPENGL_TERRAIN_HPP
