#ifndef PROC_GEN_OPENGL_TERRAIN_MODELS_VIEW_HPP
#define PROC_GEN_OPENGL_TERRAIN_MODELS_VIEW_HPP


#include <view/opengl_interfacing/mesh.hpp>
#include <controller/terrain_translator.hpp>
#include "camera_view.hpp"

class TerrainModelsView : public CameraView
{
protected:
	std::vector<std::unique_ptr<Mesh>> models;
	std::unique_ptr<Mesh> terrain;
	TerrainTranslator* terrainTranslator;
public:
	TerrainModelsView(Application *application, Window *window, TerrainTranslator *terrainTranslator);

	void draw() override;

	void updateTerrain(); //this method updates the terrain mesh to terrain in model via terraintranslate; costly operation
};


#endif //PROC_GEN_OPENGL_TERRAIN_MODELS_VIEW_HPP
