#include "model/terrain.hpp"

Terrain::Terrain(unsigned int width, unsigned int length)
{
	vertices =
		{
			glm::vec3(width / 2, 0, length / 2),
			glm::vec3(width / 2, 0, -length / 2),
			glm::vec3(-width / 2, 0, -length / 2),
			glm::vec3(-width / 2, 0, length / 2),
		};
}
