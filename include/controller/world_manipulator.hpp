#ifndef PROC_GEN_OPENGL_WORLD_MANIPULATOR_HPP
#define PROC_GEN_OPENGL_WORLD_MANIPULATOR_HPP


#include <generation_algorithm.hpp>
#include <model/world.hpp>
#include "model_manipulator.hpp"

class WorldManipulator : public ModelManipulator
{
private:
	World* world;
public:
	void setTerrainAlgorithm(GenerationAlgorithm algorithm);

	void setTerrainWidth(float width);

	void setTerrainHeight(float height);

	void setTerrainNVerticesWidth(int nVertices);

	void setTerrainNVerticesHeight(int nVerticesHeight);
};


#endif //PROC_GEN_OPENGL_WORLD_MANIPULATOR_HPP
