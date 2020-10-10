#include <iostream>
#include <sys/time.h>
#include "controller/application.hpp"

//long int Application::lastTimestamp = Application::getCurrentTime();

Application::Application(std::string title, int height, int width)
: window(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width)
{
	this->title = title;
	lastFrameDuration = std::chrono::duration<double>(1.0);
}

std::chrono::duration<double> Application::getLastFrameDuration()
{
	return lastFrameDuration;
}

Window *Application::getWindow()
{
	return &window;
}
