#include <iostream>
#include "view/main_scene_view.hpp"

MainSceneView::MainSceneView()
: camera(glm::radians(45.0f), 800 / 600, .1f, 100.0f)
{
	//todo temporary below
	float vertices[] =
		{
			//front face
			-.5f, .5f, .5f, //up left
			-.5f, -.5f, .5f, //down left
			.5f, -.5f, .5f, //down right
			.5f, .5f, .5f, //up right

			//back face
			-.5f, .5f, -.5f, //up left
			-.5f, -.5f, -.5f, //down left
			.5f, -.5f, -.5f, //down right
			.5f, .5f, -.5f, //up right
		};
	unsigned int indices[] =
		{
			0, 1, 3,
			1, 2, 3,

			4, 5, 7,
			5, 6, 7
		};
	addModel(std::make_shared<RenderedModel>(vertices, sizeof(vertices), indices, sizeof(indices), GL_STATIC_DRAW));
}

void MainSceneView::draw()
{
	View::draw();
	for (auto model : models)
	{
		model->draw(camera.getViewMatrix(), camera.getProjectionMatrix());
	}
}

void MainSceneView::render()
{
	View::render();
}

//todo this function leaks! some weird things with smart pointers going on
void MainSceneView::addModel(std::shared_ptr<RenderedModel> model)
{
	models.emplace_back(std::move(model));
}

