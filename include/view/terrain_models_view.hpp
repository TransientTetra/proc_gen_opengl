#ifndef PROC_GEN_OPENGL_TERRAIN_MODELS_VIEW_HPP
#define PROC_GEN_OPENGL_TERRAIN_MODELS_VIEW_HPP


#include <view/opengl_interfacing/mesh.hpp>
#include <model/entity.hpp>
#include <model/terrain.hpp>
#include "camera_view.hpp"

class TerrainModelsView : public CameraView
{
protected:
	std::vector<Entity*> entities;
	Terrain* terrain;
public:
	TerrainModelsView(Application *application, Window *window, Terrain* terrain);

	void draw() override;
};


#endif //PROC_GEN_OPENGL_TERRAIN_MODELS_VIEW_HPP
