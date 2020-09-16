#include <iostream>
#include <chrono>
#include "view/main_scene_view.hpp"

MainSceneView::MainSceneView()
    : View()
{
    camera = new AboveCamera(glm::radians(45.0f), 800 / 600, .1f, 100.0f, 0.05f);
    camera->setPosition(glm::vec3(1.0f, .0f, 4.0f));
    camera->setDirection(camera->getPosition() + camera->getForward());

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
	addModel(std::make_shared<Mesh>(vertices, sizeof(vertices), indices, sizeof(indices), GL_STATIC_DRAW));
}

void MainSceneView::processEvents(SDL_Event &event)
{
    switch(event.type) {
        case SDL_KEYDOWN:
            switch( event.key.keysym.sym ){
                case SDLK_a:
                    ((AboveCamera*)camera)->moveHorizontally(true);
                    break;
                case SDLK_d:
                    ((AboveCamera*)camera)->moveHorizontally(false);
                    break;
                case SDLK_w:
                    ((AboveCamera*)camera)->moveVertically(true);
                    break;
                case SDLK_s:
                    ((AboveCamera*)camera)->moveVertically(false);
                    break;
                case SDLK_UP:
                    ((AboveCamera*)camera)->moveDeeper(true);
                    break;
                case SDLK_DOWN:
                    ((AboveCamera*)camera)->moveDeeper(false);
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
	for (auto model : models)
	{
		model->draw(camera->getViewMatrix(), camera->getProjectionMatrix());
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
