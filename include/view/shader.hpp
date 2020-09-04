#ifndef PROC_GEN_OPENGL_SHADER_HPP
#define PROC_GEN_OPENGL_SHADER_HPP


#include <string>
#include <GL/glew.h>

class Shader
{
protected:
	unsigned int id;
	std::string getSourceFromFile(std::string filename);
public:
	Shader(int shaderType);
	~Shader();
	void loadCompileShaderSource(std::string filename);

	unsigned int getId() const;
};


#endif //PROC_GEN_OPENGL_SHADER_HPP
