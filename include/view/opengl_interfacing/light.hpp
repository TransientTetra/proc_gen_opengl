#ifndef PROC_GEN_OPENGL_LIGHT_HPP
#define PROC_GEN_OPENGL_LIGHT_HPP

#include <glm/gtc/type_ptr.hpp>

class Light
{
private:
	glm::vec3 position;
	glm::vec3 color;
public:
	Light();
	Light(glm::vec3 position, glm::vec3 color);

	virtual ~Light();

	glm::vec3 getPosition();
	glm::vec3 getColor();


};

#endif //PROC_GEN_OPENGL_LIGHT_HPP
