#ifndef CPP_GUI_TEMPLATE_VIEW_HPP
#define CPP_GUI_TEMPLATE_VIEW_HPP

#include <memory>
#include <vector>
#include <view/opengl_interfacing/light_source.hpp>
#include "frame.hpp"
#include "view/window.hpp"

class Application;

class View
{
protected:
	std::vector<std::unique_ptr<Frame>> frames;
	Application* application;
	Window* window;
	std::unique_ptr<LightSource> light;

public:
	View(Application* application, Window* window);
	virtual ~View();

	virtual void processEvents(SDL_Event& event) = 0;
	//draw has to be called at the start of the overridden method
	virtual void draw();

	Window *getWindow() const;
};


#endif //CPP_GUI_TEMPLATE_VIEW_HPP
