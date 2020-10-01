#ifndef PROC_GEN_OPENGL_ABOVE_CAMERA_HPP
#define PROC_GEN_OPENGL_ABOVE_CAMERA_HPP

#include "camera.hpp"

class AboveCamera : public Camera
{
private:
    float speed;

    bool movingForward = false;
    bool movingBackward = false;
    bool movingLeft = false;
    bool movingRight = false;
    bool movingUp = false;
    bool movingDown = false;
protected:
public:
    //all angles in radians
    AboveCamera(float fov, float aspectRatio, float nearDraw, float farDraw, float speed);

    void moveForward() override;

    void moveBackward() override;

    void moveLeft() override;

    void moveRight() override;

    void moveUp() override;

    void moveDown() override;

    void move() override;

    void setMovingForward(bool movingForward);
    void setMovingBackward(bool movingBackward);
    void setMovingLeft(bool movingLeft);
    void setMovingRight(bool movingRight);
    void setMovingUp(bool movingUp);
    void setMovingDown(bool movingDown);

    float getSpeed() const;
};

#endif //PROC_GEN_OPENGL_ABOVE_CAMERA_HPP
