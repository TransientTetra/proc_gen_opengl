#include "view/opengl_interfacing/mesh.hpp"

#include <memory>

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, GLenum usage, Lightsource* light)
	: vertices(vertices), indices(indices), usage(usage), light(light)
{
	modelMatrix = glm::mat4(1.0f);

	//the shaders used below are strongly related to what uniform names are used in draw(), so they cannot be
	//parametrized easily
	VertexShader vs;
	FragmentShader fs;
	vs.loadCompileShaderSource("assets/shaders/vertex/default_basic_lighting.glsl");
	fs.loadCompileShaderSource("assets/shaders/fragment/default_basic_lighting.glsl");

	shader.attachVertexAndFragmentShaders(vs, fs);
	shader.linkProgram();

	update();
}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, GLenum usage, Lightsource* light, glm::vec3 color)
	: Mesh(vertices, indices, usage, light)
{
	this->color = color;
}

void Mesh::draw(const glm::mat4 &viewMatrix, const glm::mat4 &projectionMatrix)
{
	shader.useProgram();

	//first parameter has to be exactly the same as the uniform's name in the shader used
	shader.sendUniformMatrix("model", modelMatrix);
	shader.sendUniformMatrix("view", viewMatrix);
	shader.sendUniformMatrix("projection", projectionMatrix);

	shader.sendUniformVector("lightPos", light->getPosition());
	shader.sendUniformVector("lightColor", light->getColor());
	shader.sendUniformVector("viewPos", glm::vec3(2.0f, 10.0f, 2.1f));

	vao->bind();
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}

void Mesh::scale(glm::vec3 scale)
{
	modelMatrix = glm::scale(modelMatrix, scale);
}

//todo rotate only works when model at 0,0,0
void Mesh::rotate(float angle, glm::vec3 axis)
{
	axis = glm::normalize(axis);
	modelMatrix = glm::rotate(modelMatrix, angle, axis);
}

void Mesh::translate(glm::vec3 trans)
{
	modelMatrix = glm::translate(modelMatrix, trans);
}

void Mesh::scaleRotateTranslate(glm::vec3 scale, float angle, glm::vec3 axis, glm::vec3 trans)
{
	this->scale(scale);
	rotate(angle, axis);
	translate(trans);
}

Mesh::~Mesh()
{

}

std::vector<Vertex> &Mesh::getVertices()
{
	return vertices;
}

std::vector<unsigned int> &Mesh::getIndices()
{
	return indices;
}

std::vector<glm::vec3> &Mesh::getNormals()
{
	return normals;
}

void Mesh::update()
{
	vao = std::make_unique<VAO>();
	vbo = std::make_unique<VBO>();
	ebo = std::make_unique<EBO>();

	vao->bind();

	vbo->bind();
	vbo->loadVertices(vertices, usage);

	ebo->bind();
	ebo->loadIndices(indices, usage);

	vao->setVertexAttributePointers(0, 3, 9 * sizeof(float),0);
	//vao.setVertexAttributePointers(1, 3, 3 * sizeof(float), offsetof(Vertex, normal)) //for adding new fields to Vertex
	vao->setVertexAttributePointers(1, 3, 9 * sizeof(float), 3 * sizeof(float));
	vao->setVertexAttributePointers(2, 3, 9 * sizeof(float), 6 * sizeof(float));

}