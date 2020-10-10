#include <imgui/examples/imgui_impl_opengl3.h>
#include "view/frame.hpp"
#include "view/view.hpp"

Frame::Frame(View* view, std::string name)
: name(name)
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
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame(view->getWindow()->getSDLWindow());
	ImGui::NewFrame();
	ImGui::Begin(name.c_str());
}

void Frame::endDraw()
{
	ImGui::End();
	ImGui::EndFrame();
}
