#include <view/static_camera_controller.hpp>
#include <view/flying_fps_camera_controller.hpp>
#include <view/above_camera_controller.hpp>
#include "view/camera_view.hpp"

CameraView::CameraView(Application *application, Window *window)
: View(application, window), camera(glm::radians(45.0f),
				    static_cast<float>(window->getWidth()) / static_cast<float>(window->getHeight()),
				    .1f, 100.0f)
{
	cameraController = std::make_unique<StaticCameraController>(&camera);
}

void CameraView::setCameraController(CameraControllerType cameraType)
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

void CameraView::setCameraPosition(glm::vec3 position)
{
	camera.setPosition(position);
}

void CameraView::draw()
{
	View::draw();
}

void CameraView::setCameraSpeed(float cameraSpeed)
{
	cameraController->setMovementSpeed(cameraSpeed);
}

void CameraView::setCameraSensitivity(float sensitivity)
{
	cameraController->setRotationSpeed(sensitivity);
}

void CameraView::setCameraFOV(float fov)
{
	camera.setFOV(fov);
}

void CameraView::setCameraAspectRatio(float aspectRatio)
{
	camera.setAspectRatio(aspectRatio);
}

void CameraView::setCameraDrawDistance(float drawDistance)
{
	camera.setFarDraw(drawDistance);
}

void CameraView::setRenderingMode(RenderingMode renderingMode)
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

const glm::vec3& CameraView::getCameraPosition() const
{
	return camera.getPosition();
}
