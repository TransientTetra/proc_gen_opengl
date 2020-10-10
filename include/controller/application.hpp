#ifndef APPLICATION_HPP
#define APPLICATION_HPP


#include <string>
#include <memory>
#include <view/view.hpp>
#include "view/window.hpp"
#include "constants.hpp"
#include <chrono>

class Application
{
private:
protected:
	std::string title;
	Window window;

	std::unique_ptr<View> currentView;

	std::chrono::duration<double> lastFrameDuration;

public:
	Application(std::string title, int height, int width);

	virtual void run() = 0;
	virtual void processEvents() = 0;

	std::chrono::duration<double> getLastFrameDuration();
	Window* getWindow();

};


#endif //APPLICATION_HPP
