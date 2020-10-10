#include <iostream>
#include <view/terrain_control_frame.hpp>
#include "view/main_scene_view.hpp"
#include "controller/application.hpp"

MainSceneView::MainSceneView(Application* application, Window* window)
: View(application, window)
{
	camera = std::make_unique<AboveCamera>(glm::radians(45.0f), 800 / 600, .1f, 100.0f, 2.8f);
	camera->setPosition(glm::vec3(0.0f, 3.0f, 0.0f));

	frames.emplace_back(std::make_unique<TerrainControlFrame>(this, "Generation Control"));
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
				default:
					break;
			}
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

void MainSceneView::addModel(std::unique_ptr<Mesh> model)
{
	models.emplace_back(std::move(model));
}

MainSceneView::~MainSceneView()
{

}
