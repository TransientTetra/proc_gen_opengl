#ifndef PROC_GEN_OPENGL_ABOVE_CAMERA_HPP
#define PROC_GEN_OPENGL_ABOVE_CAMERA_HPP

#include "camera.hpp"

class AboveCamera : public Camera
{
private:
	float speed;
protected:
public:
	//all angles in radians
	AboveCamera(float fov, float aspectRatio, float nearDraw, float farDraw, float speed);

	void moveForward() override;

	void moveBackward() override;

	void moveLeft() override;

	void moveRight() override;

	void moveUp() override;

	void moveDown() override;


	float getSpeed() const;
};

#endif //PROC_GEN_OPENGL_ABOVE_CAMERA_HPP
