#ifndef PROC_GEN_OPENGL_MAIN_SCENE_VIEW_HPP
#define PROC_GEN_OPENGL_MAIN_SCENE_VIEW_HPP


#include <view/opengl_interfacing/mesh.hpp>
#include <memory>
#include <view/opengl_interfacing/vertex_shader.hpp>
#include <view/opengl_interfacing/fragment_shader.hpp>
#include <view/opengl_interfacing/shader_program.hpp>
#include <view/opengl_interfacing/camera.hpp>
#include <view/opengl_interfacing/above_camera.hpp>
#include "view.hpp"

//the main view of the scene; the view where entities are rendered and where player can move and terrain is rendered
class MainSceneView : public View
{
private:
	std::vector<std::unique_ptr<Mesh>> models;

public:
	MainSceneView();
	void processEvents(SDL_Event& event) override;
	virtual ~MainSceneView();

	void draw() override;
	void render() override;

	void addModel(std::unique_ptr<Mesh> model);
};


#endif //PROC_GEN_OPENGL_MAIN_SCENE_VIEW_HPP
