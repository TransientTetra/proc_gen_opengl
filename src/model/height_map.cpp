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

void HeightMap::multiply(const HeightMap &other)
{
	unsigned width = getWidth() < other.getWidth() ? getWidth() : other.getWidth();
	unsigned length = getLength() < other.getLength() ? getLength() : other.getLength();
	for (unsigned i = 0; i < length; ++i)
	{
		for (unsigned j = 0; j < width; ++j)
		{
			float val = at(j, i) * other.at(j, i);
			setAt(j, i, val);
		}
	}
}

void HeightMap::add(const HeightMap &other)
{
	unsigned width = getWidth() < other.getWidth() ? getWidth() : other.getWidth();
	unsigned length = getLength() < other.getLength() ? getLength() : other.getLength();
	float min = 1;
	float max = -1;
	for (unsigned i = 0; i < length; ++i)
	{
		for (unsigned j = 0; j < width; ++j)
		{
			float val = at(j, i) + other.at(j, i);
			if (val < min) min = val;
			if (val > max) max = val;
			setAt(j, i, val);
		}
	}

	//normalization
	for (unsigned i = 0; i < length; ++i)
	{
		for (unsigned j = 0; j < width; ++j)
		{
			float normalizedVal = 2 * (static_cast<float>(at(j, i)) - min) / (max - min) - 1;
			setAt(j, i, normalizedVal);
		}
	}
}
