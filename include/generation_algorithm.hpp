#ifndef PROC_GEN_OPENGL_ALGORITHMS_HPP
#define PROC_GEN_OPENGL_ALGORITHMS_HPP

enum GenerationAlgorithm : unsigned int
{
	FLAT		= 1 << 0,
	WHITE_NOISE	= 1 << 1,
	SINUSOIDAL	= 1 << 2,
	PERLIN_NOISE	= 1 << 3,
	DIAMOND_SQUARE	= 1 << 4,
	VORONOI		= 1 << 5,
};

#endif //PROC_GEN_OPENGL_ALGORITHMS_HPP
