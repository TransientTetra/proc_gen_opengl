#ifndef PROC_GEN_OPENGL_RENDERED_MODEL_HPP
#define PROC_GEN_OPENGL_RENDERED_MODEL_HPP


#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "vao.hpp"
#include "vbo.hpp"
#include "ebo.hpp"
#include "vertex_shader.hpp"
#include "fragment_shader.hpp"
#include "shader_program.hpp"

//todo perhaps change class name and delegate some of its responsibilities?
class RenderedModel
{
private:
	VertexShader vs;
	FragmentShader fs;
	ShaderProgram shader;

	glm::mat4 transformMatrix;
	glm::mat4 modelMatrix;
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

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

	void scale(glm::vec3 scale);
	//angle in radians!
	void rotate(float angle, glm::vec3 axis);
	void translate(glm::vec3 trans);

	//angle in radians!; when possible use this function, it has the correct order of matrix operations
	void scaleRotateTranslate(glm::vec3 scale, float angle, glm::vec3 axis, glm::vec3 trans);
};


#endif //PROC_GEN_OPENGL_RENDERED_MODEL_HPP
