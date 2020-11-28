#include "view/erosion_control_frame.hpp"

ErosionControlFrame::ErosionControlFrame(Scene3D *view, const std::string &name, int xPos, int yPos, WorldManipulator *worldManipulator)
: Frame(view, name, xPos, yPos), worldManipulator(worldManipulator)
{
	flags = ImGuiWindowFlags_NoResize;
	width = 700;
	height = 300;
	seedBuf[0] = '\0';

	nDroplets = 70000;

	dropletInertia = .1f;
	evaporateSpeed = .01f;
	depositSpeed = .3f;
	erosionSpeed = .3f;
	dropletRadius = 3;
}

void ErosionControlFrame::mainDraw()
{
	ImGui::Columns(1);


	ImGui::SliderInt("Number of droplets", reinterpret_cast<int*>(&nDroplets), 1, 200000);

	ImGui::SliderFloat("Droplet inertia", &dropletInertia, 0, 1);

	ImGui::SliderFloat("Droplet water evaporation rate", &evaporateSpeed, 0, 1);

	ImGui::SliderFloat("Sediment deposition rate", &depositSpeed, 0, 1);

	ImGui::SliderFloat("Erosion rate", &erosionSpeed, 0, 1);

	ImGui::SliderInt("Erosion brush size", reinterpret_cast<int*>(&dropletRadius), 0, 8);

	ImGui::NewLine();
	ImGui::Text("Erosion random seed");
	ImGui::InputText("", seedBuf, sizeof(seedBuf) / sizeof(char));

	ImGui::NewLine();
	if (ImGui::Button("Erode"))
		sendUpdateSignal();
}

void ErosionControlFrame::sendUpdateSignal()
{
	worldManipulator->erodeTerrainHydraulic(seedBuf, nDroplets, dropletInertia, evaporateSpeed, depositSpeed,
					 erosionSpeed, dropletRadius);
}
