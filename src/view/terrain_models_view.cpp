#include "view/terrain_models_view.hpp"

TerrainModelsView::TerrainModelsView(Application *application, Window *window, TerrainTranslator *terrainTranslator)
: CameraView(application, window), terrainTranslator(terrainTranslator)
{
}

void TerrainModelsView::draw()
{
	CameraView::draw();
}

void TerrainModelsView::updateTerrain()
{
	terrainTranslator->updateMesh(terrain.get());
}
