#ifndef PROC_GEN_OPENGL_ENTITY_TRANSLATOR_HPP
#define PROC_GEN_OPENGL_ENTITY_TRANSLATOR_HPP


#include <vector>
#include <view/opengl_interfacing/vertex.hpp>
#include <model/entity.hpp>

class EntityTranslator
{
private:
protected:
public:
	std::vector<Vertex> getVertices(const Entity &entity);
	std::vector<unsigned int> getIndices(const Entity &entity);
};


#endif //PROC_GEN_OPENGL_ENTITY_TRANSLATOR_HPP
