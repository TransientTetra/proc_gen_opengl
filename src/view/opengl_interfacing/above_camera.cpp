#include "view/opengl_interfacing/above_camera.hpp"

AboveCamera::AboveCamera(float fov, float aspectRatio, float nearDraw, float farDraw, float speed)
    : Camera(fov, aspectRatio, nearDraw, farDraw)
{
    AboveCamera::speed = speed;
}

void AboveCamera::moveVertically(bool isUp)
{
    changePosition(speed * up * (isUp ? 1.0f : -1.0f));
}

void AboveCamera::moveHorizontally(bool isRight)
{
    changePosition(glm::normalize(glm::cross(direction, up)) * speed * (isRight ? 1.0f : -1.0f));
}

void AboveCamera::moveDeeper(bool deeper)
{
    changePosition(forward * speed * (deeper ? 1.0f : -1.0f));
}

void AboveCamera::changePosition(const glm::vec3 &shift)
{
    AboveCamera::position = position + shift;
    setDirection(position + forward);
}

const float AboveCamera::getSpeed() const
{
    return speed;
}