#ifndef PROC_GEN_OPENGL_STANDARD_FPS_MOVEMENT_HPP
#define PROC_GEN_OPENGL_STANDARD_FPS_MOVEMENT_HPP


#include "movement.hpp"
#include "camera_controller.hpp"

class StandardFPSMovement : public Movement
{
private:
	bool relativeMouseMode;
public:
	StandardFPSMovement();

	void processInput(SDL_Event &e, CameraController *cameraController) override;
};


#endif //PROC_GEN_OPENGL_STANDARD_FPS_MOVEMENT_HPP
