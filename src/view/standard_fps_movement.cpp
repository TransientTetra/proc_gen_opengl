#include "view/standard_fps_movement.hpp"

StandardFPSMovement::StandardFPSMovement(CameraController *cameraController)
: Movement(cameraController)
{
	mouseSensitivity = .005f;
	speedMultiplier = 3;
	relativeMouseMode = false;
	keyPressed[SDLK_w] = false;
	keyPressed[SDLK_a] = false;
	keyPressed[SDLK_s] = false;
	keyPressed[SDLK_d] = false;
	keyPressed[SDLK_SPACE] = false;
	keyPressed[SDLK_LSHIFT] = false;
	keyPressed[SDLK_LCTRL] = false;
	keyPressed[SDLK_UP] = false;
	keyPressed[SDLK_DOWN] = false;
	keyPressed[SDLK_LEFT] = false;
	keyPressed[SDLK_RIGHT] = false;}


void StandardFPSMovement::processKeyboardEvent(SDL_Event &event)
{
	switch (event.type)
	{
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
				case SDLK_a:
					keyPressed[SDLK_a] = true;
					break;
				case SDLK_d:
					keyPressed[SDLK_d] = true;
					break;
				case SDLK_w:
					keyPressed[SDLK_w] = true;
					break;
				case SDLK_s:
					keyPressed[SDLK_s] = true;
					break;
				case SDLK_UP:
					keyPressed[SDLK_UP] = true;
					break;
				case SDLK_DOWN:
					keyPressed[SDLK_DOWN] = true;
					break;
				case SDLK_LEFT:
					keyPressed[SDLK_LEFT] = true;
					break;
				case SDLK_RIGHT:
					keyPressed[SDLK_RIGHT] = true;
					break;
				case SDLK_SPACE:
					keyPressed[SDLK_SPACE] = true;
					break;
				case SDLK_LCTRL:
					keyPressed[SDLK_LCTRL] = true;
					break;
				case SDLK_LSHIFT:
					keyPressed[SDLK_LSHIFT] = true;
					break;
				default:
					break;
			}
			break;
		case SDL_KEYUP:
			switch(event.key.keysym.sym)
			{
				case SDLK_a:
					keyPressed[SDLK_a] = false;
					break;
				case SDLK_d:
					keyPressed[SDLK_d] = false;
					break;
				case SDLK_w:
					keyPressed[SDLK_w] = false;
					break;
				case SDLK_s:
					keyPressed[SDLK_s] = false;
					break;
				case SDLK_UP:
					keyPressed[SDLK_UP] = false;
					break;
				case SDLK_DOWN:
					keyPressed[SDLK_DOWN] = false;
					break;
				case SDLK_LEFT:
					keyPressed[SDLK_LEFT] = false;
					break;
				case SDLK_RIGHT:
					keyPressed[SDLK_RIGHT] = false;
					break;
				case SDLK_SPACE:
					keyPressed[SDLK_SPACE] = false;
					break;
				case SDLK_LCTRL:
					keyPressed[SDLK_LCTRL] = false;
					break;
				case SDLK_LSHIFT:
					keyPressed[SDLK_LSHIFT] = false;
					break;
				case SDLK_ESCAPE:
					if (relativeMouseMode)
					{
						relativeMouseMode = false;
						SDL_SetRelativeMouseMode(SDL_FALSE);
					}
					else
					{
						relativeMouseMode = true;
						SDL_SetRelativeMouseMode(SDL_TRUE);
					}
				default:
					break;
			}
			break;
	}
}

void StandardFPSMovement::updateController(CameraController *cameraController, float deltaT)
{
	if (keyPressed[SDLK_LSHIFT])
	{
		deltaT *= speedMultiplier;
	}
	if (keyPressed[SDLK_w])
	{
		cameraController->moveForward(deltaT);
	}
	if (keyPressed[SDLK_a])
	{
		cameraController->moveLeft(deltaT);
	}
	if (keyPressed[SDLK_s])
	{
		cameraController->moveBackward(deltaT);
	}
	if (keyPressed[SDLK_d])
	{
		cameraController->moveRight(deltaT);
	}
	if (keyPressed[SDLK_SPACE] or keyPressed[SDLK_UP])
	{
		cameraController->moveUp(deltaT);
	}
	if (keyPressed[SDLK_LCTRL] or keyPressed[SDLK_DOWN])
	{
		cameraController->moveDown(deltaT);
	}
}

void StandardFPSMovement::processMouseEvent(SDL_Event &event)
{
	switch (event.type)
	{
		case SDL_MOUSEMOTION:
			if(relativeMouseMode)
			{
				if (event.motion.xrel)
				{
					if (event.motion.xrel > 0)
						cameraController->yawRight(mouseSensitivity);
					if (event.motion.xrel < 0)
						cameraController->yawLeft(mouseSensitivity);
				}
				if (event.motion.yrel)
				{
					if (event.motion.yrel < 0)
						cameraController->pitchUp(mouseSensitivity);
					if (event.motion.yrel > 0)
						cameraController->pitchDown(mouseSensitivity);
				}
			}
			break;
	}
}
