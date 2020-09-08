#include <GL/glew.h>
#include "view/opengl_interfacing/vao.hpp"

VAO::VAO()
{
	glGenVertexArrays(1, &id);
}

void VAO::bind()
{
	glBindVertexArray(id);
}

void VAO::setVertexAttributePointers(unsigned int index, int size)
{
	//index is the id of vertex attribute we are configuring, dictated by
	//the value from vertex shader; size is the size of vertices loaded to vbo
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, size * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
}