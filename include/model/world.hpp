#ifndef PROC_GEN_OPENGL_WORLD_HPP
#define PROC_GEN_OPENGL_WORLD_HPP


#include <memory>
#include <vector>
#include "entity.hpp"
#include "terrain.hpp"

class World
{
private:
	std::vector<std::unique_ptr<Entity>> entities; //possibly use another data structure
	std::unique_ptr<Terrain> terrain;

protected:
public:
};


#endif //PROC_GEN_OPENGL_WORLD_HPP
