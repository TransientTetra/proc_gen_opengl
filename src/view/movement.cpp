#include "view/movement.hpp"

Movement::Movement(CameraController *cameraController)
: cameraController(cameraController)
{}

void Movement::setCameraController(CameraController *cameraController)
{
	Movement::cameraController = cameraController;
}
