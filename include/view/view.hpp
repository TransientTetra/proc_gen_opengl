#ifndef CPP_GUI_TEMPLATE_VIEW_HPP
#define CPP_GUI_TEMPLATE_VIEW_HPP


#include <vector>
#include <view/frame.hpp>
#include <view/opengl_interfacing/camera.hpp>

class View
{
protected:
	std::vector<Frame> frames;

    Camera* camera;
public:
    View();

    virtual void processEvents(SDL_Event& event) = 0;
	//draw has to be called at the start of the overridden method
	virtual void draw();
	//render has to be called at the end of the overridden method
	virtual void render();
};


#endif //CPP_GUI_TEMPLATE_VIEW_HPP
