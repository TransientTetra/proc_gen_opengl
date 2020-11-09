#ifndef PROC_GEN_OPENGL_VBO_HPP
#define PROC_GEN_OPENGL_VBO_HPP


#include <vector>
#include "vertex.hpp"

class VBO //vertex buffer object
{
private:
	unsigned int id;
public:
	VBO();

	virtual ~VBO();

	void bind();
	void loadVertices(std::vector<Vertex> &vertices, GLenum usage);
};

#endif //PROC_GEN_OPENGL_VBO_HPP
