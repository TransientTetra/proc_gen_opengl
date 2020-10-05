#ifndef APPLICATION_HPP
#define APPLICATION_HPP


#include <string>
#include <memory>
#include <view/view.hpp>
#include "view/window.hpp"
#include "constants.hpp"

class Application
{
private:
protected:
	std::string title;
	Window window;

	std::unique_ptr<View> currentView;

	static long int lastTimestamp;
	static long int getCurrentTime();

public:
	Application(std::string title, int height, int width);

	virtual void run() = 0;
	virtual void processEvents() = 0;

	static float getFrameTime();

};


#endif //APPLICATION_HPP
