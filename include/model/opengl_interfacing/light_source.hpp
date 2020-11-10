#ifndef PROC_GEN_OPENGL_LIGHT_SOURCE_HPP
#define PROC_GEN_OPENGL_LIGHT_SOURCE_HPP

#include <glm/gtc/type_ptr.hpp>

class LightSource
{
private:
	glm::vec3 position;
	glm::vec3 color;
public:
	LightSource(glm::vec3 position, glm::vec3 color);

	virtual ~LightSource();

	const glm::vec3& getPosition() const;
	const glm::vec3& getColor() const;
};

#endif //PROC_GEN_OPENGL_LIGHT_SOURCE_HPP
