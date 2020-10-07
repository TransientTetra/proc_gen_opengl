#include <memory>
#include <model/square.hpp>
#include <view/opengl_interfacing/vertex_shader.hpp>
#include <view/opengl_interfacing/fragment_shader.hpp>
#include <view/opengl_interfacing/vao.hpp>
#include <view/opengl_interfacing/vbo.hpp>
#include <view/opengl_interfacing/shader_program.hpp>
#include <view/opengl_interfacing/ebo.hpp>
#include <view/opengl_interfacing/mesh.hpp>
#include <view/main_scene_view.hpp>
#include <iostream>
#include <controller/entity_translator.hpp>
#include <controller/terrain_translator.hpp>
#include "controller/demo1.hpp"

Demo1::Demo1(const std::string &title, int height, int width)
	: Application(title, height, width)
{
	//todo temporary
	world.addEntity(std::shared_ptr<Cube>(new Cube(glm::vec3(0, 0, 0), 3, 3, 3)));
	world.setTerrain(std::make_unique<Terrain>(8, 10));

	//todo change default first view once menu or something is devised
	currentView = std::make_unique<MainSceneView>(this);

	EntityTranslator e;
	for (auto entity : world.getEntities())
	{
		dynamic_cast<MainSceneView*>(currentView.get())->addModel(std::make_unique<Mesh>(e.getVertices(*entity), e.getIndices(*entity), GL_STATIC_DRAW));
	}

	TerrainTranslator t;
	dynamic_cast<MainSceneView*>(currentView.get())->addModel(std::make_unique<Mesh>(t.getVertices(*world.getTerrain()), t.getIndices(*world.getTerrain()), GL_STATIC_DRAW));
}

void Demo1::processEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		ImGui_ImplSDL2_ProcessEvent(&event);
		bool quit = (event.type == SDL_QUIT);
		quit |= (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE
			 && event.window.windowID == SDL_GetWindowID(window.getSDLWindow()));
		if (quit)
		{
			window.setClose();
		}

		currentView->processEvents(event);
	}
}

void Demo1::run()
{
	while (window.isOpen())
	{
		auto start = std::chrono::high_resolution_clock::now();
		processEvents();

		window.updateViewportAndClear();

		currentView->draw();

		window.render();

		auto end = std::chrono::high_resolution_clock::now();
		lastFrameDuration = end - start;
	}
}


