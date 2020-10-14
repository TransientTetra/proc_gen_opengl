#include "controller/entity_translator.hpp"

std::vector<Vertex> EntityTranslator::getVertices(const Entity &entity)
{
	std::vector<Vertex> ret;
	for (auto&& point : entity.getVertices())
	{
		ret.emplace_back(Vertex(point));
	}
	return ret;
}

std::vector<unsigned int> EntityTranslator::getIndices(const Entity &entity)
{
	return entity.getIndices();
}
