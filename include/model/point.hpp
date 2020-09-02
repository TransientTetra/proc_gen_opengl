#ifndef PROC_GEN_OPENGL_POINT_HPP
#define PROC_GEN_OPENGL_POINT_HPP


class Point
{
private:
protected:
public:
	float x;
	float y;
	float z;

	Point(float x, float y, float z);
	Point(Point &other);
	void operator=(Point const &other);
};


#endif //PROC_GEN_OPENGL_POINT_HPP
