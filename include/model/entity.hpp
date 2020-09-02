#ifndef PROC_GEN_OPENGL_ENTITY_HPP
#define PROC_GEN_OPENGL_ENTITY_HPP


#include "point.hpp"

class Entity
{
private:
protected:
	Point position;
public:
	Entity();
	Entity(Point position);

	const Point &getPosition() const;

	void setPosition(const Point &position);
};


#endif //PROC_GEN_OPENGL_ENTITY_HPP
