#ifndef PROC_GEN_OPENGL_LIGHT_VAO_HPP
#define PROC_GEN_OPENGL_LIGHT_VAO_HPP


class LightVAO
{
private:
	unsigned int id;
public:
	LightVAO();

	virtual ~LightVAO();

	void bind();
	void bindBuffer(unsigned int vaoId);
	void setVertexAttributePointers(unsigned int index, unsigned int size, int stride, int offset);
};


#endif //PROC_GEN_OPENGL_LIGHT_VAO_HPP

