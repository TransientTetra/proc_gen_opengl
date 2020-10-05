#ifndef PROC_GEN_OPENGL_ABOVE_CAMERA_HPP
#define PROC_GEN_OPENGL_ABOVE_CAMERA_HPP

#include "camera.hpp"

class AboveCamera : public Camera
{
private:
protected:
public:
	//all angles in radians
	AboveCamera(float fov, float aspectRatio, float nearDraw, float farDraw, float speed);

	void moveForward(float frameTime) override;

	void moveBackward(float frameTime) override;

	void moveLeft(float frameTime) override;

	void moveRight(float frameTime) override;

	void moveUp(float frameTime) override;

	void moveDown(float frameTime) override;

	void move(float frameTime) override;
};

#endif //PROC_GEN_OPENGL_ABOVE_CAMERA_HPP
