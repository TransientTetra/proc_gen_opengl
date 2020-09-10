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
#include "controller/demo1.hpp"

Demo1::Demo1(const std::string &title, int height, int width)
: Application(title, height, width)
{
	//todo temporary
	world.addEntity(std::shared_ptr<Square>(new Square(Point(0, 0, 0), 10, 10)));

	//todo change default first view once menu or something is devised
	currentView = std::make_unique<MainSceneView>();
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


