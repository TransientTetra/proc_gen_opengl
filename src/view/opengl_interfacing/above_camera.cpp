#include <cstdio>
#include "view/opengl_interfacing/above_camera.hpp"

AboveCamera::AboveCamera(float fov, float aspectRatio, float nearDraw, float farDraw, float speed)
    : Camera(fov, aspectRatio, nearDraw, farDraw)
{
    AboveCamera::speed = speed;
}

void AboveCamera::moveVertically(bool isUp)
{
    position += glm::vec3(1.0f, .0f, .0f) * speed * (isUp ? -1.0f : 1.0f);
}

void AboveCamera::moveHorizontally(bool isRight)
{
    position += glm::vec3(.0f, .0f, 1.0f) * speed * (isRight ? -1.0f : 1.0f);
}

void AboveCamera::moveDeeper(bool deeper)
{
    position += glm::vec3(.0f, 1.0f, .0f) * speed * (deeper ? -1.0f : 1.0f);
}

void AboveCamera::changePosition()
{
//    setDirection(glm::vec3(position + glm::vec3(.0f, -10.0f, .0f)));
    setDirection(glm::vec3(1.0f, .0f, 2.0f));

    printf("position - x: %f, y: %f, z: %f\n", position.x, position.y, position.z);
//    printf("direction - x: %f, y: %f, z: %f\n", direction.x, direction.y, direction.z);
}

float AboveCamera::getSpeed() const
{
    return speed;
}