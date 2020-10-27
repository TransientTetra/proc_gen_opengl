#include "view/flying_fps_camera_controller.hpp"

FlyingFPSCameraController::FlyingFPSCameraController(Camera *camera, float movementSpeed, float rotationSpeed)
: CameraController(camera, movementSpeed, rotationSpeed)
{}

void FlyingFPSCameraController::moveForward(float deltaT)
{
	glm::vec3 directionPlane = camera->getDirection();
	if (directionPlane.y > 0)
		directionPlane -= camera->getUp();
	else
		directionPlane += camera->getUp();
	directionPlane.y = 0;
	camera->move(deltaT * movementSpeed, directionPlane);
}

void FlyingFPSCameraController::moveBackward(float deltaT)
{
	glm::vec3 directionPlane = camera->getDirection();
	if (directionPlane.y > 0)
		directionPlane -= camera->getUp();
	else
		directionPlane += camera->getUp();
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
	glm::vec3 down(0, -1, 0);
	float dirDot = glm::dot(camera->getDirection(), down);
	float upDot = glm::dot(camera->getUp(), down);
	if (dirDot > 0 or (dirDot > -1 and upDot < 0))
		camera->rotate(deltaT * rotationSpeed, camera->getRight());
}

void FlyingFPSCameraController::pitchDown(float deltaT)
{
	glm::vec3 down(0, -1, 0);
	float dirDot = glm::dot(camera->getDirection(), down);
	float upDot = glm::dot(camera->getUp(), down);
	if (dirDot < 0 or (dirDot < 1 and upDot < 0))
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
