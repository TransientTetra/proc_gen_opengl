#include <memory>
#include <view/opengl_interfacing/vertex_shader.hpp>
#include <view/opengl_interfacing/mesh.hpp>
#include <view/demo1_main_scene.hpp>
#include <iostream>
#include <controller/entity_translator.hpp>
#include "controller/demo1.hpp"

Demo1::Demo1(const std::string &title, int height, int width)
: Application(title, height, width), worldManipulator(&world), terrainTranslator(world.getTerrain().get())
{
	//todo change default first view once menu or something is devised
	currentView = std::make_unique<Demo1MainScene>(this, &window, &worldManipulator, &terrainTranslator);

	EntityTranslator e;
	for (auto entity : world.getEntities())
	{
		dynamic_cast<Demo1MainScene*>(currentView.get())->addModel(
			std::make_unique<Mesh>(e.getVertices(*entity), e.getIndices(*entity), GL_STATIC_DRAW));
	}
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


