#ifndef PROC_GEN_OPENGL_WORLD_MANIPULATOR_HPP
#define PROC_GEN_OPENGL_WORLD_MANIPULATOR_HPP


#include <generation_algorithm.hpp>
#include <model/world.hpp>
#include "model_manipulator.hpp"
#include <string>

class WorldManipulator : public ModelManipulator
{
private:
	World* world;
public:
	WorldManipulator(World *world);

	virtual ~WorldManipulator();

	void
	setTerrainAlgorithm(GenerationAlgorithm algorithm, std::string seed, int nVerticesSide, float horizontalScale,
			    unsigned int nOctaves, float persistence, float lacunarity, unsigned int nWavesWidth,
			    unsigned int nWavesLength, unsigned int nPartitions, float levelDiff, float gapWidth,
			    float gapHeight);

	void setTerrainWidth(float width);

	void setTerrainLength(float height);

	void setTerrainScale(float scale);
};


#endif //PROC_GEN_OPENGL_WORLD_MANIPULATOR_HPP
