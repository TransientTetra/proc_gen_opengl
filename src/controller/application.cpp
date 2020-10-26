#include <iostream>
#include "controller/application.hpp"

Application::Application(std::string title, int height, int width)
: window(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width)
{
	this->title = title;
	lastFrameDuration = std::chrono::duration<double>(1.0);
}

double Application::getLastFrameDuration()
{
	return lastFrameDuration.count();
}

Window *Application::getWindow()
{
	return &window;
}
