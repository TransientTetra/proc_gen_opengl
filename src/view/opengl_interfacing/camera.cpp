#include <glm/ext.hpp>
#include "view/opengl_interfacing/camera.hpp"

Camera::Camera(float fov, float aspectRatio, float nearDraw, float farDraw)
{
	position = glm::vec3(.0f, .0f, .0f);
	direction = glm::vec3(.0f, .0f, -1.0f);
	up = glm::vec3(.0f, 1.0f, .0f);
	projectionMatrix = glm::perspective(fov, aspectRatio, nearDraw, farDraw);

	viewMatrix = glm::lookAt(position, direction, up);
}

const glm::mat4 &Camera::getViewMatrix() const
{
	return viewMatrix;
}

const glm::mat4 &Camera::getProjectionMatrix() const
{
	return projectionMatrix;
}
