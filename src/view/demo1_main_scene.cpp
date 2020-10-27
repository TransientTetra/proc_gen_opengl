#include <iostream>
#include <view/terrain_control_frame.hpp>
#include "view/demo1_main_scene.hpp"
#include "controller/application.hpp"
#include <view/camera_control_frame.hpp>

Demo1MainScene::Demo1MainScene(Application* application, Window* window,
			       WorldManipulator* modelManipulator, TerrainTranslator* terrainTranslator)
: TerrainModelsView(application, window, terrainTranslator)
{
	Demo1MainScene::terrainTranslator = terrainTranslator;

	light = std::make_unique<Lightsource>(glm::vec3(4.0f, 1.0f, 10.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	terrain = std::make_unique<Mesh>(std::vector<Vertex>(), std::vector<unsigned int>(), GL_STATIC_DRAW, glm::vec3(.376f, .502f, .22f), light.get());
	updateTerrain();

	frames.emplace_back(std::make_unique<TerrainControlFrame>(this, "Generation Control", modelManipulator));
	frames.emplace_back(std::make_unique<CameraControlFrame>(this, "Camera Control"));
}

void Demo1MainScene::processEvents(SDL_Event &event)
{
	inputProcessor.processInput(event);
}

void Demo1MainScene::draw()
{
	inputProcessor.updateController(cameraController.get(), application->getLastFrameDuration());
	TerrainModelsView::draw();

	terrain->draw(camera.getViewMatrix(), camera.getProjectionMatrix());
	for (auto&& model : models)
	{
		model->draw(camera.getViewMatrix(), camera.getProjectionMatrix());
	}
}

void Demo1MainScene::addModel(std::unique_ptr<Mesh> model)
{
	models.emplace_back(std::move(model));
}

Demo1MainScene::~Demo1MainScene()
{

}
