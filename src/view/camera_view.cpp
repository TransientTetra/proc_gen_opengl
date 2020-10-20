#include <view/opengl_interfacing/first_person_camera.hpp>
#include <view/opengl_interfacing/above_camera.hpp>
#include "view/camera_view.hpp"

CameraView::CameraView(Application *application, Window *window)
: View(application, window)
{
	//todo init camera as static camera as default here
	camera = std::make_unique<FirstPersonCamera>(glm::radians(45.0f),
						     800 / 600, .1f, 100.0f, 2.8f, 0.003f);
}

void CameraView::setCamera(CameraType cameraType)
{
	//todo when camera internals are reworked to not include speed and sensitivity change below
	glm::vec3 position = camera->getPosition();
	switch(cameraType)
	{
		case FPS_CAMERA:
			camera = std::make_unique<FirstPersonCamera>(camera->getFOV(),
							camera->getAspectRatio(), camera->getNearDraw(),
							camera->getFarDraw(), 2.8f, 0.003f);
			break;
		case ABOVE_CAMERA:
			camera = std::make_unique<AboveCamera>(camera->getFOV(),
						       camera->getAspectRatio(), camera->getNearDraw(),
						       camera->getFarDraw(), 2.8f);
			break;
		default:
			break;
	}
	camera->setPosition(position);
}

void CameraView::setCameraPosition(glm::vec3 position)
{
	camera->setPosition(position);
}

void CameraView::draw()
{
	View::draw();
}

void CameraView::setCameraSpeed(float cameraSpeed)
{
	CameraView::cameraSpeed = cameraSpeed;
}

void CameraView::setCameraSensitivity(float sensitivity)
{
	CameraView::sensitivity = sensitivity;
}

void CameraView::setCameraFOV(float fov)
{
	camera->setFOV(fov);
}

void CameraView::setCameraAspectRatio(float aspectRatio)
{
	camera->setAspectRatio(aspectRatio);
}

void CameraView::setCameraDrawDistance(float drawDistance)
{
	camera->setFarDraw(drawDistance);
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
