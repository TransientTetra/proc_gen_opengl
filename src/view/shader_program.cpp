#include <GL/glew.h>
#include <iostream>
#include "view/shader_program.hpp"

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
