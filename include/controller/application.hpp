#ifndef APPLICATION_HPP
#define APPLICATION_HPP


#include <string>
#include "view/window.hpp"
#include "constants.hpp"

class Application
{
private:
	std::string title;
	Window window;
protected:
public:
	Application(std::string title);

	void run();
};


#endif //APPLICATION_HPP
