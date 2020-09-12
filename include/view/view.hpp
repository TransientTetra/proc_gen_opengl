#ifndef CPP_GUI_TEMPLATE_VIEW_HPP
#define CPP_GUI_TEMPLATE_VIEW_HPP


#include <vector>
#include <view/frame.hpp>
#include <view/opengl_interfacing/camera.hpp>

class View
{
protected:
	std::vector<Frame> frames;

    Camera* camera;
    float cameraSpeed;
    glm::vec3* cameraPos;
    glm::vec3* cameraFront;
    glm::vec3* cameraUp;
public:
    View();
	//draw has to be called at the start of the overridden method
	virtual void draw();
	//render has to be called at the end of the overridden method
	virtual void render();

    Camera* getCamera();
    float getCameraSpeed();
    glm::vec3* getCameraPos();
    glm::vec3* getCameraFront();
    glm::vec3* getCameraUp();
    void changeCameraPos(const glm::vec3 &changeVector);
};


#endif //CPP_GUI_TEMPLATE_VIEW_HPP
