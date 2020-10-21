#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include "view/view.hpp"

View::View(Application* application, Window* window)
{
	this->application = application;
	this->window = window;
}

void View::draw()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame(getWindow()->getSDLWindow());
	ImGui::NewFrame();
	for (auto&& frame : frames)
	{
		frame->draw();
	}
}

View::~View()
{

}

Window *View::getWindow() const
{
	return window;
}