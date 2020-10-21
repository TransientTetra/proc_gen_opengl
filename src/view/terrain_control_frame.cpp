#include "view/terrain_control_frame.hpp"
#include "view/view.hpp"

TerrainControlFrame::TerrainControlFrame(TerrainModelsView *view, const std::string &name, WorldManipulator* worldManipulator)
: Frame(view, name), worldManipulator(worldManipulator)
{
	flags = ImGuiWindowFlags_NoResize;
	width = 500;
	height = 500;

	widthTerrain = 10;
	heightTerrain = 10;

	nVerticesSide = 256;
	scale = 1;
	horizontalScale = 50;
	nOctaves = 1;
	persistence = .5f;
	lacunarity = 2;

	currentAlgo = FLAT;
	seedBuf[0] = '\0';

	nWavesWidth = 1;
	nWavesHeight = 1;

	sendUpdateSignal();
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
	if (tempA != currentAlgo)
		sendUpdateSignal();
	ImGui::NewLine();

	ImGui::Text("Generation algorithm parameters");

	float tempF = widthTerrain;
	ImGui::SliderFloat("Width", &widthTerrain, 1, 1000);
	if (tempF != widthTerrain)
	{
		worldManipulator->setTerrainWidth(widthTerrain);
		dynamic_cast<TerrainModelsView*>(view)->updateTerrain();
	}

	tempF = heightTerrain;
	ImGui::SliderFloat("Height", &heightTerrain, 1, 1000);
	if (tempF != heightTerrain)
	{
		worldManipulator->setTerrainLength(heightTerrain);
		dynamic_cast<TerrainModelsView*>(view)->updateTerrain();
	}

	int tempI = nVerticesSide;
	ImGui::SliderInt("N vertices per side", &nVerticesSide, 2, 1024);
	if (tempI != nVerticesSide)
		sendUpdateSignal();

	tempF = scale;
	ImGui::SliderFloat("Scale", &scale, 0, 10);
	if (tempF != scale)
	{
		worldManipulator->setTerrainScale(scale);
		dynamic_cast<TerrainModelsView*>(view)->updateTerrain();
	}

	if (currentAlgo == PERLIN_NOISE)
	{
		tempF = horizontalScale;
		ImGui::SliderFloat("Horizontal scale", &horizontalScale, 1.f, 100.f);
		if (tempF != horizontalScale)
			sendUpdateSignal();

		tempF = persistence;
		ImGui::SliderFloat("Persistence", &persistence, 0, 1);
		if (tempF != persistence)
			sendUpdateSignal();

		tempF = lacunarity;
		ImGui::SliderFloat("Lacunarity", &lacunarity, 1.f, 10.f);
		if (tempF != lacunarity)
			sendUpdateSignal();
	}

	if (currentAlgo == WHITE_NOISE or currentAlgo == PERLIN_NOISE)
	{
		tempI = nOctaves;
		ImGui::SliderInt("N octaves", &nOctaves, 1, 10);
		if (tempI != nOctaves)
			sendUpdateSignal();

		ImGui::Text("Noise seed");
		if (ImGui::InputText("", seedBuf, sizeof(seedBuf) / sizeof(char)))
		{
			sendUpdateSignal();
		}
	}
	if (currentAlgo == SINUSOIDAL)
	{
		tempI = nWavesWidth;
		ImGui::SliderInt("N waves width", &nWavesWidth, 1, 10);
		if (tempI != nWavesWidth)
			sendUpdateSignal();

		tempI = nWavesHeight;
		ImGui::SliderInt("N waves height", &nWavesHeight, 1, 10);
		if (tempI != nWavesHeight)
			sendUpdateSignal();
	}
}

void TerrainControlFrame::sendUpdateSignal()
{
	worldManipulator->setTerrainAlgorithm(currentAlgo, std::string(seedBuf),
					      nVerticesSide, horizontalScale,
					      nOctaves, persistence, lacunarity,
					      nWavesWidth, nWavesHeight);
	dynamic_cast<TerrainModelsView*>(view)->updateTerrain();
}

