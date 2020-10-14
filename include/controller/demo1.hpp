#ifndef DEMO1_HPP
#define DEMO1_HPP

#include <chrono>
#include <model/world.hpp>
#include "application.hpp"
#include "world_manipulator.hpp"
#include <controller/terrain_translator.hpp>

class Demo1 : public Application
{
private:
	World world;
	WorldManipulator worldManipulator;
	TerrainTranslator terrainTranslator;
public:
	Demo1(const std::string &title, int height, int width);

	void run() override;

	void processEvents() override;
};


#endif //DEMO1_HPP
