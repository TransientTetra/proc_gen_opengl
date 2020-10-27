#include "view/above_camera_controller.hpp"

AboveCameraController::AboveCameraController(Camera *camera, float movementSpeed, float rotationSpeed)
: CameraController(camera, movementSpeed, rotationSpeed)
{
	glm::vec3 pos = camera->getPosition();
	camera->setDirection(glm::vec3(pos.x, -1.0f, pos.z), glm::vec3(.0f, .0f, -1.0f));
}

void AboveCameraController::moveForward(float deltaT)
{
	camera->moveZ(deltaT * -movementSpeed);
}

void AboveCameraController::moveBackward(float deltaT)
{
	camera->moveZ(deltaT * movementSpeed);
}

void AboveCameraController::moveLeft(float deltaT)
{
	camera->moveX(deltaT * -movementSpeed);
}

void AboveCameraController::moveRight(float deltaT)
{
	camera->moveX(deltaT * movementSpeed);
}

void AboveCameraController::moveUp(float deltaT)
{
	camera->moveY(deltaT * movementSpeed);
}

void AboveCameraController::moveDown(float deltaT)
{
	camera->moveY(deltaT * -movementSpeed);
}

void AboveCameraController::pitch(float deltaT)
{

}

void AboveCameraController::yaw(float deltaT)
{

}

void AboveCameraController::roll(float deltaT)
{

}
