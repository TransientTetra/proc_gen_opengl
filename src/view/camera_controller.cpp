#include "view/camera_controller.hpp"

CameraController::CameraController(Camera *camera, float movementSpeed, float rotationSpeed)
: camera(camera), movementSpeed(movementSpeed), rotationSpeed(rotationSpeed)
{
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