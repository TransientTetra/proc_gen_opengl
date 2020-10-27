#include "view/flying_fps_camera_controller.hpp"

FlyingFPSCameraController::FlyingFPSCameraController(Camera *camera, float movementSpeed, float rotationSpeed)
: CameraController(camera, movementSpeed, rotationSpeed)
{}

void FlyingFPSCameraController::moveForward(float deltaT)
{
	glm::vec3 directionPlane = camera->getDirection();
	directionPlane.y = 0;
	camera->move(deltaT * movementSpeed, directionPlane);
}

void FlyingFPSCameraController::moveBackward(float deltaT)
{
	glm::vec3 directionPlane = camera->getDirection();
	directionPlane.y = 0;
	camera->move(deltaT * -movementSpeed, directionPlane);
}

void FlyingFPSCameraController::moveLeft(float deltaT)
{
	glm::vec3 directionPlane = camera->getRight();
	directionPlane.y = 0;
	camera->move(deltaT * -movementSpeed, directionPlane);
}

void FlyingFPSCameraController::moveRight(float deltaT)
{
	glm::vec3 directionPlane = camera->getRight();
	directionPlane.y = 0;
	camera->move(deltaT * movementSpeed, directionPlane);
}

void FlyingFPSCameraController::moveUp(float deltaT)
{
	camera->move(deltaT * movementSpeed, glm::vec3(0, 1, 0));
}

void FlyingFPSCameraController::moveDown(float deltaT)
{
	camera->move(deltaT * -movementSpeed, glm::vec3(0, 1, 0));
}

void FlyingFPSCameraController::pitchUp(float deltaT)
{
	camera->rotate(deltaT * rotationSpeed, camera->getRight());
}

void FlyingFPSCameraController::pitchDown(float deltaT)
{
	camera->rotate(deltaT * -rotationSpeed, camera->getRight());
}

void FlyingFPSCameraController::yawLeft(float deltaT)
{
	camera->rotate(deltaT * rotationSpeed, glm::vec3(0, 1, 0));
}

void FlyingFPSCameraController::yawRight(float deltaT)
{
	camera->rotate(deltaT * -rotationSpeed, glm::vec3(0, 1, 0));
}

void FlyingFPSCameraController::rollLeft(float deltaT)
{

}

void FlyingFPSCameraController::rollRight(float deltaT)
{

}
