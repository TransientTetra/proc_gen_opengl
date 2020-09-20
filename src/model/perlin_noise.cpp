#include <algorithm>
#include "model/perlin_noise.hpp"

PerlinNoise::PerlinNoise(unsigned int seed)
: Noise(seed)
{
	std::mt19937 generator(seed);
	std::uniform_real_distribution<float> distribution(-1.f, 1.f);
	for (int i = 0; i < tableSize; ++i)
	{
		gradients.emplace_back(glm::normalize(glm::vec2(distribution(generator), distribution(generator))));
		permutations.emplace_back(i);
	}

	std::shuffle(std::begin(permutations), std::end(permutations), generator);
}

float PerlinNoise::eval(float x, float y)
{
	glm::vec2 v = glm::vec2(x, y);
	//grid points
	//  v0 --- v1
	//  |      |
	//  |      |
	//  v2 --- v3

	glm::vec2 v0 = glm::floor(v);
	glm::vec2 v1 = v0 + glm::vec2(1, 0);
	glm::vec2 v2 = v0 + glm::vec2(0, 1);
	glm::vec2 v3 = v0 + glm::vec2(1, 1);

	//gradients
	glm::vec2 g0 = gradient(v0.x, v0.y);
	glm::vec2 g1 = gradient(v1.x, v1.y);
	glm::vec2 g2 = gradient(v2.x, v2.y);
	glm::vec2 g3 = gradient(v3.x, v3.y);

	//dot products
	float d0 = glm::dot(g0, (v - v0));
	float d1 = glm::dot(g1, (v - v1));
	float d2 = glm::dot(g2, (v - v2));
	float d3 = glm::dot(g3, (v - v3));

	//averaging and smoothing
	float a = lerp(d0, d1, fade(v.x - v0.x));
	float b = lerp(d2, d3, fade(v.x - v0.x));

	return lerp(a, b, fade(v.y - v0.y));
}

glm::vec2 PerlinNoise::gradient(unsigned int x, unsigned int y)
{
	return gradients[permutations[(permutations[x % tableSize] + y) % tableSize]];
}

float PerlinNoise::fade(float x)
{
	return 3 * x * x - 2 * x * x * x;
}

float PerlinNoise::lerp(float x, float y, float w)
{
	return (1.f - w) * x + w * y;
}

