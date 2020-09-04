#include <model/square.hpp>
#include "controller/demo1.hpp"

Demo1::Demo1(const std::string &title, int height, int width)
: Application(title, height, width)
{
	world.addEntity(std::shared_ptr<Square>(new Square(Point(0, 0, 0), 10, 10)));
}

void Demo1::run()
{
	while (window.isOpen())
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
//		currentView->draw();
		window.render();
	}
}

