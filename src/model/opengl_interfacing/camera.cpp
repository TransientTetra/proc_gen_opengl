#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>
#include "model/opengl_interfacing/camera.hpp"

Camera::Camera(float fov, float aspectRatio, float nearDraw, float farDraw)
: fov(fov), aspectRatio(aspectRatio), nearDraw(nearDraw), farDraw(farDraw)
{
	position = glm::vec3(.0f, .0f, .0f);
	direction = glm::vec3(.0f, .0f, -1.0f);
	up = glm::vec3(.0f, 1.0f, .0f);
	projectionMatrix = glm::perspective(fov, aspectRatio, nearDraw, farDraw);

	viewMatrix = glm::lookAt(position, direction + position, up);
}

const glm::mat4 &Camera::getViewMatrix() const
{
	return viewMatrix;
}

const glm::mat4 &Camera::getProjectionMatrix() const
{
	return projectionMatrix;
}

const glm::vec3 &Camera::getPosition() const
{
    return position;
}

const glm::vec3 &Camera::getDirection() const
{
    return direction;
}

const glm::vec3 &Camera::getUp() const
{
    return up;
}

glm::vec3 Camera::getRight()
{
	return glm::normalize(glm::cross(direction, up));;
}


void Camera::setPosition(const glm::vec3 &position)
{
	Camera::position = position;
	viewMatrix = glm::lookAt(position, direction + position, up);
}

void Camera::setDirection(const glm::vec3 &direction, const glm::vec3 &up)
{
	Camera::direction = direction;
	Camera::up = up;
	viewMatrix = glm::lookAt(position, direction + position, up);
}

float Camera::getFOV() const
{
	return fov;
}

void Camera::setFOV(float fov)
{
	Camera::fov = fov;
	projectionMatrix = glm::perspective(fov, aspectRatio, nearDraw, farDraw);
}

float Camera::getAspectRatio() const
{
	return aspectRatio;
}

void Camera::setAspectRatio(float aspectRatio)
{
	Camera::aspectRatio = aspectRatio;
	projectionMatrix = glm::perspective(fov, aspectRatio, nearDraw, farDraw);
}

float Camera::getNearDraw() const
{
	return nearDraw;
}

void Camera::setNearDraw(float nearDraw)
{
	Camera::nearDraw = nearDraw;
	projectionMatrix = glm::perspective(fov, aspectRatio, nearDraw, farDraw);
}

float Camera::getFarDraw() const
{
	return farDraw;
}

void Camera::setFarDraw(float farDraw)
{
	Camera::farDraw = farDraw;
	projectionMatrix = glm::perspective(fov, aspectRatio, nearDraw, farDraw);
}

void Camera::move(const float &delta, const glm::vec3 &vec)
{
	position += glm::normalize(vec) * delta;
	viewMatrix = glm::lookAt(position, direction + position, up);
}

void Camera::rotate(const float &angle, const glm::vec3 &vec)
{
	glm::mat4 rotation = glm::rotate(angle, vec);
	direction = glm::vec3(glm::normalize(rotation * glm::vec4(direction, 0.0)));
	up = glm::vec3(glm::normalize(rotation * glm::vec4(up, 0.0)));
	viewMatrix = glm::lookAt(position, direction + position, up);
}