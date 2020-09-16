#ifndef PROC_GEN_OPENGL_ABOVE_CAMERA_HPP
#define PROC_GEN_OPENGL_ABOVE_CAMERA_HPP

#include "camera.hpp"

class AboveCamera : public Camera
{
private:
    float speed;
protected:
public:
    //all angles in radians
    AboveCamera(float fov, float aspectRatio, float nearDraw, float farDraw, float speed);

    void moveVertically(bool isUp);
    void moveHorizontally(bool isRight);
    void moveDeeper(bool deeper);

    void changePosition(const glm::vec3 &shift);

    const float getSpeed() const;
};

#endif //PROC_GEN_OPENGL_ABOVE_CAMERA_HPP
