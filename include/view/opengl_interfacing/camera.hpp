#ifndef PROC_GEN_OPENGL_CAMERA_HPP
#define PROC_GEN_OPENGL_CAMERA_HPP


#include <glm/glm.hpp>

class Camera
{
protected:
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 forward;
	glm::vec3 up;

	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
public:
	//all angles in radians
	Camera(float fov, float aspectRatio, float nearDraw, float farDraw);

	const glm::mat4 &getViewMatrix() const;
	const glm::mat4 &getProjectionMatrix() const;

	const glm::vec3 &getPosition() const;
	const glm::vec3 &getDirection() const;
	const glm::vec3 &getForward() const;
	const glm::vec3 &getUp() const;

	void setPosition(const glm::vec3 &position);
	void setDirection(const glm::vec3 &direction, const glm::vec3 &up);

	virtual void moveForward() = 0;
	virtual void moveBackward() = 0;
	virtual void moveLeft() = 0;
	virtual void moveRight() = 0;
	virtual void moveUp() = 0;
	virtual void moveDown() = 0;
	//heads up: here will almost certainly be rotation methods like the ones above
};


#endif //PROC_GEN_OPENGL_CAMERA_HPP
