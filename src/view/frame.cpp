#include <imgui/backends/imgui_impl_opengl3.h>
#include "view/frame.hpp"
#include "view/view.hpp"

Frame::Frame(View* view, std::string name)
: name(name), flags(ImGuiWindowFlags_None), opacity(.5f)
{
	this->view = view;
	xPos = 0;
	yPos = 0;
}

Frame::Frame(View* view, std::string name, int xPos, int yPos)
: Frame(view, name)
{
	Frame::xPos = xPos;
	Frame::yPos = yPos;
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
	ImGui::SetNextWindowSize(ImVec2(width, height), ImGuiCond_Once);
	ImGui::SetNextWindowPos(ImVec2(xPos, yPos), ImGuiCond_Once);
	ImGui::SetNextWindowCollapsed(false, ImGuiCond_Once);
	ImGui::Begin(name.c_str(), nullptr, flags);
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
