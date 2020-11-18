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
	unsigned int seed;

	unsigned int nDroplets;
	unsigned int dropletLifetime;
	float dropletInitialSpeed;
	float dropletInitialVolume;

	float dropletInertia = .1f;
	float sedimentCapacityFactor = 1;
	float minSedimentCapacity = .01f;
	float gravity = 4;
	float evaporateSpeed = .01f;
	float depositSpeed = .3f;
	float erosionSpeed = .3f;
	float dropletRadius = 3;

	float getDropletHeight(const Droplet &droplet, Terrain &terrain);
	glm::vec2 getDropletDirection(const Droplet &droplet, Terrain &terrain);
	void deposit(const Droplet &droplet, Terrain &terrain, float amount);
	void erodeSingle(const Droplet &droplet, Terrain &terrain, float amount);
public:
	HydraulicErosion(unsigned int seed, unsigned int nDroplets, unsigned int dropletLifetime,
			 float dropletInitialSpeed, float dropletInitialVolume);

	void erode(Terrain &terrain) override;
};


#endif //PROC_GEN_OPENGL_HYDRAULIC_EROSION_HPP
