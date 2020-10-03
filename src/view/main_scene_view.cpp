#include <iostream>
#include <chrono>
#include "view/main_scene_view.hpp"

MainSceneView::MainSceneView()
: View()
{
	camera = new AboveCamera(glm::radians(45.0f), 800 / 600, .1f, 100.0f, 0.05f);
	camera->setPosition(glm::vec3(0.0f, 3.0f, 0.0f));

}

void MainSceneView::processEvents(SDL_Event &event)
{
	AboveCamera* aboveCamera = (AboveCamera*)camera;

	switch(event.type) {
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym){
				case SDLK_a:
					aboveCamera->setMovingLeft(true);
					break;
				case SDLK_d:
					aboveCamera->setMovingRight(true);
					break;
				case SDLK_w:
					aboveCamera->setMovingForward(true);
					break;
				case SDLK_s:
					aboveCamera->setMovingBackward(true);
					break;
				case SDLK_UP:
					aboveCamera->setMovingUp(true);
					break;
				case SDLK_DOWN:
					aboveCamera->setMovingDown(true);
					break;
				default:
					break;
			}
			break;
		case SDL_KEYUP:
			switch(event.key.keysym.sym){
				case SDLK_a:
					aboveCamera->setMovingLeft(false);
					break;
				case SDLK_d:
					aboveCamera->setMovingRight(false);
					break;
				case SDLK_w:
					aboveCamera->setMovingForward(false);
					break;
				case SDLK_s:
					aboveCamera->setMovingBackward(false);
					break;
				case SDLK_UP:
					aboveCamera->setMovingUp(false);
					break;
				case SDLK_DOWN:
					aboveCamera->setMovingDown(false);
					break;
				default:
					break;
			}
			break;
	}
}


void MainSceneView::draw()
{
	View::draw();

	camera->move();

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
