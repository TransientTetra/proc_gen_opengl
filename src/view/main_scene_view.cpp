#include <iostream>
#include "view/main_scene_view.hpp"
#include "controller/application.hpp"
#include <view/opengl_interfacing/above_camera.hpp>
#include <view/opengl_interfacing/first_person_camera.hpp>



MainSceneView::MainSceneView(Application* application)
: View(application)
{
	camera = std::make_unique<FirstPersonCamera>(glm::radians(45.0f), 800 / 600, .1f, 100.0f, 2.8f);
//	camera = std::make_unique<AboveCamera>(glm::radians(45.0f), 800 / 600, .1f, 100.0f, 2.8f);
	camera->setPosition(glm::vec3(0.0f, 3.0f, 0.0f));

	firstMouse = true;
	relativeMouseMode = true;
	if(relativeMouseMode)
	{
		SDL_SetRelativeMouseMode(SDL_TRUE);
	}
	else
	{
		SDL_SetRelativeMouseMode(SDL_FALSE);
	}

	yaw = .0f;
	pitch = .0f;
}

void MainSceneView::processEvents(SDL_Event &event)
{
	float xpos = 400.0f, ypos = 300.0f;

	switch(event.type) {
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym){
				case SDLK_a:
					camera->startMovingLeft();
					break;
				case SDLK_d:
					camera->startMovingRight();
					break;
				case SDLK_w:
					camera->startMovingForward();
					break;
				case SDLK_s:
					camera->startMovingBackward();
					break;
				case SDLK_UP:
					camera->startMovingUp();
					break;
				case SDLK_DOWN:
					camera->startMovingDown();
					break;
				default:
					break;
			}
			break;
		case SDL_KEYUP:
			switch(event.key.keysym.sym){
				case SDLK_a:
					camera->stopMovingLeft();
					break;
				case SDLK_d:
					camera->stopMovingRight();
					break;
				case SDLK_w:
					camera->stopMovingForward();
					break;
				case SDLK_s:
					camera->stopMovingBackward();
					break;
				case SDLK_UP:
					camera->stopMovingUp();
					break;
				case SDLK_DOWN:
					camera->stopMovingDown();
					break;
				case SDLK_ESCAPE:
					if(relativeMouseMode)
					{
						SDL_SetRelativeMouseMode(SDL_FALSE);
						relativeMouseMode = false;
					}
					else
					{
						SDL_SetRelativeMouseMode(SDL_TRUE);
						relativeMouseMode = true;
					}

				default:
					break;
			}
			break;
		case SDL_MOUSEMOTION:

			float xoffset = event.motion.xrel;
			float yoffset = event.motion.yrel;
			xpos += xoffset;
			ypos += yoffset;

//			printf("offset (xoffset = %f, yoffset = %f)\n", xoffset, yoffset);

			const float sensitivity = 0.1f;
			xoffset *= sensitivity;
			yoffset *= sensitivity;

			yaw += xoffset;
			pitch += yoffset;

			if(pitch > 89.0f)
				pitch = 89.0f;
			if(pitch < -89.0f)
				pitch = -89.0f;

			glm::vec3 direction;
			direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
			direction.y = sin(glm::radians(pitch));
			direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

			// TODO this up vector is shit
			glm::vec3 directionNorm = glm::normalize(direction);
			glm::vec3 cameraRight = glm::normalize(glm::cross(camera->getUp(), directionNorm));
//			glm::vec3 cameraRight = glm::normalize(glm::cross(camera->getUp(), directionNorm));
			glm::vec3 cameraUp = glm::cross(directionNorm, cameraRight);
			camera->setDirection(directionNorm, cameraUp);

			printf("rotation (pitch = %f, yaw = %f)\n", pitch, yaw);

			break;
	}
}


void MainSceneView::draw()
{
	View::draw();

	camera->move(application->getLastFrameDuration().count());

	for (auto&& model : models)
	{
		model->draw(camera->getViewMatrix(), camera->getProjectionMatrix());
	}
}

void MainSceneView::render()
{
	View::render();
}

//todo this function leaks! some weird things with smart pointers going on
void MainSceneView::addModel(std::unique_ptr<Mesh> model)
{
	models.emplace_back(std::move(model));
}

MainSceneView::~MainSceneView()
{

}
