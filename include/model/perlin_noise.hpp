#ifndef PROC_GEN_OPENGL_PERLIN_NOISE_HPP
#define PROC_GEN_OPENGL_PERLIN_NOISE_HPP


#include <glm/glm.hpp>
#include "noise.hpp"

class PerlinNoise : public Noise
{
private:
	glm::vec2 gradient(unsigned int x, unsigned int y);
public:
	float eval(float x, float y) override;
};


#endif //PROC_GEN_OPENGL_PERLIN_NOISE_HPP
