#include "controller/entity_translator.hpp"

std::vector<Vertex> EntityTranslator::getVertices(const Entity &entity)
{
	std::vector<Vertex> ret;
	for (auto&& point : entity.getVertices())
	{
		// TODO add norm and color vectors. I see that this method is not used anywhere, so I leave it here
		//  commented (it doesn't work because Vertex require normal and color too) and let you solve this
		//  issue by yourself
//		ret.emplace_back(Vertex(point));
	}
	return ret;
}

std::vector<unsigned int> EntityTranslator::getIndices(const Entity &entity)
{
	return entity.getIndices();
}
