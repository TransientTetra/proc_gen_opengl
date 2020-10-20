#include "camera_control_frame.hpp"

CameraControlFrame::CameraControlFrame(CameraView *view, const std::string &name)
: Frame(view, name)
{
	flags = ImGuiWindowFlags_NoResize;
	width = 500;
	height = 500;

	//todo change below to static camera once added
	cameraType = FPS_CAMERA;

}

void CameraControlFrame::mainDraw()
{
	ImGui::SetWindowSize(ImVec2(width, height));
	ImGui::Text("Camera type");
//	ImGui::RadioButton("FPS camera", );

	ImGui::NewLine();
	ImGui::Text("Render mode");

	ImGui::NewLine();
	ImGui::Text("Current position");
	ImGui::Text("");

	ImGui::NewLine();
	ImGui::Text("Change position");
//	ImGui::InputText("Xpos");
//	ImGui::InputText("Ypos");
//	ImGui::InputText("Zpos");
	if (ImGui::Button("Teleport"))
	{

	}

	ImGui::NewLine();
	ImGui::Text("Mouse sensitivity");

	ImGui::NewLine();
	ImGui::Text("Field of view");

	ImGui::NewLine();
	ImGui::Text("Draw distance");
}
