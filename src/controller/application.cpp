#include <iostream>
#include "controller/application.hpp"
#include "constants.hpp"

Application::Application(std::string title, int height, int width)
: window(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width)
{
	this->title = title;
}
