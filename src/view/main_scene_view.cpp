#include <iostream>
#include <chrono>
#include "view/main_scene_view.hpp"

MainSceneView::MainSceneView()
: View()
{
	camera = new AboveCamera(glm::radians(45.0f), 800 / 600, .1f, 100.0f, 0.05f);
	camera->setPosition(glm::vec3(0.0f, 3.0f, 0.0f));

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

			//up face
			-.5f, .5f, -.5f, //up left
			-.5f, .5f, .5f, //down left
			.5f, .5f, .5f, //down right
			.5f, .5f, -.5f, //up right

			//down face
			-.5f, -.5f, -.5f, //up left
			-.5f, -.5f, .5f, //down left
			.5f, -.5f, .5f, //down right
			.5f, -.5f, -.5f, //up right
		};
	unsigned int indices[] =
		{
			0, 1, 3,
			1, 2, 3,

			4, 5, 7,
			5, 6, 7,

			8, 9, 11,
			11, 9, 10,

			12, 13, 15,
			15, 13, 14
		};
	addModel(std::make_shared<Mesh>(vertices, sizeof(vertices), indices, sizeof(indices), GL_STATIC_DRAW));
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

	for (auto model : models)
	{
		model->draw(camera->getViewMatrix(), camera->getProjectionMatrix());
		//todo remove below demo
//		model->rotate(glm::radians(2.f), glm::vec3(1, 0, 1));
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
