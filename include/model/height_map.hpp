#ifndef PROC_GEN_OPENGL_HEIGHT_MAP_HPP
#define PROC_GEN_OPENGL_HEIGHT_MAP_HPP


#include <vector>

//heightmap guarantees points to be in <-1, 1> when created, adding or multiplying can yield heightmaps with points
//outside of this range
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

	void multiply(const HeightMap &other);
	void add(const HeightMap &other);
	void normalize(float rangeMin, float rangeMax);
};


#endif //PROC_GEN_OPENGL_HEIGHT_MAP_HPP
