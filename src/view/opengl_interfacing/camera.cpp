#include <glm/ext.hpp>
#include "view/opengl_interfacing/camera.hpp"

Camera::Camera(float fov, float aspectRatio, float nearDraw, float farDraw)
: fov(fov), aspectRatio(aspectRatio), nearDraw(nearDraw), farDraw(farDraw)
{
	position = glm::vec3(.0f, .0f, .0f);
	direction = glm::vec3(.0f, .0f, -1.0f);
	forward = glm::vec3(.0f, .0f, -1.0f);
	up = glm::vec3(.0f, 1.0f, .0f);
	projectionMatrix = glm::perspective(fov, aspectRatio, nearDraw, farDraw);

	viewMatrix = glm::lookAt(position, direction, up);

	movingForward = false;
	movingBackward = false;
	movingLeft = false;
	movingRight = false;
	movingUp = false;
	movingDown = false;
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

void Camera::setPosition(const glm::vec3 &position)
{
	direction += (position - Camera::position);
	Camera::position = position;
	viewMatrix = glm::lookAt(position, direction, up);
}

void Camera::setDirection(const glm::vec3 &direction, const glm::vec3 &up)
{
	Camera::direction = direction;
	forward = glm::normalize(Camera::direction - Camera::position);
	Camera::up = up;
	viewMatrix = glm::lookAt(position, direction, up);
}

void Camera::setForward(const glm::vec3 &forward, const glm::vec3 &up)
{
	Camera::forward = forward;
	Camera::direction = position + forward;
	Camera::up = up;
	viewMatrix = glm::lookAt(position, direction, up);
}

void Camera::startMovingForward()
{
	movingForward = true;
}

void Camera::stopMovingForward()
{
	movingForward = false;
}

void Camera::startMovingBackward()
{
	movingBackward = true;
}

void Camera::stopMovingBackward()
{
	movingBackward = false;
}

void Camera::startMovingLeft()
{
	movingLeft = true;
}

void Camera::stopMovingLeft()
{
	movingLeft = false;
}

void Camera::startMovingRight()
{
	movingRight = true;
}

void Camera::stopMovingRight()
{
	movingRight = false;
}

void Camera::startMovingUp()
{
	movingUp = true;
}

void Camera::stopMovingUp()
{
	movingUp = false;
}

void Camera::startMovingDown()
{
	movingDown = true;
}

void Camera::stopMovingDown()
{
	movingDown = false;
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
