#include <iostream>
#include <view/terrain_control_frame.hpp>
#include "view/demo1_main_scene.hpp"
#include "controller/application.hpp"

Demo1MainScene::Demo1MainScene(Application* application, Window* window,
			       WorldManipulator* modelManipulator, TerrainTranslator* terrainTranslator)
: View(application, window)
{
	Demo1MainScene::terrainTranslator = terrainTranslator;
	camera = std::make_unique<AboveCamera>(glm::radians(45.0f), 800 / 600, .1f, 100.0f, 2.8f);
	camera->setPosition(glm::vec3(0.0f, 3.0f, 0.0f));

	frames.emplace_back(std::make_unique<TerrainControlFrame>(this, "Generation Control", modelManipulator));

	terrain = std::make_unique<Mesh>(std::vector<Vertex>(), std::vector<unsigned int>(), GL_STATIC_DRAW);
	terrainTranslator->updateMesh(terrain.get());
}

void Demo1MainScene::processEvents(SDL_Event &event)
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

void Demo1MainScene::draw()
{
	View::draw();
	camera->move(application->getLastFrameDuration().count());

	terrainTranslator->updateMesh(terrain.get());
	terrain->draw(camera->getViewMatrix(), camera->getProjectionMatrix());
	for (auto&& model : models)
	{
		model->draw(camera->getViewMatrix(), camera->getProjectionMatrix());
	}

}

void Demo1MainScene::addModel(std::unique_ptr<Mesh> model)
{
	models.emplace_back(std::move(model));
}

Demo1MainScene::~Demo1MainScene()
{

}