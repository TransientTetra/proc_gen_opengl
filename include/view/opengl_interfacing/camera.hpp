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

	//this only sets the position vector! this does not change direction where camera looks at, meaning that
	//using only this will result in camera moving, but looking at the point set in direction vector
	void setPosition(const glm::vec3 &position);

	void setDirection(const glm::vec3 &direction);
};


#endif //PROC_GEN_OPENGL_CAMERA_HPP
