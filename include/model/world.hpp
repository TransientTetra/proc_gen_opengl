#ifndef PROC_GEN_OPENGL_WORLD_HPP
#define PROC_GEN_OPENGL_WORLD_HPP


#include <memory>
#include <vector>
#include "entity.hpp"
#include "terrain.hpp"

class World
{
private:
	std::vector<std::shared_ptr<Entity>> entities; //possibly use another data structure
	std::unique_ptr<Terrain> terrain;

protected:
public:
	void addEntity(std::shared_ptr<Entity> entity);

	const std::vector<std::shared_ptr<Entity>> &getEntities() const;
};


#endif //PROC_GEN_OPENGL_WORLD_HPP
