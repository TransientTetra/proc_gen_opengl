#ifndef PROC_GEN_OPENGL_HYDRAULIC_EROSION_HPP
#define PROC_GEN_OPENGL_HYDRAULIC_EROSION_HPP


#include <random>
#include "erosion.hpp"

struct Droplet
{
	glm::vec2 position;
	glm::vec2 offsets;
	glm::vec2 direction;
	float speed;
	float water;
	float sediment;

	Droplet(const glm::vec2 &position, float speed, float water);
	void updateOffsets();
};

class HydraulicErosion : public Erosion
{
private:
	std::knuth_b generator;

	unsigned int nDroplets;
	unsigned int dropletLifetime;
	float dropletInitialSpeed;
	float dropletInitialVolume;

	float dropletInertia;
	float sedimentCapacityFactor;
	float minSedimentCapacity;
	float gravity;
	float evaporateSpeed;
	float depositSpeed;
	float erosionSpeed;
	unsigned int dropletRadius;

	float getDropletHeight(const Droplet &droplet, Terrain &terrain);
	glm::vec2 getDropletDirection(const Droplet &droplet, Terrain &terrain);
	void deposit(const Droplet &droplet, Terrain &terrain, float amount);
	void erodeSingle(const Droplet &droplet, Terrain &terrain, float amount);
public:
	HydraulicErosion(unsigned int seed, unsigned int nDroplets);

	HydraulicErosion(unsigned int seed, unsigned int nDroplets, float dropletInertia,
			 float evaporateSpeed, float depositSpeed, float erosionSpeed, unsigned int dropletRadius);

	void erode(Terrain &terrain) override;
};


#endif //PROC_GEN_OPENGL_HYDRAULIC_EROSION_HPP
