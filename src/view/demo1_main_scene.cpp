#include <iostream>
#include <view/terrain_control_frame.hpp>
#include "view/demo1_main_scene.hpp"
#include "controller/application.hpp"
#include <view/camera_control_frame.hpp>

Demo1MainScene::Demo1MainScene(Application* application, Window* window,
			       WorldManipulator* modelManipulator, Terrain* terrain)
: Scene3D(application, window, terrain), inputProcessor(cameraController.get())
{
	light = std::make_unique<LightSource>(glm::vec3(4.0f, 1.0f, 10.0f), glm::vec3(1.0f, 1.0f, 1.0f));

	frames.emplace_back(std::make_unique<TerrainControlFrame>(this, "Generation Control", modelManipulator));
	frames.emplace_back(std::make_unique<CameraControlFrame>(this, "Camera Control"));
}

void Demo1MainScene::processEvents(SDL_Event &event)
{
	inputProcessor.setCameraController(cameraController.get());
	inputProcessor.processKeyboardEvent(event);
	inputProcessor.processMouseEvent(event);
}

void Demo1MainScene::draw()
{
	inputProcessor.updateController(cameraController.get(), application->getLastFrameDuration());
	Scene3D::draw();

	terrain->getMesh()->draw(camera.getViewMatrix(), camera.getProjectionMatrix(), camera.getPosition(), *light);
	for (auto&& entity : entities)
	{
		entity->getMesh()->draw(camera.getViewMatrix(), camera.getProjectionMatrix(), camera.getPosition(), *light);
	}
}

Demo1MainScene::~Demo1MainScene()
{

}
