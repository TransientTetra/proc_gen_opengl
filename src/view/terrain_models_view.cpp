#include "view/terrain_models_view.hpp"

TerrainModelsView::TerrainModelsView(Application *application, Window *window, TerrainTranslator *terrainTranslator)
: CameraView(application, window), terrainTranslator(terrainTranslator)
{
	terrain = std::make_unique<Mesh>(std::vector<Vertex>(), std::vector<unsigned int>(), GL_STATIC_DRAW);
	updateTerrain();
}

void TerrainModelsView::draw()
{
	CameraView::draw();
}

void TerrainModelsView::updateTerrain()
{
	terrainTranslator->updateMesh(terrain.get());
}
