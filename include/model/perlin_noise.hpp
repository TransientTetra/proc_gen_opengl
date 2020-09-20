#ifndef PROC_GEN_OPENGL_PERLIN_NOISE_HPP
#define PROC_GEN_OPENGL_PERLIN_NOISE_HPP


#include <glm/glm.hpp>
#include <vector>
#include <random>
#include "noise.hpp"

class PerlinNoise : public Noise
{
private:
	const unsigned int tableSize = 256;
	std::vector<unsigned int> permutations;
	std::vector<glm::vec2> gradients;
	glm::vec2 gradient(unsigned int x, unsigned int y);
	float fade(float x);
	float lerp(float x, float y, float w);
public:
	PerlinNoise(unsigned int seed);

	float eval(float x, float y) override;
};


#endif //PROC_GEN_OPENGL_PERLIN_NOISE_HPP
