#include "view/terrain_control_frame.hpp"

TerrainControlFrame::TerrainControlFrame(View *view, const std::string &name)
: Frame(view, name)
{}

void TerrainControlFrame::mainDraw()
{
	ImGui::SetWindowSize(ImVec2(220 * 3, 330));
	ImGui::Text("Sending progress");
}

