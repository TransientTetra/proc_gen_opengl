#ifndef PROC_GEN_OPENGL_RENDERED_MODEL_HPP
#define PROC_GEN_OPENGL_RENDERED_MODEL_HPP


#include <GL/glew.h>
#include "vao.hpp"
#include "vbo.hpp"
#include "ebo.hpp"
#include "vertex_shader.hpp"
#include "fragment_shader.hpp"
#include "shader_program.hpp"

class RenderedModel
{
private:
	VertexShader vs;
	FragmentShader fs;
	ShaderProgram program;

	VAO vao;
	VBO vbo;
	EBO ebo;

	unsigned int sizeVertices; //size in bytes!
	unsigned int sizeIndices;

	unsigned int nVertices; //number of them!
	unsigned int nIndices;
public:
	RenderedModel(float* vertices, int sizeVertices, unsigned int* indices, int sizeIndices, GLenum usage);

	void draw();
};


#endif //PROC_GEN_OPENGL_RENDERED_MODEL_HPP
