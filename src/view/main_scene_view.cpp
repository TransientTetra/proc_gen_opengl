#include <iostream>
#include "view/main_scene_view.hpp"

MainSceneView::MainSceneView()
{
	vs.loadCompileShaderSource("assets/shaders/vertex/default_basic.glsl");
	fs.loadCompileShaderSource("assets/shaders/fragment/default_basic.glsl");

	program.attachVertexAndFragmentShaders(vs, fs);
	program.linkProgram();

	//todo temporary below
	float vertices[] =
		{
			-0.25f,  0.5f, 0.0f, // top right
			-0.25f, 0.25f, 0.0f, // bottom right
			-0.5f, 0.25f, 0.0f, // bottom left
			-0.5f,  0.5f, 0.0f  // top left
		};

	float vertices2[] =
		{
			0.25f,  0.5f, 0.0f, // top right
			0.25f, 0.25f, 0.0f, // bottom right
			0.5f, 0.25f, 0.0f, // bottom left
			0.5f,  0.5f, 0.0f  // top left
		};
	unsigned int indices[] =
		{
			0, 1, 3,
			1, 2, 3
		};
	addModel(std::make_shared<RenderedModel>(vertices, sizeof(vertices), indices, sizeof(indices), GL_STATIC_DRAW));
	addModel(std::make_shared<RenderedModel>(vertices2, sizeof(vertices2), indices, sizeof(indices), GL_STATIC_DRAW));
}

void MainSceneView::draw()
{
	View::draw();
	program.useProgram();
	for (auto model : models)
	{
		model->draw();
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

