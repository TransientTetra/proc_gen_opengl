#include "model/height_map.hpp"

HeightMap::HeightMap()
{
	width = 0;
	length = 0;
}

HeightMap::HeightMap(unsigned int width, unsigned int length)
: width(width), length(length)
{
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			points.emplace_back(0);
		}
	}
}

HeightMap::~HeightMap()
{

}


float HeightMap::at(unsigned int x, unsigned int y)
{
	return points[y * width + x];
}

unsigned int HeightMap::getWidth() const
{
	return width;
}

unsigned int HeightMap::getLength() const
{
	return length;
}