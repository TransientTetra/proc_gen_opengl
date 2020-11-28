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
	int xPos;
	int yPos;

	void beginDraw();
	virtual void mainDraw() = 0;
	void endDraw();
public:
	Frame(View* view, std::string name);
	Frame(View* view, std::string name, int xPos, int yPos);
	virtual void draw() final;

	void setOpacity(float opacity);

	int getHeight() const;

	void setHeight(int height);

	int getWidth() const;

	void setWidth(int width);
};


#endif //SAFE_SENDER_FRAME_HPP
