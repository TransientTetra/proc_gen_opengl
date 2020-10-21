#include "view/terrain_control_frame.hpp"
#include "view/view.hpp"

TerrainControlFrame::TerrainControlFrame(View *view, const std::string &name, WorldManipulator* worldManipulator)
: Frame(view, name), worldManipulator(worldManipulator)
{
	flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse;
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

	worldManipulator->setTerrainAlgorithm(currentAlgo, std::string(seedBuf),
					      nVerticesSide, horizontalScale,
					      nOctaves, persistence, lacunarity,
					      nWavesWidth, nWavesHeight);
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
	if (ImGui::RadioButton("Diamond Square", currentAlgo == DIAMOND_SQUARE)) currentAlgo = DIAMOND_SQUARE;
	if (tempA != currentAlgo)
		worldManipulator->setTerrainAlgorithm(currentAlgo, std::string(seedBuf),
						      nVerticesSide, horizontalScale,
						      nOctaves, persistence, lacunarity,
						      nWavesWidth, nWavesHeight);
	ImGui::NewLine();

	ImGui::Text("Generation algorithm parameters");

	float tempF = widthTerrain;
	ImGui::SliderFloat("Width", &widthTerrain, 1, 1000);
	if (tempF != widthTerrain)
		worldManipulator->setTerrainWidth(widthTerrain);

	tempF = heightTerrain;
	ImGui::SliderFloat("Height", &heightTerrain, 1, 1000);
	if (tempF != heightTerrain)
		worldManipulator->setTerrainLength(heightTerrain);

	int tempI = nVerticesSide;
	ImGui::SliderInt("N vertices per side", &nVerticesSide, 2, 1024);
	if (tempI != nVerticesSide)
		worldManipulator->setTerrainAlgorithm(currentAlgo, std::string(seedBuf),
						      nVerticesSide, horizontalScale,
						      nOctaves, persistence, lacunarity,
						      nWavesWidth, nWavesHeight);

	tempF = scale;
	ImGui::SliderFloat("Scale", &scale, 0, 10);
	if (tempF != scale)
		worldManipulator->setTerrainScale(scale);

	if (currentAlgo == PERLIN_NOISE)
	{
		tempF = horizontalScale;
		ImGui::SliderFloat("Horizontal scale", &horizontalScale, 1.f, 100.f);
		if (tempF != horizontalScale)
			worldManipulator->setTerrainAlgorithm(currentAlgo, std::string(seedBuf),
							      nVerticesSide, horizontalScale,
							      nOctaves, persistence, lacunarity,
							      nWavesWidth, nWavesHeight);

		tempF = persistence;
		ImGui::SliderFloat("Persistence", &persistence, 0, 1);
		if (tempF != persistence)
			worldManipulator->setTerrainAlgorithm(currentAlgo, std::string(seedBuf),
							      nVerticesSide, horizontalScale,
							      nOctaves, persistence, lacunarity,
							      nWavesWidth, nWavesHeight);

		tempF = lacunarity;
		ImGui::SliderFloat("Lacunarity", &lacunarity, 1.f, 10.f);
		if (tempF != lacunarity)
			worldManipulator->setTerrainAlgorithm(currentAlgo, std::string(seedBuf),
							      nVerticesSide, horizontalScale,
							      nOctaves, persistence, lacunarity,
							      nWavesWidth, nWavesHeight);
	}

	if (currentAlgo == WHITE_NOISE or currentAlgo == PERLIN_NOISE)
	{
		tempI = nOctaves;
		ImGui::SliderInt("N octaves", &nOctaves, 1, 10);
		if (tempI != nOctaves)
			worldManipulator->setTerrainAlgorithm(currentAlgo, std::string(seedBuf),
							      nVerticesSide, horizontalScale,
							      nOctaves, persistence, lacunarity,
							      nWavesWidth, nWavesHeight);

		ImGui::Text("Noise seed");
		if (ImGui::InputText("", seedBuf, sizeof(seedBuf) / sizeof(char)))
		{
			worldManipulator->setTerrainAlgorithm(currentAlgo, std::string(seedBuf),
							      nVerticesSide, horizontalScale,
							      nOctaves, persistence, lacunarity,
							      nWavesWidth, nWavesHeight);
		}
	}
	if (currentAlgo == SINUSOIDAL)
	{
		tempI = nWavesWidth;
		ImGui::SliderInt("N waves width", &nWavesWidth, 1, 10);
		if (tempI != nWavesWidth)
			worldManipulator->setTerrainAlgorithm(currentAlgo, std::string(seedBuf),
							      nVerticesSide, horizontalScale,
							      nOctaves, persistence, lacunarity,
							      nWavesWidth, nWavesHeight);

		tempI = nWavesHeight;
		ImGui::SliderInt("N waves height", &nWavesHeight, 1, 10);
		if (tempI != nWavesHeight)
			worldManipulator->setTerrainAlgorithm(currentAlgo, std::string(seedBuf),
							      nVerticesSide, horizontalScale,
							      nOctaves, persistence, lacunarity,
							      nWavesWidth, nWavesHeight);
	}
}

