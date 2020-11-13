#include "model/cube.hpp"

Cube::Cube(glm::vec3 position, float width, float height, float depth)
: Entity(position), width(width), height(height), depth(depth)
{
//	float frontFaceDepth = position.z - depth / 2;
//	vertices =
//		{
//			glm::vec3(position.x - width / 2, position.y + height / 2, frontFaceDepth),
//			glm::vec3(position.x - width / 2, position.y - height / 2, frontFaceDepth),
//			glm::vec3(position.x + width / 2, position.y - height / 2, frontFaceDepth),
//			glm::vec3(position.x + width / 2, position.y + height / 2, frontFaceDepth),
//		};
//
//	indices =
//		{
//			0, 1, 3,
//			1, 2, 3,
//		};
//
//	if (depth > 0)
//	{
//		vertices.emplace_back(position.x - width / 2, position.y + height / 2, position.z + depth / 2);
//		vertices.emplace_back(position.x - width / 2, position.y - height / 2, position.z + depth / 2);
//		vertices.emplace_back(position.x + width / 2, position.y - height / 2, position.z + depth / 2);
//		vertices.emplace_back(position.x + width / 2, position.y + height / 2, position.z + depth / 2);
//
//		indices =
//			{
//				0, 1, 3,
//				1, 2, 3,
//
//				4, 5, 7,
//				7, 5, 6,
//
//				0, 4, 5,
//				0, 5, 1,
//
//				2, 1, 6,
//				1, 5, 6,
//
//				7, 3, 6,
//				3, 6, 2,
//
//				7, 4, 0,
//				7, 0, 3
//			};
//	}
}
