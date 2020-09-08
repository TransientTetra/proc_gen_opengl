#ifndef PROC_GEN_OPENGL_SHADER_PROGRAM_HPP
#define PROC_GEN_OPENGL_SHADER_PROGRAM_HPP


#include <glm/glm/glm.hpp>
#include "vertex_shader.hpp"
#include "fragment_shader.hpp"

class ShaderProgram
{
private:
	unsigned int id;
	void attachShader(Shader shader);
public:
	ShaderProgram();
	void attachVertexAndFragmentShaders(VertexShader vs, FragmentShader fs);
	void linkProgram();
	void useProgram();

	unsigned int getId() const;
	void sendUniformMatrix(std::string uniformName, const glm::mat4 &matrix);
};


#endif //PROC_GEN_OPENGL_SHADER_PROGRAM_HPP
