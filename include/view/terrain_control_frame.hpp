#ifndef PROC_GEN_OPENGL_TERRAIN_CONTROL_FRAME_HPP
#define PROC_GEN_OPENGL_TERRAIN_CONTROL_FRAME_HPP


#include <generation_algorithm.hpp>
#include <controller/world_manipulator.hpp>
#include "frame.hpp"
#include "scene_3d.hpp"

class TerrainControlFrame : public Frame
{
private:
	WorldManipulator* worldManipulator;
	GenerationAlgorithm currentAlgo;
	HeightMapOperation op;

	//checkbox buffers
	bool flat;
	bool white;
	bool sinusoidal;
	bool perlin;
	bool diamond;
	bool voronoi;

	//common variables
	float widthTerrain;
	float heightTerrain;
	int nVerticesSide;
	float scale;

	//noise map variables
	float horizontalScale;
	int nOctaves;
	float persistence;
	float lacunarity;
	char seedBuf[256];

	//sinusoidal map variables
	int nWavesWidth;
	int nWavesHeight;

	//voronoi variables
	int nPartitions;
	float levelDiff;

	void mainDraw() override;
	void sendUpdateSignal();
public:
	TerrainControlFrame(Scene3D *view, const std::string &name, int xPos, int yPos, WorldManipulator* worldManipulator);
};


#endif //PROC_GEN_OPENGL_TERRAIN_CONTROL_FRAME_HPP
