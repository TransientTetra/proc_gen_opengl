#include <view/static_camera_controller.hpp>
#include <view/flying_fps_camera_controller.hpp>
#include <view/above_camera_controller.hpp>
#include "view/scene_3d.hpp"

Scene3D::Scene3D(Application *application, Window *window, Terrain* terrain)
: View(application, window), terrain(terrain),
	camera(glm::radians(45.0f),
				    static_cast<float>(window->getWidth()) / static_cast<float>(window->getHeight()),
				    .1f, 100.0f)
{
	cameraController = std::make_unique<StaticCameraController>(&camera);
}

void Scene3D::setCameraController(CameraControllerType cameraType)
{
	float mvSp = cameraController->getMovementSpeed();
	float rotSp = cameraController->getRotationSpeed();
	switch(cameraType)
	{
		case FPS_CAMERA:
			cameraController = std::make_unique<FlyingFPSCameraController>(&camera, mvSp, rotSp);
			break;
		case ABOVE_CAMERA:
			cameraController = std::make_unique<AboveCameraController>(&camera, mvSp, rotSp);
			break;
		default:
		case STATIC_CAMERA:
			cameraController = std::make_unique<StaticCameraController>(&camera);
			break;
	}
}

void Scene3D::setCameraPosition(glm::vec3 position)
{
	camera.setPosition(position);
}

void Scene3D::draw()
{
	View::draw();
}

void Scene3D::setCameraSpeed(float cameraSpeed)
{
	cameraController->setMovementSpeed(cameraSpeed);
}

void Scene3D::setCameraSensitivity(float sensitivity)
{
	cameraController->setRotationSpeed(sensitivity);
}

void Scene3D::setCameraFOV(float fov)
{
	camera.setFOV(fov);
}

void Scene3D::setCameraAspectRatio(float aspectRatio)
{
	camera.setAspectRatio(aspectRatio);
}

void Scene3D::setCameraDrawDistance(float drawDistance)
{
	camera.setFarDraw(drawDistance);
}

void Scene3D::setRenderingMode(RenderingMode renderingMode)
{
	switch(renderingMode)
	{
		case WIREFRAME:
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			break;
		case FILLED_WITH_LIGHTING:
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			break;
		default:
			break;
	}
}

const glm::vec3& Scene3D::getCameraPosition() const
{
	return camera.getPosition();
}
