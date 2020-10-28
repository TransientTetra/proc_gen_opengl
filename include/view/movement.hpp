#ifndef PROC_GEN_OPENGL_MOVEMENT_HPP
#define PROC_GEN_OPENGL_MOVEMENT_HPP


#include <SDL2/SDL_events.h>
#include <SDL2/SDL.h>
#include "camera_controller.hpp"

class Movement
{
protected:
	CameraController* cameraController;
public:
	Movement(CameraController *cameraController);

	virtual void processKeyboardEvent(SDL_Event &e) = 0;
	virtual void processMouseEvent(SDL_Event &e) = 0;
	virtual void updateController(CameraController* cameraController, float deltaT) = 0;

	void setCameraController(CameraController *cameraController);
};


#endif //PROC_GEN_OPENGL_MOVEMENT_HPP
