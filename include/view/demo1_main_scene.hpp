#ifndef PROC_GEN_OPENGL_DEMO1_MAIN_SCENE_HPP
#define PROC_GEN_OPENGL_DEMO1_MAIN_SCENE_HPP


#include <model/opengl_interfacing/mesh.hpp>
#include <memory>
#include <model/opengl_interfacing/vertex_shader.hpp>
#include <model/opengl_interfacing/fragment_shader.hpp>
#include <model/opengl_interfacing/shader_program.hpp>
#include <model/opengl_interfacing/camera.hpp>
#include <controller/world_manipulator.hpp>
#include "view.hpp"
#include "scene_3d.hpp"
#include "standard_fps_movement.hpp"

//the main view of the scene; the view where entities are rendered and where player can move and terrain is rendered
class Demo1MainScene : public Scene3D
{
private:
	StandardFPSMovement inputProcessor;
	//below cameras for keeping each config
	Camera aboveCamera;
	Camera fpsCamera;
	Camera staticCamera;
	CameraControllerType currType;
public:
	Demo1MainScene(Application* application, Window* window,
		WorldManipulator* modelManipulator, Terrain* terrain);

	void setCameraController(CameraControllerType cameraType) override;

	void processEvents(SDL_Event& event) override;
	virtual ~Demo1MainScene();

	void draw() override;
};


#endif //PROC_GEN_OPENGL_DEMO1_MAIN_SCENE_HPP
