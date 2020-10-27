#include "view/above_camera_controller.hpp"

AboveCameraController::AboveCameraController(Camera *camera, float movementSpeed, float rotationSpeed)
: CameraController(camera, movementSpeed, rotationSpeed)
{
	glm::vec3 pos = camera->getPosition();
	camera->setDirection(glm::vec3(pos.x, -1.0f, pos.z), glm::vec3(.0f, .0f, -1.0f));
}

void AboveCameraController::moveForward(float deltaT)
{
	camera->move(deltaT * -movementSpeed, glm::vec3(0, 0, 1));
}

void AboveCameraController::moveBackward(float deltaT)
{
	camera->move(deltaT * movementSpeed, glm::vec3(0, 0, 1));
}

void AboveCameraController::moveLeft(float deltaT)
{
	camera->move(deltaT * -movementSpeed, glm::vec3(1, 0, 0));
}

void AboveCameraController::moveRight(float deltaT)
{
	camera->move(deltaT * movementSpeed, glm::vec3(1, 0, 0));
}

void AboveCameraController::moveUp(float deltaT)
{
	camera->move(deltaT * movementSpeed, glm::vec3(0, 1, 0));
}

void AboveCameraController::moveDown(float deltaT)
{
	camera->move(deltaT * -movementSpeed, glm::vec3(0, 1, 0));
}

void AboveCameraController::pitchUp(float deltaT)
{

}

void AboveCameraController::pitchDown(float deltaT)
{

}

void AboveCameraController::yawLeft(float deltaT)
{

}

void AboveCameraController::yawRight(float deltaT)
{

}

void AboveCameraController::rollLeft(float deltaT)
{

}

void AboveCameraController::rollRight(float deltaT)
{

}
