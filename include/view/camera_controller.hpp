#ifndef PROC_GEN_OPENGL_CAMERA_CONTROLLER_HPP
#define PROC_GEN_OPENGL_CAMERA_CONTROLLER_HPP


#include <view/opengl_interfacing/camera.hpp>

class CameraController
{
protected:
	Camera* camera;
	float movementSpeed;
	float rotationSpeed;

	bool isMovingForward;
	bool isMovingBackward;
	bool isMovingLeft;
	bool isMovingRight;
	bool isMovingUp;
	bool isMovingDown;
	bool isPitchingUp;
	bool isPitchingDown;
	bool isYawingLeft;
	bool isYawingRight;
	bool isRollingLeft;
	bool isRollingRight;

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
public:
	CameraController(Camera *camera, float movementSpeed, float rotationSpeed);

	float getMovementSpeed() const;

	void setMovementSpeed(float movementSpeed);

	float getRotationSpeed() const;

	void setRotationSpeed(float rotationSpeed);

	virtual void startMoveForward();
	virtual void startMoveBackward();
	virtual void startMoveLeft();
	virtual void startMoveRight();
	virtual void startMoveUp();
	virtual void startMoveDown();
	virtual void startPitchUp();
	virtual void startPitchDown();
	virtual void startYawLeft();
	virtual void startYawRight();
	virtual void startRollLeft();
	virtual void startRollRight();
	virtual void stopMoveForward();
	virtual void stopMoveBackward();
	virtual void stopMoveLeft();
	virtual void stopMoveRight();
	virtual void stopMoveUp();
	virtual void stopMoveDown();
	virtual void stopPitchUp();
	virtual void stopPitchDown();
	virtual void stopYawLeft();
	virtual void stopYawRight();
	virtual void stopRollLeft();
	virtual void stopRollRight();
	virtual void update(float deltaT);
};


#endif //PROC_GEN_OPENGL_CAMERA_CONTROLLER_HPP
