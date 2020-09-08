#ifndef PROC_GEN_OPENGL_RENDERED_MODEL_HPP
#define PROC_GEN_OPENGL_RENDERED_MODEL_HPP


#include <GL/glew.h>
#include "vao.hpp"
#include "vbo.hpp"
#include "ebo.hpp"

class RenderedModel
{
private:
	VAO vao;
	VBO vbo;
	EBO ebo;

	int sizeVertices; //size in bytes!
	int sizeIndices;

	int nVertices; //number of them!
	int nIndices;
public:
	RenderedModel(float* vertices, int sizeVertices, unsigned int* indices, int sizeIndices, GLenum usage);

	void draw();
};


#endif //PROC_GEN_OPENGL_RENDERED_MODEL_HPP
