#include <iostream>
#include <chrono>
#include "view/main_scene_view.hpp"

MainSceneView::MainSceneView()
: camera(glm::radians(45.0f), 800 / 600, .1f, 100.0f)
{
	//todo temporary below
	camera.setPosition(glm::vec3(.0f, .0f, 10.0f));
}

void MainSceneView::draw()
{
	View::draw();
	for (auto model : models)
	{
		model->draw(camera.getViewMatrix(), camera.getProjectionMatrix());
		//todo remove below demo
		model->rotate(glm::radians(2.f), glm::vec3(0, 1, 1));
	}
}

void MainSceneView::render()
{
	View::render();
}

//todo this function leaks! some weird things with smart pointers going on
void MainSceneView::addModel(std::shared_ptr<Mesh> model)
{
	models.emplace_back(std::move(model));
}

