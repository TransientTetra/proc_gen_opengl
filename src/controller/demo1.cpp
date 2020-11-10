#include <memory>
#include <model/opengl_interfacing/vertex_shader.hpp>
#include <model/opengl_interfacing/mesh.hpp>
#include <view/demo1_main_scene.hpp>
#include <iostream>
#include "controller/demo1.hpp"

Demo1::Demo1(const std::string &title, int height, int width)
: Application(title, height, width), worldManipulator(&world)
{
	//todo change default first view once menu or something is devised
	currentView = std::make_unique<Demo1MainScene>(this, &window, &worldManipulator, world.getTerrain().get());
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


