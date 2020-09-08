#ifndef PROC_GEN_OPENGL_EBO_HPP
#define PROC_GEN_OPENGL_EBO_HPP


class EBO
{
private:
	unsigned int id;
public:
	EBO();

	void bind();
	void loadIndices(unsigned int* indices, int size, GLenum usage);
};


#endif //PROC_GEN_OPENGL_EBO_HPP
