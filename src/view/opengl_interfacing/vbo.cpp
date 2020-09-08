#include <GL/glew.h>
#include "view/opengl_interfacing/vbo.hpp"

VBO::VBO()
{
	glGenBuffers(1, &id);
}

VBO::~VBO()
{
}

void VBO::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::loadVertices(float *vertices, int size, GLenum usage)
{
	glBufferData(GL_ARRAY_BUFFER, size, vertices, usage);
}
