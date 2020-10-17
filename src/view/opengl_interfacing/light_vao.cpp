#include <GL/glew.h>
#include "view/opengl_interfacing/light_vao.hpp"

LightVAO::LightVAO()
{
	glGenVertexArrays(1, &id);
}

LightVAO::~LightVAO()
{
	glDeleteVertexArrays(1, &id);
}

void LightVAO::bind()
{
	glBindVertexArray(id);
}

void LightVAO::bindBuffer(unsigned int vaoId)
{
	glBindBuffer(GL_ARRAY_BUFFER, vaoId);
}

void LightVAO::setVertexAttributePointers(unsigned int index, unsigned int size, int stride, int offset)
{
	//index is the id of vertex attribute we are configuring, dictated by
	//the value from vertex shader; size is the size of vertices loaded to vbo
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, (void *)offset);
	glEnableVertexAttribArray(index);
}