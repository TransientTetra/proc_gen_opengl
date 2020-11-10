#include <GL/glew.h>
#include "model/opengl_interfacing/ebo.hpp"

EBO::EBO()
{
	glGenBuffers(1, &id);
}

EBO::~EBO()
{
	glDeleteBuffers(1, &id);
}

void EBO::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void EBO::loadIndices(const std::vector<unsigned int> &indices, GLenum usage)
{
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), usage);
}
