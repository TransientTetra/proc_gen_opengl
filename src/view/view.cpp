#include "view/view.hpp"

View::View(Application* application)
{
	this->application = application;
}

void View::draw()
{
	for (Frame frame : frames)
	{
		frame.draw();
	}
}

void View::render()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

View::~View()
{

}