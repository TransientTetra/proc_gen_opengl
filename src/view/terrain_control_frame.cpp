#include "view/terrain_control_frame.hpp"
#include "view/view.hpp"

TerrainControlFrame::TerrainControlFrame(View *view, const std::string &name)
: Frame(view, name)
{
	flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse;
	width = 400;
	height = 500;

	widthTerrain = 10;
	heightTerrain = 10;

	nVerticesHeight = 256;
	nVerticesWidth = 256;
	scale = 1;
	horizontalScale = 50;
	nOctaves = 1;
	persistence = .5f;
	lacunarity = 2;

	currentAlgo = FLAT;
}

void TerrainControlFrame::mainDraw()
{
	ImGui::SetWindowSize(ImVec2(width, height));

	ImGui::Text("Generation algorithm");
	GenerationAlgorithm tempA = currentAlgo;
	if (ImGui::RadioButton("Flat", currentAlgo == FLAT)) currentAlgo = FLAT;
	if (ImGui::RadioButton("White Noise", currentAlgo == WHITE_NOISE)) currentAlgo = WHITE_NOISE;
	if (ImGui::RadioButton("Sinusoidal", currentAlgo == SINUSOIDAL)) currentAlgo = SINUSOIDAL;
	if (ImGui::RadioButton("Perlin Noise", currentAlgo == PERLIN_NOISE)) currentAlgo = PERLIN_NOISE;
//	if (tempA != currentAlgo)
//		worldManipulator->setTerrainAlgorithm(currentAlgo);
	ImGui::NewLine();

	ImGui::Text("Generation algorithm parameters");
	float tempW = widthTerrain;
	ImGui::SliderFloat("Width", &widthTerrain, 1, 1000);
//	if (tempW != widthTerrain)
//		worldManipulator->setTerrainWidth(widthTerrain);

	ImGui::SliderFloat("Height", &heightTerrain, 1, 1000);
	ImGui::SliderInt("N vertices width", &nVerticesWidth, 2, 1024);
	ImGui::SliderInt("N vertices height", &nVerticesHeight, 2, 1024);
	ImGui::SliderFloat("Scale", &scale, .1f, 10);
	if (currentAlgo == WHITE_NOISE or currentAlgo == PERLIN_NOISE)
	{
		ImGui::SliderFloat("Horizontal scale", &horizontalScale, 1.f, 100.f);
		ImGui::SliderInt("N octaves", &nOctaves, 1, 10);
		ImGui::SliderFloat("Persistence", &persistence, 0, 1);
		ImGui::SliderFloat("Lacunarity", &lacunarity, 1.f, 10.f);
	}
}

