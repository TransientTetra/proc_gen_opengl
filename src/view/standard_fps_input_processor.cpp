#include "view/standard_fps_input_processor.hpp"

StandardFPSInputProcessor::StandardFPSInputProcessor(CameraController *cameraController)
: cameraController(cameraController)
{
	relativeMouseMode = true;
	SDL_SetRelativeMouseMode(SDL_TRUE);
}

void StandardFPSInputProcessor::processInput(SDL_Event &event)
{
	switch(event.type) {
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym){
				case SDLK_a:
					cameraController->startMoveLeft();
					break;
				case SDLK_d:
					cameraController->startMoveRight();
					break;
				case SDLK_w:
					cameraController->startMoveForward();
					break;
				case SDLK_s:
					cameraController->startMoveBackward();
					break;
				case SDLK_SPACE:
				case SDLK_UP:
					cameraController->startMoveUp();
					break;
				case SDLK_LCTRL:
				case SDLK_DOWN:
					cameraController->startMoveDown();
					break;
				default:
					break;
			}
			break;
		case SDL_KEYUP:
			switch(event.key.keysym.sym){
				case SDLK_a:
					cameraController->stopMoveLeft();
					break;
				case SDLK_d:
					cameraController->stopMoveRight();
					break;
				case SDLK_w:
					cameraController->stopMoveForward();
					break;
				case SDLK_s:
					cameraController->stopMoveBackward();
					break;
				case SDLK_SPACE:
				case SDLK_UP:
					cameraController->stopMoveUp();
					break;
				case SDLK_LCTRL:
				case SDLK_DOWN:
					cameraController->stopMoveDown();
					break;
				case SDLK_ESCAPE:
					if (relativeMouseMode)
						SDL_SetRelativeMouseMode(SDL_FALSE);
					else
						SDL_SetRelativeMouseMode(SDL_TRUE);

					relativeMouseMode = !relativeMouseMode;
					break;
				default:
					break;
			}
			break;
		case SDL_MOUSEMOTION:
//			if(relats

			break;
	}
}

void StandardFPSInputProcessor::setCameraController(CameraController *cameraController)
{
	StandardFPSInputProcessor::cameraController = cameraController;
}
