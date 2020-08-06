#ifndef CPP_GUI_TEMPLATE_VIEW_HPP
#define CPP_GUI_TEMPLATE_VIEW_HPP


#include <vector>
#include <view/frame.hpp>

class View
{
protected:
	std::vector<Frame> frames;
public:
	View();
	//draw has to be called at the start of the overridden method
	virtual void draw();
	//render has to be called at the end of the overridden method
	virtual void render();
};


#endif //CPP_GUI_TEMPLATE_VIEW_HPP
