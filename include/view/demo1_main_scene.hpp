#ifndef PROC_GEN_OPENGL_DEMO1_MAIN_SCENE_HPP
#define PROC_GEN_OPENGL_DEMO1_MAIN_SCENE_HPP


#include <view/opengl_interfacing/mesh.hpp>
#include <memory>
#include <view/opengl_interfacing/vertex_shader.hpp>
#include <view/opengl_interfacing/fragment_shader.hpp>
#include <view/opengl_interfacing/shader_program.hpp>
#include <view/opengl_interfacing/camera.hpp>
#include <controller/world_manipulator.hpp>
#include <controller/terrain_translator.hpp>
#include "view.hpp"

//the main view of the scene; the view where entities are rendered and where player can move and terrain is rendered
class Demo1MainScene : public View
{
private:
	std::vector<std::unique_ptr<Mesh>> models;
	std::unique_ptr<Mesh> terrain;
	TerrainTranslator* terrainTranslator;
	std::unique_ptr<Camera> camera;

	int terrainFrameIndex;
	bool relativeMouseMode;

public:
	Demo1MainScene(Application* application, Window* window,
		WorldManipulator* modelManipulator, TerrainTranslator* terrainTranslator);
	void processEvents(SDL_Event& event) override;
	virtual ~Demo1MainScene();

	void draw() override;

	void addModel(std::unique_ptr<Mesh> model);
};


#endif //PROC_GEN_OPENGL_DEMO1_MAIN_SCENE_HPP
