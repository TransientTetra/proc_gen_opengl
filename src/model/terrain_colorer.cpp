#include "model/terrain_colorer.hpp"

TerrainColorer::TerrainColorer()
{
	maxHeight = 2.0f;
	minHeight = -2.0f;
	highColor = glm::vec3(1.0f, .0f, .0f);
	lowColor = glm::vec3(.0f, 1.0f, .0f);
}

TerrainColorer::~TerrainColorer()
{

}

glm::vec3 TerrainColorer::getPointColor(glm::vec3 &point)
{
	float diff = (point.y - minHeight) / (maxHeight - minHeight);
	diff = diff < .0f ? .0f : diff > 1.0f ? 1.0f : diff;

	glm::vec3 col = glm::vec3(
		highColor.r > lowColor.r ? (highColor.r - lowColor.r) * diff + lowColor.r : lowColor.r - (lowColor.r - highColor.r) * diff,
		highColor.g > lowColor.g ? (highColor.g - lowColor.g) * diff + lowColor.g : lowColor.g - (lowColor.g - highColor.g) * diff,
		highColor.b > lowColor.b ? (highColor.b - lowColor.b) * diff + lowColor.b : lowColor.b - (lowColor.b - highColor.b) * diff
	);

	return col;
}
