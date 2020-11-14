#include "view/terrain_control_frame.hpp"
#include "view/view.hpp"

TerrainControlFrame::TerrainControlFrame(TerrainModelsView *view, const std::string &name, WorldManipulator* worldManipulator)
: Frame(view, name), worldManipulator(worldManipulator)
{
	flags = ImGuiWindowFlags_NoResize;
	width = 500;
	height = 550;

	currentAlgo = FLAT;
	op = ADDITION;

	flat = true;
	white = false;
	sinusoidal = false;
	perlin = false;
	diamond = false;
	voronoi = false;

	widthTerrain = 10;
	heightTerrain = 10;

	nVerticesSide = 256;
	scale = 1;
	horizontalScale = .3f;
	nOctaves = 1;
	persistence = .5f;
	lacunarity = 2;

	seedBuf[0] = '\0';

	nWavesWidth = 1;
	nWavesHeight = 1;

	nPartitions = 40;
	levelDiff = 0.2;

	sendUpdateSignal();
}

void TerrainControlFrame::mainDraw()
{
	ImGui::SetWindowSize(ImVec2(width, height));
	ImGui::Columns(2);

	ImGui::Text("Generation algorithm");
	bool checkboxChange = false;
	if (ImGui::Checkbox("Flat", &flat))
	{
		checkboxChange = true;
		if (flat)
			currentAlgo = static_cast<GenerationAlgorithm>(currentAlgo | FLAT);
		else
			currentAlgo = static_cast<GenerationAlgorithm>(currentAlgo & ~FLAT);
	}
	if (ImGui::Checkbox("White Noise", &white))
	{
		checkboxChange = true;
		if (white)
			currentAlgo = static_cast<GenerationAlgorithm>(currentAlgo | WHITE_NOISE);
		else
			currentAlgo = static_cast<GenerationAlgorithm>(currentAlgo & ~WHITE_NOISE);
	}
	if (ImGui::Checkbox("Sinusoidal", &sinusoidal))
	{
		checkboxChange = true;
		if (sinusoidal)
			currentAlgo = static_cast<GenerationAlgorithm>(currentAlgo | SINUSOIDAL);
		else
			currentAlgo = static_cast<GenerationAlgorithm>(currentAlgo & ~SINUSOIDAL);
	}
	if (ImGui::Checkbox("Perlin Noise", &perlin))
	{
		checkboxChange = true;
		if (perlin)
			currentAlgo = static_cast<GenerationAlgorithm>(currentAlgo | PERLIN_NOISE);
		else
			currentAlgo = static_cast<GenerationAlgorithm>(currentAlgo & ~PERLIN_NOISE);
	}
	if (ImGui::Checkbox("Diamond Square", &diamond))
	{
		checkboxChange = true;
		if (diamond)
			currentAlgo = static_cast<GenerationAlgorithm>(currentAlgo | DIAMOND_SQUARE);
		else
			currentAlgo = static_cast<GenerationAlgorithm>(currentAlgo & ~DIAMOND_SQUARE);
	}
	if (ImGui::Checkbox("Voronoi Diagrams", &voronoi))
	{
		checkboxChange = true;
		if (voronoi)
			currentAlgo = static_cast<GenerationAlgorithm>(currentAlgo | VORONOI);
		else
			currentAlgo = static_cast<GenerationAlgorithm>(currentAlgo & ~VORONOI);
	}
	if (checkboxChange)
		sendUpdateSignal();
	ImGui::NextColumn();

	ImGui::Text("Multiple algorithms operation");
	HeightMapOperation tempO = op;
	if (ImGui::RadioButton("Addition", op == ADDITION)) op = ADDITION;
	if (ImGui::RadioButton("Multiplication", op == MULTIPLICATION)) op = MULTIPLICATION;
	if (tempO != op)
		sendUpdateSignal();

	ImGui::Columns(1);
	ImGui::Text("Generation algorithm parameters");

	float tempF = widthTerrain;
	ImGui::SliderFloat("Width", &widthTerrain, 1, 1000);
	if (tempF != widthTerrain)
	{
		worldManipulator->setTerrainWidth(widthTerrain);
	}

	tempF = heightTerrain;
	ImGui::SliderFloat("Height", &heightTerrain, 1, 1000);
	if (tempF != heightTerrain)
	{
		worldManipulator->setTerrainLength(heightTerrain);
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
	}

	if (currentAlgo & PERLIN_NOISE)
	{
		tempF = horizontalScale;
		ImGui::SliderFloat("Horizontal scale", &horizontalScale, .01f, .5f);
		if (tempF != horizontalScale)
			sendUpdateSignal();

		tempF = lacunarity;
		ImGui::SliderFloat("Lacunarity", &lacunarity, 1.f, 10.f);
		if (tempF != lacunarity)
			sendUpdateSignal();
	}

	if (currentAlgo & PERLIN_NOISE or currentAlgo & DIAMOND_SQUARE)
	{
		tempF = persistence;
		ImGui::SliderFloat("Persistence", &persistence, 0, 1);
		if (tempF != persistence)
			sendUpdateSignal();
	}

	if (currentAlgo & WHITE_NOISE or currentAlgo & PERLIN_NOISE)
	{
		tempI = nOctaves;
		ImGui::SliderInt("N octaves", &nOctaves, 1, 10);
		if (tempI != nOctaves)
			sendUpdateSignal();
	}

	if (currentAlgo & VORONOI)
	{
		tempI = nPartitions;
		ImGui::SliderInt("N partitions", &nPartitions, 1, 100);
		if (tempI != nPartitions)
			sendUpdateSignal();

		tempF = levelDiff;
		ImGui::SliderFloat("Level diff %", &levelDiff, 0, 1);
		if (tempF != levelDiff)
			sendUpdateSignal();
	}

	if (currentAlgo & SINUSOIDAL)
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

	if (currentAlgo & WHITE_NOISE or currentAlgo & PERLIN_NOISE or currentAlgo & DIAMOND_SQUARE
	    or currentAlgo & VORONOI)
	{
		ImGui::Text("Noise seed");
		if (ImGui::InputText("", seedBuf, sizeof(seedBuf) / sizeof(char)))
		{
			sendUpdateSignal();
		}
	}
}

void TerrainControlFrame::sendUpdateSignal()
{
	worldManipulator->setTerrainAlgorithm(currentAlgo, op, std::string(seedBuf),
					      nVerticesSide, horizontalScale,
					      nOctaves, persistence, lacunarity,
					      nWavesWidth, nWavesHeight, nPartitions, levelDiff);
}

