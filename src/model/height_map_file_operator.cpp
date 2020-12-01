#include <filesystem>
#include "model/height_map_file_operator.hpp"
#include <bitmap_image.hpp>

HeightMapFileOperator::HeightMapFileOperator()
{}

HeightMapFileOperator::~HeightMapFileOperator()
{

}

HeightMap HeightMapFileOperator::loadHeightMap(const std::string& filename)
{
	if (not std::filesystem::exists(filename))
		throw;
	bitmap_image bitmap(filename);
	bitmap.convert_to_grayscale();
	const unsigned width = bitmap.width();
	const unsigned height = bitmap.height();
	HeightMap ret(width, height);
	for (unsigned y = 0; y < height; ++y)
	{
		for (unsigned x = 0; x < width; ++x)
		{
			unsigned char val;
			bitmap.get_pixel(x, y, val, val, val);
			float v = val / 255.0f;
			ret.setAt(x, y, v);
		}
	}
	ret.normalize(-1, 1);
	return ret;
}

void HeightMapFileOperator::saveHeightMap(const std::string& filename, const HeightMap& heightMap)
{
	const unsigned width = heightMap.getWidth();
	const unsigned height = heightMap.getLength();
	HeightMap temp = heightMap;
	temp.normalize(0, 1);
	bitmap_image bitmap(width, height);
	for (unsigned y = 0; y < height; ++y)
	{
		for (unsigned x = 0; x < width; ++x)
		{
			unsigned char val = temp.at(x, y) * 255;
			if (temp.at(x, y) > 1 or temp.at(x, y) < 0)
				throw;
			bitmap.set_pixel(y, x, val, val, val);
		}
	}
	bitmap.save_image(filename);
}
