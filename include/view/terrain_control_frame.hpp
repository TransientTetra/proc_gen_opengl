#ifndef PROC_GEN_OPENGL_TERRAIN_CONTROL_FRAME_HPP
#define PROC_GEN_OPENGL_TERRAIN_CONTROL_FRAME_HPP


#include <generation_algorithm.hpp>
#include <controller/world_manipulator.hpp>
#include "frame.hpp"

class TerrainControlFrame : public Frame
{
private:
	WorldManipulator* worldManipulator;
	GenerationAlgorithm currentAlgo;
	float widthTerrain;
	float heightTerrain;
	int nVerticesWidth;
	int nVerticesHeight;
	float scale;

	float horizontalScale;
	int nOctaves;
	float persistence;
	float lacunarity;

	void mainDraw() override;
public:
	TerrainControlFrame(View *view, const std::string &name, WorldManipulator* worldManipulator);
};


#endif //PROC_GEN_OPENGL_TERRAIN_CONTROL_FRAME_HPP
