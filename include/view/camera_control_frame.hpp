#ifndef PROC_GEN_OPENGL_CAMERA_CONTROL_FRAME_HPP
#define PROC_GEN_OPENGL_CAMERA_CONTROL_FRAME_HPP


#include "frame.hpp"
#include "camera_type.hpp"
#include "camera_view.hpp"

class CameraControlFrame : public Frame
{
private:
	void mainDraw() override;
	CameraType cameraType;
public:
	CameraControlFrame(CameraView *view, const std::string &name);
};


#endif //PROC_GEN_OPENGL_CAMERA_CONTROL_FRAME_HPP
