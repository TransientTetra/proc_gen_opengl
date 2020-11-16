#ifndef PROC_GEN_OPENGL_HYDRAULIC_EROSION_HPP
#define PROC_GEN_OPENGL_HYDRAULIC_EROSION_HPP


#include <random>
#include "erosion.hpp"

class HydraulicErosion : public Erosion
{
private:
	std::mt19937 generator;
	unsigned int seed;

	unsigned int nDroplets;
	unsigned int dropletLifetime;
	float dropletInertia;
	float dropletRadius;
	float dropletSedimentCapacity;
	float erosionSpeed;
	float depositSpeed;
	float evaporateSpeed;
	float gravity;
public:
	HydraulicErosion(unsigned int seed, unsigned int nDroplets, unsigned int dropletLifetime);

	void erode(Terrain &terrain) override;
};


#endif //PROC_GEN_OPENGL_HYDRAULIC_EROSION_HPP
