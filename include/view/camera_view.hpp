#ifndef PROC_GEN_OPENGL_CAMERA_VIEW_HPP
#define PROC_GEN_OPENGL_CAMERA_VIEW_HPP


#include <view/opengl_interfacing/camera.hpp>
#include "view.hpp"
#include "camera_controller_type.hpp"
#include "rendering_mode.hpp"
#include "camera_controller.hpp"

class CameraView : public View
{
protected:
	Camera camera;
	std::unique_ptr<CameraController> cameraController;
public:
	CameraView(Application *application, Window *window);

	void draw() override;

	void setRenderingMode(RenderingMode renderingMode);

	void setCameraController(CameraControllerType cameraType);
	void setCameraPosition(glm::vec3 position);
	const glm::vec3& getCameraPosition() const;
	void setCameraSpeed(float cameraSpeed);
	void setCameraAspectRatio(float aspectRatio);
	void setCameraDrawDistance(float drawDistance);

	void setCameraSensitivity(float sensitivity);
	void setCameraFOV(float fov); //radians
};


#endif //PROC_GEN_OPENGL_CAMERA_VIEW_HPP
