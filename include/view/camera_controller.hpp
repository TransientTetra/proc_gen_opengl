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

	virtual void pitchUp(float deltaT) = 0;
	virtual void pitchDown(float deltaT) = 0;
	virtual void yawLeft(float deltaT) = 0;
	virtual void yawRight(float deltaT) = 0;
	virtual void rollLeft(float deltaT) = 0;
	virtual void rollRight(float deltaT) = 0;
};


#endif //PROC_GEN_OPENGL_CAMERA_CONTROLLER_HPP
