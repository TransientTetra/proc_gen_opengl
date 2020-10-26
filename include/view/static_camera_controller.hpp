#ifndef PROC_GEN_OPENGL_STATIC_CAMERA_CONTROLLER_HPP
#define PROC_GEN_OPENGL_STATIC_CAMERA_CONTROLLER_HPP


#include "camera_controller.hpp"

class StaticCameraController : public CameraController
{
protected:
public:
	StaticCameraController(Camera *camera);

	void moveForward(float deltaT) override;

	void moveBackward(float deltaT) override;

	void moveLeft(float deltaT) override;

	void moveRight(float deltaT) override;

	void moveUp(float deltaT) override;

	void moveDown(float deltaT) override;

	void pitchUp(float deltaT) override;

	void pitchDown(float deltaT) override;

	void yawLeft(float deltaT) override;

	void yawRight(float deltaT) override;

	void rollLeft(float deltaT) override;

	void rollRight(float deltaT) override;
};


#endif //PROC_GEN_OPENGL_STATIC_CAMERA_CONTROLLER_HPP
