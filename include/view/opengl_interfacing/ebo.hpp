#ifndef PROC_GEN_OPENGL_EBO_HPP
#define PROC_GEN_OPENGL_EBO_HPP


#include <vector>

class EBO
{
private:
	unsigned int id;
public:
	EBO();

	virtual ~EBO();

	void bind();
	void loadIndices(std::vector<unsigned int> &indices, GLenum usage);
};


#endif //PROC_GEN_OPENGL_EBO_HPP
