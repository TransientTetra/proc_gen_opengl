#ifndef PROC_GEN_OPENGL_VBO_HPP
#define PROC_GEN_OPENGL_VBO_HPP


class VBO //vertex buffer object
{
private:
	unsigned int id;
public:
	VBO();
	~VBO();

	void bind();
	void loadVertices(float *vertices, int size, GLenum usage);
};

#endif //PROC_GEN_OPENGL_VBO_HPP
