#ifndef PROC_GEN_OPENGL_FLYING_FPS_CAMERA_CONTROLLER_HPP
#define PROC_GEN_OPENGL_FLYING_FPS_CAMERA_CONTROLLER_HPP


#include "camera_controller.hpp"

class FlyingFPSCameraController : public CameraController
{
private:
public:
	FlyingFPSCameraController(Camera *camera, float movementSpeed, float rotationSpeed);

	void pitch(float deltaT) override;
	void yaw(float deltaT) override;
	void roll(float deltaT) override;
	void moveForward(float deltaT) override;

	void moveBackward(float deltaT) override;

	void moveLeft(float deltaT) override;

	void moveRight(float deltaT) override;

	void moveUp(float deltaT) override;

	void moveDown(float deltaT) override;
};


#endif //PROC_GEN_OPENGL_FLYING_FPS_CAMERA_CONTROLLER_HPP
