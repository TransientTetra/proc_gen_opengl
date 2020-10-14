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

	float speed;

	bool movingForward;
	bool movingBackward;
	bool movingLeft;
	bool movingRight;
	bool movingUp;
	bool movingDown;
public:
	//all angles in radians
	Camera(float fov, float aspectRatio, float nearDraw, float farDraw);

	const glm::mat4 &getViewMatrix() const;
	const glm::mat4 &getProjectionMatrix() const;

	const glm::vec3 &getPosition() const;
	const glm::vec3 &getDirection() const;
	const glm::vec3 &getUp() const;

	void setPosition(const glm::vec3 &position);
	void setDirection(const glm::vec3 &direction, const glm::vec3 &up);
	void setForward(const glm::vec3 &, const glm::vec3 &up);

	virtual void moveForward(float frameTime) = 0;
	virtual void moveBackward(float frameTime) = 0;
	virtual void moveLeft(float frameTime) = 0;
	virtual void moveRight(float frameTime) = 0;
	virtual void moveUp(float frameTime) = 0;
	virtual void moveDown(float frameTime) = 0;
	virtual void rotateX(float xoffset) = 0;
	virtual void rotateY(float yoffset) = 0;
	//heads up: here will almost certainly be rotation methods like the ones above

	virtual void startMovingForward();
	virtual void stopMovingForward();
	virtual void startMovingBackward();
	virtual void stopMovingBackward();
	virtual void startMovingLeft();
	virtual void stopMovingLeft();
	virtual void startMovingRight();
	virtual void stopMovingRight();
	virtual void startMovingUp();
	virtual void stopMovingUp();
	virtual void startMovingDown();
	virtual void stopMovingDown();

	virtual void move(float frameTime) = 0;
};


#endif //PROC_GEN_OPENGL_CAMERA_HPP
