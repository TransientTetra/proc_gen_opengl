#ifndef PROC_GEN_OPENGL_SCENE_3D_HPP
#define PROC_GEN_OPENGL_SCENE_3D_HPP


#include <model/opengl_interfacing/camera.hpp>
#include <model/entity.hpp>
#include <model/terrain.hpp>
#include "view.hpp"
#include "camera_controller_type.hpp"
#include "rendering_mode.hpp"
#include "camera_controller.hpp"

class Scene3D : public View
{
protected:
	Camera camera;
	std::unique_ptr<CameraController> cameraController;
	std::vector<Entity*> entities;
	Terrain* terrain;
	std::unique_ptr<LightSource> light;
public:
	Scene3D(Application *application, Window *window, Terrain* terrain);

	void draw() override;

	virtual void setRenderingMode(RenderingMode renderingMode);

	virtual void setCameraController(CameraControllerType cameraType);
	virtual void setCameraPosition(glm::vec3 position);
	virtual const glm::vec3& getCameraPosition() const;
	virtual void setCameraSpeed(float cameraSpeed);
	virtual void setCameraAspectRatio(float aspectRatio);
	virtual void setCameraDrawDistance(float drawDistance);

	virtual void setCameraSensitivity(float sensitivity);
	virtual void setCameraFOV(float fov); //radians
};


#endif //PROC_GEN_OPENGL_SCENE_3D_HPP
