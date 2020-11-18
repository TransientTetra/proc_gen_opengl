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

	float dropletInertia = .5f;
	float sedimentCapacityFactor = 4;
	float minSedimentCapacity = .01f;
	float gravity = 4;
	float evaporateSpeed = .1f;
	float depositSpeed = .3f;
	float erosionSpeed = .3f;
	float dropletRadius;

	//bilinear interpolation
	float interp(float val1, float val2, float val3, float val4, float w1, float w2, float w3, float w4);

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
