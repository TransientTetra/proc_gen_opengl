#include "view/opengl_interfacing/rendered_model.hpp"

RenderedModel::RenderedModel(float *vertices, int sizeVertices, unsigned int *indices, int sizeIndices, GLenum usage)
: sizeIndices(sizeIndices), sizeVertices(sizeVertices)
{
	nVertices = sizeVertices / sizeof(float);
	nIndices = sizeIndices / sizeof(unsigned int);

	vs.loadCompileShaderSource("assets/shaders/vertex/default_basic.glsl");
	fs.loadCompileShaderSource("assets/shaders/fragment/default_basic.glsl");

	program.attachVertexAndFragmentShaders(vs, fs);
	program.linkProgram();

	vao.bind();

	vbo.bind();
	vbo.loadVertices(vertices, sizeVertices, usage);

	ebo.bind();
	ebo.loadIndices(indices, sizeIndices, usage);

	vao.setVertexAttributePointers(0, 3);
}

void RenderedModel::draw()
{
	program.useProgram();
	vao.bind();
	glDrawElements(GL_TRIANGLES, sizeIndices, GL_UNSIGNED_INT, 0);
}
