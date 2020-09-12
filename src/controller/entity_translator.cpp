#include "controller/entity_translator.hpp"

std::vector<Vertex> EntityTranslator::getVertices(Entity &entity)
{
	std::vector<Vertex> ret;
	for (auto point : entity.getVertices())
	{
		ret.emplace_back(Vertex(point));
	}
	return ret;
}

std::vector<unsigned int> EntityTranslator::getIndices(Entity &entity)
{
	return entity.getIndices();
}
