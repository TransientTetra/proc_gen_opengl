#include "model/white_noise.hpp"

WhiteNoise::WhiteNoise(unsigned int seed)
: Noise(seed), generator(seed), distribution(-1.f, 1.f)
{}

float WhiteNoise::eval(float x, float y)
{
	//warning: this does not guarantee the same result for the same coordinates
	return distribution(generator);
}
