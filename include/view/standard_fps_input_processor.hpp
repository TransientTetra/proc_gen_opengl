#ifndef PROC_GEN_OPENGL_STANDARD_FPS_INPUT_PROCESSOR_HPP
#define PROC_GEN_OPENGL_STANDARD_FPS_INPUT_PROCESSOR_HPP


#include "input_processor.hpp"
#include "camera_controller.hpp"

class StandardFPSInputProcessor : public InputProcessor
{
private:
	CameraController* cameraController;
	bool relativeMouseMode;
public:
	StandardFPSInputProcessor(CameraController *cameraController);

	void setCameraController(CameraController *cameraController);

	void processInput(SDL_Event &e) override;
};


#endif //PROC_GEN_OPENGL_STANDARD_FPS_INPUT_PROCESSOR_HPP
