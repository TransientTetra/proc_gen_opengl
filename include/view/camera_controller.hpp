#ifndef PROC_GEN_OPENGL_CAMERA_CONTROLLER_HPP
#define PROC_GEN_OPENGL_CAMERA_CONTROLLER_HPP


#include <view/opengl_interfacing/camera.hpp>

class CameraController
{
protected:
	Camera* camera;
	float movementSpeed;
	float rotationSpeed;

public:
	CameraController(Camera *camera, float movementSpeed, float rotationSpeed);

	float getMovementSpeed() const;

	void setMovementSpeed(float movementSpeed);

	float getRotationSpeed() const;

	void setRotationSpeed(float rotationSpeed);

	virtual void moveForward(float deltaT) = 0;
	virtual void moveBackward(float deltaT) = 0;
	virtual void moveLeft(float deltaT) = 0;
	virtual void moveRight(float deltaT) = 0;
	virtual void moveUp(float deltaT) = 0;
	virtual void moveDown(float deltaT) = 0;

	virtual void pitch(float deltaT) = 0;
	virtual void yaw(float deltaT) = 0;
	virtual void roll(float deltaT) = 0;
};


#endif //PROC_GEN_OPENGL_CAMERA_CONTROLLER_HPP
