#ifndef PROC_GEN_OPENGL_NOISE_HPP
#define PROC_GEN_OPENGL_NOISE_HPP


class Noise
{
protected:
	unsigned int seed;
public:
	Noise(unsigned int seed);
	virtual float eval(float x, float y) = 0;

	virtual ~Noise();
};


#endif //PROC_GEN_OPENGL_NOISE_HPP
