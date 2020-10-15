#ifndef SAFE_SENDER_FRAME_HPP
#define SAFE_SENDER_FRAME_HPP


#include <string>
#include <imgui/imgui.h>
class View;

class Frame
{
protected:
	View* view;
	std::string name;

	int flags;
	float opacity;
	int height;
	int width;

	void beginDraw();
	virtual void mainDraw() = 0;
	void endDraw();
public:
	Frame(View* view, std::string name);
	virtual void draw();

	void setOpacity(float opacity);

	int getHeight() const;

	void setHeight(int height);

	int getWidth() const;

	void setWidth(int width);
};


#endif //SAFE_SENDER_FRAME_HPP
