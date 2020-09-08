#include <GL/glew.h>
#include <iostream>
#include <glm/glm/gtc/type_ptr.hpp>
#include "view/opengl_interfacing/shader_program.hpp"

ShaderProgram::ShaderProgram()
{
	id = glCreateProgram();
}

void ShaderProgram::attachShader(Shader shader)
{
	glAttachShader(id, shader.getId());
}

void ShaderProgram::attachVertexAndFragmentShaders(VertexShader vs, FragmentShader fs)
{
	attachShader(vs);
	attachShader(fs);
}

void ShaderProgram::linkProgram()
{
	glLinkProgram(id);
	int success;
	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if (!success)
	{
		char info[512];
		glGetProgramInfoLog(id, 512, NULL, info);
		std::cerr << "Linking shader program failed: " << info << std::endl;
	}
}

void ShaderProgram::useProgram()
{
	glUseProgram(id);
}

unsigned int ShaderProgram::getId() const
{
	return id;
}

void ShaderProgram::sendUniformMatrix(std::string uniformName, const glm::mat4 &matrix)
{
	int id = glGetUniformLocation(getId(), uniformName.c_str());
	if (id == -1)
	{
		std::cerr << "Uniform " << uniformName << " location getting failed" << std::endl;
	}
	glUniformMatrix4fv(id, 1, GL_FALSE, glm::value_ptr(matrix));
}
