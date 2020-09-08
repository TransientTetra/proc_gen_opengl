#include "view/opengl_interfacing/rendered_model.hpp"

RenderedModel::RenderedModel(float *vertices, int sizeVertices, unsigned int *indices, int sizeIndices, GLenum usage)
: sizeIndices(sizeIndices), sizeVertices(sizeVertices), nVertices(sizeVertices / sizeof(float)),
nIndices(sizeIndices / sizeof(unsigned int))
{
	vao.bind();

	vbo.bind();
	vbo.loadVertices(vertices, sizeVertices, usage);

	ebo.bind();
	ebo.loadIndices(indices, sizeIndices, usage);

	vao.setVertexAttributePointers(0, 3);
}

void RenderedModel::draw()
{
	vao.bind();
	glDrawElements(GL_TRIANGLES, sizeIndices, GL_UNSIGNED_INT, 0);
}
