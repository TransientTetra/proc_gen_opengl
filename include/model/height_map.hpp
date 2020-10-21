#ifndef PROC_GEN_OPENGL_HEIGHT_MAP_HPP
#define PROC_GEN_OPENGL_HEIGHT_MAP_HPP


#include <vector>

class HeightMap
{
private:
protected:
	unsigned int width ; //number of points horizontal
	unsigned int length; //number of points vertical
	std::vector<float> points;
	void setAt(unsigned int x, unsigned int y, float v);
public:
	HeightMap();

	HeightMap(unsigned int width, unsigned int length);

	virtual ~HeightMap();

	const float& at(unsigned int x, unsigned int y) const;

	unsigned int getWidth() const;

	unsigned int getLength() const;
};


#endif //PROC_GEN_OPENGL_HEIGHT_MAP_HPP
