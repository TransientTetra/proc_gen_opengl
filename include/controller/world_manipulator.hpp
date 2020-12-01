#ifndef PROC_GEN_OPENGL_WORLD_MANIPULATOR_HPP
#define PROC_GEN_OPENGL_WORLD_MANIPULATOR_HPP


#include <generation_algorithm.hpp>
#include <model/world.hpp>
#include "model_manipulator.hpp"
#include <string>

enum HeightMapOperation
{
	MULTIPLICATION,
	ADDITION,
};

class WorldManipulator : public ModelManipulator
{
private:
	World* world;
public:
	WorldManipulator(World *world);

	virtual ~WorldManipulator();

	void setTerrainAlgorithm(GenerationAlgorithm algorithm, HeightMapOperation operation, const std::string& seed,
				 int nVerticesSide, float horizontalScale, unsigned int nOctaves, float persistence,
				 float lacunarity, unsigned int nWavesWidth, unsigned int nWavesLength,
				 unsigned int nPartitions, float levelDiff);

	void setTerrainWidth(float width);

	void setTerrainLength(float height);

	void setTerrainScale(float scale);

	void erodeTerrainHydraulic(const std::string &seed, unsigned int nDroplets, float dropletInertia,
				   float evaporateSpeed, float depositSpeed, float erosionSpeed,
				   unsigned int dropletRadius);

	void loadTerrain(const std::string& filename);
	void saveTerrain(const std::string& filename);
};


#endif //PROC_GEN_OPENGL_WORLD_MANIPULATOR_HPP
