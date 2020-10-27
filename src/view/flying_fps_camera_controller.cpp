#include "view/flying_fps_camera_controller.hpp"

FlyingFPSCameraController::FlyingFPSCameraController(Camera *camera, float movementSpeed, float rotationSpeed)
: CameraController(camera, movementSpeed, rotationSpeed)
{}

void FlyingFPSCameraController::moveForward(float deltaT)
{

}

void FlyingFPSCameraController::moveBackward(float deltaT)
{

}

void FlyingFPSCameraController::moveLeft(float deltaT)
{
//	camera->move(deltaT * -movementSpeed, camera->getRight());
}

void FlyingFPSCameraController::moveRight(float deltaT)
{
//	camera->move(deltaT * movementSpeed, camera->getRight());
}

void FlyingFPSCameraController::moveUp(float deltaT)
{

}

void FlyingFPSCameraController::moveDown(float deltaT)
{

}

void FlyingFPSCameraController::pitch(float deltaT)
{

}

void FlyingFPSCameraController::yaw(float deltaT)
{

}

void FlyingFPSCameraController::roll(float deltaT)
{

}
