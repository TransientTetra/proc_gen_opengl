#include <iostream>
#include <view/terrain_control_frame.hpp>
#include "view/demo1_main_scene.hpp"
#include "controller/application.hpp"
#include <view/opengl_interfacing/above_camera.hpp>
#include <view/opengl_interfacing/first_person_camera.hpp>
#include <view/camera_control_frame.hpp>

Demo1MainScene::Demo1MainScene(Application* application, Window* window,
			       WorldManipulator* modelManipulator, TerrainTranslator* terrainTranslator)
: TerrainModelsView(application, window, terrainTranslator)
{
	Demo1MainScene::terrainTranslator = terrainTranslator;
	setCamera(FPS_CAMERA);
	setCameraPosition(glm::vec3(0.0f, .5f, 0.0f));

	light = std::make_unique<Lightsource>(glm::vec3(4.0f, 1.0f, 10.0f), glm::vec3(1.0f, 1.0f, 1.0f));
//	terrain = std::make_unique<Mesh>(std::vector<Vertex>(), std::vector<unsigned int>(), GL_STATIC_DRAW, glm::vec3(.8f, .2f, .6f), light.get());
	terrain = std::make_unique<Mesh>(std::vector<Vertex>(), std::vector<unsigned int>(), GL_STATIC_DRAW, light.get(), glm::vec3(.376f, .502f, .22f));
	updateTerrain();

	frames.emplace_back(std::make_unique<TerrainControlFrame>(this, "Generation Control", modelManipulator));
	frames.emplace_back(std::make_unique<CameraControlFrame>(this, "Camera Control"));
  
	relativeMouseMode = true;
	SDL_SetRelativeMouseMode(SDL_TRUE);
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
				case SDLK_SPACE:
				case SDLK_UP:
					camera->startMovingUp();
					break;
				case SDLK_LCTRL:
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
				case SDLK_SPACE:
				case SDLK_UP:
					camera->stopMovingUp();
					break;
				case SDLK_LCTRL:
				case SDLK_DOWN:
					camera->stopMovingDown();
					break;
				case SDLK_ESCAPE:
					if (relativeMouseMode)
						SDL_SetRelativeMouseMode(SDL_FALSE);
					else
						SDL_SetRelativeMouseMode(SDL_TRUE);

					relativeMouseMode = !relativeMouseMode;
					break;
				default:
					break;
			}
			break;
		case SDL_MOUSEMOTION:
			if(relativeMouseMode)
			{
				if (event.motion.xrel)
					camera->rotateX(event.motion.xrel);

				if (event.motion.yrel)
					camera->rotateY(event.motion.yrel);
			}

			break;
	}
}

void Demo1MainScene::draw()
{
	TerrainModelsView::draw();
	camera->move(application->getLastFrameDuration().count());

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
