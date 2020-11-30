#include <iostream>
#include <view/terrain_control_frame.hpp>
#include "view/demo1_main_scene.hpp"
#include "controller/application.hpp"
#include <view/camera_control_frame.hpp>
#include <view/erosion_control_frame.hpp>
#include <view/flying_fps_camera_controller.hpp>
#include <view/above_camera_controller.hpp>
#include <view/static_camera_controller.hpp>

Demo1MainScene::Demo1MainScene(Application* application, Window* window,
			       WorldManipulator* modelManipulator, Terrain* terrain)
: Scene3D(application, window, terrain), inputProcessor(cameraController.get()), fpsCamera(camera),
	aboveCamera(camera), staticCamera(camera)
{
	light = std::make_unique<LightSource>(glm::vec3(4.0f, 5.0f, 10.0f), glm::vec3(1.0f, 1.0f, 1.0f));

	frames.emplace_back(std::make_unique<TerrainControlFrame>(this, "Generation Control", 0, 0, modelManipulator));
	frames.emplace_back(std::make_unique<CameraControlFrame>(this, "Camera Control", frames[0]->getWidth(), 0));
	frames.emplace_back(std::make_unique<ErosionControlFrame>(this, "Erosion Control", 0,
							   frames[0]->getHeight(), modelManipulator));

	currType = STATIC_CAMERA;
	aboveCamera.setPosition(glm::vec3(0, 10, 0));
	fpsCamera.setPosition(glm::vec3(0, 1, 10));
}

void Demo1MainScene::processEvents(SDL_Event &event)
{
	inputProcessor.setCameraController(cameraController.get());
	inputProcessor.processKeyboardEvent(event);
	inputProcessor.processMouseEvent(event);
}

void Demo1MainScene::draw()
{
	inputProcessor.updateController(cameraController.get(), application->getLastFrameDuration());
	Scene3D::draw();

	terrain->getMesh()->draw(camera.getViewMatrix(), camera.getProjectionMatrix(), camera.getPosition(), *light);
	for (auto&& entity : entities)
	{
		entity->getMesh()->draw(camera.getViewMatrix(), camera.getProjectionMatrix(), camera.getPosition(), *light);
	}
}

Demo1MainScene::~Demo1MainScene()
{

}

void Demo1MainScene::setCameraController(CameraControllerType cameraType)
{
	float mvSp = cameraController->getMovementSpeed();
	float rotSp = cameraController->getRotationSpeed();
	switch(currType)
	{
		case FPS_CAMERA:
			fpsCamera = camera;
			break;
		case ABOVE_CAMERA:
			aboveCamera = camera;
			break;
		case STATIC_CAMERA:
			staticCamera = camera;
			break;
	}
	switch(cameraType)
	{
		case FPS_CAMERA:
			camera = fpsCamera;
			cameraController = std::make_unique<FlyingFPSCameraController>(&camera, mvSp, rotSp);
			break;
		case ABOVE_CAMERA:
			camera = aboveCamera;
			cameraController = std::make_unique<AboveCameraController>(&camera, mvSp, rotSp);
			break;
		default:
		case STATIC_CAMERA:
			camera = staticCamera;
			cameraController = std::make_unique<StaticCameraController>(&camera);
			break;
	}
	currType = cameraType;
}
