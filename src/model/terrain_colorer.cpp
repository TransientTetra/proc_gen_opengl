#include "model/terrain_colorer.hpp"

TerrainColorer::TerrainColorer()
{
	maxHeight = .5f;
	minHeight = -.5f;
	highColor = glm::vec3(1.0f, 1.0f, 1.0f) * .55f;
	midColor = glm::vec3(.37, .25, .125);
	lowColor = glm::vec3(.398f, .398f, .0f) * 1.f;
}

TerrainColorer::~TerrainColorer()
{

}

glm::vec3 TerrainColorer::getPointColor(glm::vec3 &point)
{
	float diff = (point.y - minHeight) / (maxHeight - minHeight);
	diff = diff < .0f ? .0f : diff > 1.0f ? 1.0f : diff;

	if (diff < .5f)
		return midColor * diff * 2.f + lowColor * (.5f - diff) * 2.f;
	else
		return highColor * (diff - .5f) * 2.f + midColor * (1 - diff) * 2.f;
}
