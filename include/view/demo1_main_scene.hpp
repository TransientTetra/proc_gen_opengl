#ifndef PROC_GEN_OPENGL_DEMO1_MAIN_SCENE_HPP
#define PROC_GEN_OPENGL_DEMO1_MAIN_SCENE_HPP


#include <view/opengl_interfacing/mesh.hpp>
#include <memory>
#include <view/opengl_interfacing/vertex_shader.hpp>
#include <view/opengl_interfacing/fragment_shader.hpp>
#include <view/opengl_interfacing/shader_program.hpp>
#include <view/opengl_interfacing/camera.hpp>
#include <controller/world_manipulator.hpp>
#include "view.hpp"
#include "camera_view.hpp"
#include "terrain_models_view.hpp"
#include "standard_fps_movement.hpp"

//the main view of the scene; the view where entities are rendered and where player can move and terrain is rendered
class Demo1MainScene : public TerrainModelsView
{
private:
	StandardFPSMovement inputProcessor;
public:
	Demo1MainScene(Application* application, Window* window,
		WorldManipulator* modelManipulator, Terrain* terrain);
	void processEvents(SDL_Event& event) override;
	virtual ~Demo1MainScene();

	void draw() override;
};


#endif //PROC_GEN_OPENGL_DEMO1_MAIN_SCENE_HPP
