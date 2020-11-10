#include "model/entity_mesh_generator.hpp"

EntityMeshGenerator::EntityMeshGenerator(Entity *entity)
: entity(entity)
{

}

EntityMeshGenerator::~EntityMeshGenerator()
{

}

std::shared_ptr<Mesh> EntityMeshGenerator::createMesh()
{
	return std::make_shared<Mesh>(entity->getVertices(), entity->getIndices(), GL_STATIC_DRAW);
}
