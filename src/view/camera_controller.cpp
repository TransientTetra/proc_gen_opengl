#include "view/camera_controller.hpp"

CameraController::CameraController(Camera *camera, float movementSpeed, float rotationSpeed)
: camera(camera), movementSpeed(movementSpeed), rotationSpeed(rotationSpeed)
{
	isMovingForward = false;
	isMovingBackward = false;
	isMovingLeft = false;
	isMovingRight = false;
	isMovingUp = false;
	isMovingDown = false;
	isPitchingUp = false;
	isPitchingDown = false;
	isYawingLeft = false;
	isYawingRight = false;
	isRollingLeft = false;
	isRollingRight = false;
}

float CameraController::getMovementSpeed() const
{
	return movementSpeed;
}

void CameraController::setMovementSpeed(float movementSpeed)
{
	CameraController::movementSpeed = movementSpeed;
}

float CameraController::getRotationSpeed() const
{
	return rotationSpeed;
}

void CameraController::setRotationSpeed(float rotationSpeed)
{
	CameraController::rotationSpeed = rotationSpeed;
}

void CameraController::update(float deltaT)
{
	if (isMovingForward)
		moveForward(deltaT);
	if (isMovingBackward)
		moveBackward(deltaT);
	if (isMovingUp)
		moveUp(deltaT);
	if (isMovingDown)
		moveDown(deltaT);
	if (isMovingLeft)
		moveLeft(deltaT);
	if (isMovingRight)
		moveRight(deltaT);
	if (isPitchingUp)
		pitchUp(deltaT);
	if (isPitchingDown)
		pitchDown(deltaT);
	if (isRollingLeft)
		rollLeft(deltaT);
	if (isRollingRight)
		rollRight(deltaT);
	if (isYawingLeft)
		yawLeft(deltaT);
	if (isYawingRight)
		yawRight(deltaT);
}

void CameraController::startMoveForward()
{
	isMovingForward = true;
}

void CameraController::startMoveBackward()
{
	isMovingBackward = true;
}

void CameraController::startMoveLeft()
{
	isMovingLeft = true;
}

void CameraController::startMoveRight()
{
	isMovingRight = true;
}

void CameraController::startMoveUp()
{
	isMovingUp = true;
}

void CameraController::startMoveDown()
{
	isMovingDown = true;
}

void CameraController::startPitchUp()
{
	isPitchingUp = true;
}

void CameraController::startPitchDown()
{
	isPitchingDown = true;
}

void CameraController::startYawLeft()
{
	isYawingLeft = true;
}

void CameraController::startYawRight()
{
	isYawingRight = true;
}

void CameraController::startRollLeft()
{
	isRollingLeft = true;
}

void CameraController::startRollRight()
{
	isRollingRight = true;
}

void CameraController::stopMoveForward()
{
	isMovingForward = false;
}

void CameraController::stopMoveBackward()
{
	isMovingBackward = false;
}

void CameraController::stopMoveLeft()
{
	isMovingLeft = false;
}

void CameraController::stopMoveRight()
{
	isMovingRight = false;
}

void CameraController::stopMoveUp()
{
	isMovingUp = false;
}

void CameraController::stopMoveDown()
{
	isMovingDown = false;
}

void CameraController::stopPitchUp()
{
	isPitchingUp = false;
}

void CameraController::stopPitchDown()
{
	isPitchingDown = false;
}

void CameraController::stopYawLeft()
{
	isYawingLeft = false;
}

void CameraController::stopYawRight()
{
	isYawingRight = false;
}

void CameraController::stopRollLeft()
{
	isRollingLeft = false;
}

void CameraController::stopRollRight()
{
	isRollingRight = false;
}
