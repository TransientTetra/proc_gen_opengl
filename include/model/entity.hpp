#ifndef PROC_GEN_OPENGL_ENTITY_HPP
#define PROC_GEN_OPENGL_ENTITY_HPP


#include <vector>
#include "point.hpp"

class Entity
{
protected:
	Point position;
	std::vector<Point> vertices;
	int nVertices;
public:
	Entity();
	Entity(Point position);

	const Point &getPosition() const;

	void setPosition(const Point &position);
};


#endif //PROC_GEN_OPENGL_ENTITY_HPP
