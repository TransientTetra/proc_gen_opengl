#ifndef PROC_GEN_OPENGL_TERRAIN_HPP
#define PROC_GEN_OPENGL_TERRAIN_HPP


#include <vector>
#include <glm/glm.hpp>
#include <memory>
#include "height_map.hpp"
#include "entity.hpp"

//terrain translates 2d heightmap to 3d terrain
class Terrain : public Entity
{
private:
protected:
	float length; //z axis
	float width; //x axis
	float scale; //amplitude

	std::unique_ptr<HeightMap> heightMap;

	void calculatePoints();
	glm::vec3 calcTriangleNormal(const glm::vec3 &v1, const glm::vec3 &v2, const glm::vec3 &v3);
public:
	Terrain(float width, float length, float scale);

	void updateNormals();
	void setHeightMap(std::unique_ptr<HeightMap> heightMap);

	void setLength(float length);

	void setWidth(float width);

	void setScale(float scale);

	float getLength() const;

	float getWidth() const;

	unsigned int getNPointsLength() const;

	unsigned int getNPointsWidth() const;

	Vertex& at(unsigned x, unsigned y);
	Vertex& at(unsigned i);

};


#endif //PROC_GEN_OPENGL_TERRAIN_HPP
