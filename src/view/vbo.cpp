#include <GL/glew.h>
#include "view/vbo.hpp"

VBO::VBO()
: isBound(false)
{
	glGenBuffers(1, &id);
}

VBO::~VBO()
{
}

void VBO::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
	isBound = true;
}

void VBO::loadVertices(float *vertices, int size)
{
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}
