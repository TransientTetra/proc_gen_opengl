#include <fstream>
#include <sstream>
#include <iostream>
#include "view/opengl_interfacing/shader.hpp"

Shader::Shader(GLenum shaderType)
{
	id = glCreateShader(shaderType);
}

Shader::~Shader()
{
	glDeleteShader(id);
}

std::string Shader::getSourceFromFile(std::string filename)
{
	std::ifstream f(filename);
	std::string ret;
	if (f)
	{
		std::ostringstream stream;
		stream << f.rdbuf();
		ret = stream.str();
	}
	return ret;
}

void Shader::loadCompileShaderSource(std::string filename)
{
	std::string sourceCode = getSourceFromFile(filename);
	if (sourceCode != "")
	{
		glShaderSource(id, 1, (const GLchar**)&sourceCode, NULL);
		glCompileShader(id);
		int success;
		glGetShaderiv(id, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			char info[512];
			glGetShaderInfoLog(id, 512, NULL, info);
			std::cerr << "Error loading shader: " << info << std::endl;
		}
	}
}

unsigned int Shader::getId() const
{
	return id;
}
