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
	camera->setPosition(glm::vec3(0.0f, .5f, 0.0f));
}

void MainSceneView::processEvents(SDL_Event &event)
{
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
					camera->toggleMouseRelativity();
					break;
				default:
					break;
			}
			break;
		case SDL_MOUSEMOTION:
			camera->rotate(event.motion.xrel, event.motion.yrel);
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
