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
	float scale; //y axis

	float xOffset;
	float yOffset;
	float zOffset;

	std::unique_ptr<HeightMap> heightMap;
	std::vector<glm::vec3> points;

	void calculatePoints();
public:
	Terrain(float width, float length, float scale, float level);

	Terrain(float length, float width, float scale, float xOffset, float yOffset, float zOffset);

	void setHeightMap(std::unique_ptr<HeightMap> heightMap);

	void setLength(float length);

	void setWidth(float width);

	void setLevel(float level);

	void setScale(float scale);

	float getLength() const;

	float getWidth() const;

	float getLevel() const;

	unsigned int getNPointsLength() const;

	unsigned int getNPointsWidth() const;
	const std::vector<glm::vec3> &getPoints() const;

};


#endif //PROC_GEN_OPENGL_TERRAIN_HPP
