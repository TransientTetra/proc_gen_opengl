#ifndef SAFE_SENDER_FRAME_HPP
#define SAFE_SENDER_FRAME_HPP


#include <string>
#include <imgui/imgui.h>
class View;

class Frame
{
private:
protected:
	View* view;
	std::string name;
	void beginDraw();
	virtual void mainDraw() = 0;
	void endDraw();
public:
	Frame(View* view, std::string name);
	virtual void draw();
};


#endif //SAFE_SENDER_FRAME_HPP
