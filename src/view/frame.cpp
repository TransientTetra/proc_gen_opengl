#include <imgui/examples/imgui_impl_opengl3.h>
#include "view/frame.hpp"
#include "view/view.hpp"

Frame::Frame(View* view, std::string name)
: name(name), open(true), flags(ImGuiWindowFlags_None), opacity(.5f)
{
	this->view = view;
}

void Frame::draw()
{
	beginDraw();
	mainDraw();
	endDraw();
}

void Frame::beginDraw()
{
	ImGui::SetNextWindowBgAlpha(opacity);
	ImGui::Begin(name.c_str(), &open, flags);
}

void Frame::endDraw()
{
	ImGui::End();
}

void Frame::setOpacity(float opacity)
{
	Frame::opacity = opacity;
}

int Frame::getHeight() const
{
	return height;
}

void Frame::setHeight(int height)
{
	Frame::height = height;
}

int Frame::getWidth() const
{
	return width;
}

void Frame::setWidth(int width)
{
	Frame::width = width;
}
