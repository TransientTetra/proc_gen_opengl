#include "model/height_map.hpp"

HeightMap::HeightMap()
{
	width = 0;
	length = 0;
}

HeightMap::HeightMap(unsigned int width, unsigned int length)
: width(width), length(length), points(width * length)
{}

HeightMap::~HeightMap()
{

}


const float& HeightMap::at(unsigned int x, unsigned int y) const
{
	return points.at(y * width + x);
}

unsigned int HeightMap::getWidth() const
{
	return width;
}

unsigned int HeightMap::getLength() const
{
	return length;
}

void HeightMap::setAt(unsigned int x, unsigned int y, float v)
{
	points.at(y * width + x) = v;
}
