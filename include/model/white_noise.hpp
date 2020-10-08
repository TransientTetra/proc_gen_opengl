#ifndef PROC_GEN_OPENGL_WHITE_NOISE_HPP
#define PROC_GEN_OPENGL_WHITE_NOISE_HPP


#include "noise.hpp"
#include <random>

class WhiteNoise : public Noise
{
private:
	std::mt19937 generator;
	std::uniform_real_distribution<float> distribution;
public:
	WhiteNoise(unsigned int seed);

	//warning: this does not guarantee the same result for the same coordinates
	float eval(float x, float y) override;
};


#endif //PROC_GEN_OPENGL_WHITE_NOISE_HPP
