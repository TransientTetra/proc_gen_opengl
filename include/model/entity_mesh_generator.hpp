#ifndef PROC_GEN_OPENGL_ENTITY_MESH_GENERATOR_HPP
#define PROC_GEN_OPENGL_ENTITY_MESH_GENERATOR_HPP


#include "entity.hpp"

class EntityMeshGenerator
{
protected:
	Entity* entity;
public:
	explicit EntityMeshGenerator(Entity* entity);

	virtual ~EntityMeshGenerator();
	std::shared_ptr<Mesh> createMesh();
};


#endif //PROC_GEN_OPENGL_ENTITY_MESH_GENERATOR_HPP
