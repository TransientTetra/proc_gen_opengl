#include "model/cube.hpp"

Cube::Cube(Point position, float width, float height, float depth)
: Entity(position), width(width), height(height), depth(depth)
{
	float frontFaceDepth = position.z - depth / 2;
	vertices.emplace_back(position.x - width / 2, position.y + height / 2, frontFaceDepth);
	vertices.emplace_back(position.x - width / 2, position.y - height / 2, frontFaceDepth);
	vertices.emplace_back(position.x + width / 2, position.y - height / 2, frontFaceDepth);
	vertices.emplace_back(position.x + width / 2, position.y + height / 2, frontFaceDepth);

	if (depth > 0)
	{
		vertices.emplace_back(position.x - width / 2, position.y + height / 2, position.z + depth / 2);
		vertices.emplace_back(position.x - width / 2, position.y - height / 2, position.z + depth / 2);
		vertices.emplace_back(position.x + width / 2, position.y - height / 2, position.z + depth / 2);
		vertices.emplace_back(position.x + width / 2, position.y + height / 2, position.z + depth / 2);
	}
	nVertices = vertices.size();
}
