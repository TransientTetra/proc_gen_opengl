#ifndef PROC_GEN_OPENGL_CAMERA_HPP
#define PROC_GEN_OPENGL_CAMERA_HPP


#include <glm/glm.hpp>

class Camera
{
private:
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 up;
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
protected:
public:
	//all angles in radians
	Camera(float fov, float aspectRatio, float nearDraw, float farDraw);

	const glm::mat4 &getViewMatrix() const;

	const glm::mat4 &getProjectionMatrix() const;
};


#endif //PROC_GEN_OPENGL_CAMERA_HPP
