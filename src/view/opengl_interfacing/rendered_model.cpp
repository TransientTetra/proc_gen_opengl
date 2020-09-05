#include "view/opengl_interfacing/rendered_model.hpp"

RenderedModel::RenderedModel(float *vertices, int sizeVertices, unsigned int *indices, int sizeIndices, GLenum usage)
: sizeIndices(sizeIndices), sizeVertices(sizeVertices)
{
	nVertices = sizeVertices / sizeof(float);
	nIndices = sizeIndices / sizeof(unsigned int);
	transformMatrix = glm::mat4(1.0f);
	//todo these almost definitely don't all belong here
	modelMatrix = glm::mat4(1.0f);
	viewMatrix = glm::mat4(1.0f);
	projectionMatrix = glm::mat4(1.0f);

	//todo remove demo matrices setting from here
	viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, -3.0f));
	projectionMatrix = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f,100.0f);

	vs.loadCompileShaderSource("assets/shaders/vertex/default_basic_transform.glsl");
	fs.loadCompileShaderSource("assets/shaders/fragment/default_basic.glsl");

	shader.attachVertexAndFragmentShaders(vs, fs);
	shader.linkProgram();

	vao.bind();

	vbo.bind();
	vbo.loadVertices(vertices, sizeVertices, usage);

	ebo.bind();
	ebo.loadIndices(indices, sizeIndices, usage);

	vao.setVertexAttributePointers(0, 3, 3 * sizeof(float), 0);
}

void RenderedModel::draw()
{
	shader.useProgram();
	//todo remove demo rotation from here
	modelMatrix = glm::rotate(modelMatrix, glm::radians(1.f), glm::vec3(.5f, 1.0f, 0.2f));

	//first parameter has to be exactly the same as the uniform's name in the shader used
	shader.sendUniformMatrix("modelMatrix", modelMatrix);
	shader.sendUniformMatrix("viewMatrix", viewMatrix);
	shader.sendUniformMatrix("projectionMatrix", projectionMatrix);

	vao.bind();
	glDrawElements(GL_TRIANGLES, sizeIndices, GL_UNSIGNED_INT, 0);
}

void RenderedModel::scale(glm::vec3 scale)
{
	transformMatrix = glm::scale(transformMatrix, scale);
}

void RenderedModel::rotate(float angle, glm::vec3 axis)
{
	axis = glm::normalize(axis);
	transformMatrix = glm::rotate(transformMatrix, angle, axis);
}

void RenderedModel::translate(glm::vec3 trans)
{
	transformMatrix = glm::translate(transformMatrix, trans);
}

void RenderedModel::scaleRotateTranslate(glm::vec3 scale, float angle, glm::vec3 axis, glm::vec3 trans)
{
	this->scale(scale);
	rotate(angle, axis);
	translate(trans);
}

