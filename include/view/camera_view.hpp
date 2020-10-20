#ifndef PROC_GEN_OPENGL_CAMERA_VIEW_HPP
#define PROC_GEN_OPENGL_CAMERA_VIEW_HPP


#include <view/opengl_interfacing/camera.hpp>
#include "view.hpp"
#include "camera_type.hpp"
#include "rendering_mode.hpp"

class CameraView : public View
{
protected:
	std::unique_ptr<Camera> camera;
	//todo if new class (e.g. camera controller) is created below variables have to be moved to it
	float cameraSpeed;
	float sensitivity;
public:
	CameraView(Application *application, Window *window);

	void draw() override;

	void setRenderingMode(RenderingMode renderingMode);

	void setCamera(CameraType cameraType);
	void setCameraPosition(glm::vec3 position);
	void setCameraSpeed(float cameraSpeed);
	void setCameraAspectRatio(float aspectRatio);
	void setCameraDrawDistance(float drawDistance);

	void setCameraSensitivity(float sensitivity);
	void setCameraFOV(float fov); //radians
};


#endif //PROC_GEN_OPENGL_CAMERA_VIEW_HPP
