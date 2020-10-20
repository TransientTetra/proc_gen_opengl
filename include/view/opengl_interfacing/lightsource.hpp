#ifndef PROC_GEN_OPENGL_LIGHTSOURCE_HPP
#define PROC_GEN_OPENGL_LIGHTSOURCE_HPP

#include <glm/gtc/type_ptr.hpp>

class Lightsource
{
private:
	glm::vec3 position;
	glm::vec3 color;
public:
	Lightsource(glm::vec3 position, glm::vec3 color);

	virtual ~Lightsource();

	glm::vec3 getPosition();
	glm::vec3 getColor();
};

#endif //PROC_GEN_OPENGL_LIGHTSOURCE_HPP
