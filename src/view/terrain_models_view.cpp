#include "view/terrain_models_view.hpp"

TerrainModelsView::TerrainModelsView(Application *application, Window *window, Terrain* terrain)
: CameraView(application, window), terrain(terrain)
{
}

void TerrainModelsView::draw()
{
	CameraView::draw();
}

