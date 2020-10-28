#ifndef PROC_GEN_OPENGL_STANDARD_FPS_MOVEMENT_HPP
#define PROC_GEN_OPENGL_STANDARD_FPS_MOVEMENT_HPP


#include <string>
#include <map>
#include "movement.hpp"
#include "camera_controller.hpp"

class StandardFPSMovement : public Movement
{
private:
	bool relativeMouseMode;
	float speedMultiplier;
	float mouseDelta;

	std::map<SDL_KeyCode, bool> keyPressed;
public:
	StandardFPSMovement(CameraController *cameraController);

	void processKeyboardEvent(SDL_Event &e) override;

	void processMouseEvent(SDL_Event &e) override;

	void updateController(CameraController *cameraController, float deltaT) override;
};


#endif //PROC_GEN_OPENGL_STANDARD_FPS_MOVEMENT_HPP
