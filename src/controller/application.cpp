#include <iostream>
#include <sys/time.h>
#include "controller/application.hpp"

long int Application::lastTimestamp = Application::getCurrentTime();

Application::Application(std::string title, int height, int width)
: window(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width)
{
	title = title;
}

float Application::getFrameTime()
{
	long int timestamp = getCurrentTime();
	long int diff = timestamp - lastTimestamp;
	lastTimestamp = timestamp;

	return diff / 1000.0f;
}

long int Application::getCurrentTime()
{
	struct timeval tp;
	gettimeofday(&tp, NULL);
	long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	return ms;
}