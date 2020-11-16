#ifndef PROC_GEN_OPENGL_EROSION_CONTROL_FRAME_HPP
#define PROC_GEN_OPENGL_EROSION_CONTROL_FRAME_HPP


#include <controller/world_manipulator.hpp>
#include "frame.hpp"
#include "scene_3d.hpp"

class ErosionControlFrame : public Frame
{
private:
	WorldManipulator* worldManipulator;

	char seedBuf[256];

	void mainDraw() override;
	void sendUpdateSignal();
public:
	ErosionControlFrame(Scene3D *view, const std::string &name, WorldManipulator *worldManipulator);
};


#endif //PROC_GEN_OPENGL_EROSION_CONTROL_FRAME_HPP
