#ifndef PROC_GEN_OPENGL_VAO_HPP
#define PROC_GEN_OPENGL_VAO_HPP


class VAO
{
private:
	unsigned int id;
public:
	VAO();

	void bind();
	void setVertexAttributePointers(unsigned int index, unsigned int size, int stride, int offset);
};


#endif //PROC_GEN_OPENGL_VAO_HPP
