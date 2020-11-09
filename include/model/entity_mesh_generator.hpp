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
	virtual void updateMesh(Mesh *mesh) = 0;
};


#endif //PROC_GEN_OPENGL_ENTITY_MESH_GENERATOR_HPP
