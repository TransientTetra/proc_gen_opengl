#ifndef PROC_GEN_OPENGL_CAMERA_CONTROL_FRAME_HPP
#define PROC_GEN_OPENGL_CAMERA_CONTROL_FRAME_HPP


#include "frame.hpp"
#include "camera_controller_type.hpp"
#include "scene_3d.hpp"
#include "rendering_mode.hpp"

class CameraControlFrame : public Frame
{
private:
	void mainDraw() override;
	CameraControllerType cameraType;
	RenderingMode renderingMode;

	//frame buffer variables
	float mouseSensitivity;
	float fov; //degrees!!
	float drawDistance;
	float speed;
	float xpos;
	float ypos;
	float zpos;
public:
	CameraControlFrame(Scene3D* view, const std::string& name, int xPos, int yPos);
};


#endif //PROC_GEN_OPENGL_CAMERA_CONTROL_FRAME_HPP
