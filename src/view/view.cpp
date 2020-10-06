#include "view/view.hpp"

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
