#ifndef APPLICATION_HPP
#define APPLICATION_HPP


#include <string>
#include <memory>
#include "view/window.hpp"
#include "constants.hpp"
#include "view/view.hpp"

class Application
{
private:
protected:
	std::string title;
	Window window;
	std::unique_ptr<View> currentView;
public:
	Application(std::string title, int height, int width);

	virtual void run() = 0;
};


#endif //APPLICATION_HPP
