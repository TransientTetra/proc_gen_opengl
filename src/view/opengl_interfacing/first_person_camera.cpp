#include <glm/ext.hpp>
#include <cstdio>
#include <sdl2/include/SDL2/SDL_quit.h>
#include <sdl2/include/SDL2/SDL_mouse.h>
#include "view/opengl_interfacing/first_person_camera.hpp"

FirstPersonCamera::FirstPersonCamera(float fov, float aspectRatio, float nearDraw, float farDraw, float speed)
	: Camera(fov, aspectRatio, nearDraw, farDraw)
{
	FirstPersonCamera::speed = speed;
	position = glm::vec3(.0f, .0f, .0f);
	direction = glm::vec3(.0f, -1.0f, .0f);
	up = glm::vec3(.0f, .0f, -1.0f);

	viewMatrix = glm::lookAt(position, direction, up);

	yaw = 90.0f;
	pitch = .0f;
	sensitivity = .1f;

	relativeMouseMode = true;
	SDL_SetRelativeMouseMode(SDL_TRUE);
}

void FirstPersonCamera::moveForward(float frameTime)
{
	setPosition(getPosition() + forward * speed * frameTime);
	setDirection(position + forward, up);
}

void FirstPersonCamera::moveBackward(float frameTime)
{
	setPosition(getPosition() + forward * speed * frameTime * -1.0f);
	setDirection(position + forward, up);
}

void FirstPersonCamera::moveLeft(float frameTime)
{

}

void FirstPersonCamera::moveRight(float frameTime)
{

}

void FirstPersonCamera::moveUp(float frameTime)
{

}

void FirstPersonCamera::moveDown(float frameTime)
{

}

void FirstPersonCamera::rotate(float xoffset, float yoffset)
{
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if(pitch > 89.0f)
		pitch = 89.0f;
	if(pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

//	printf("direction (x = %f, y = %f, z = %f)\n", direction.x, direction.y, direction.z);

	// TODO this up vector is shit
	glm::vec3 directionNorm = glm::normalize(direction);
	glm::vec3 cameraRight = glm::normalize(glm::cross(getUp(), directionNorm));
	glm::vec3 cameraUp = glm::cross(directionNorm, cameraRight);
	setForward(directionNorm, cameraUp);

//	printf("rotation (pitch = %f, yaw = %f)\n", pitch, yaw);
}

void FirstPersonCamera::move(float frameTime)
{
	if(!movingForward || !movingBackward)
	{
		if(movingForward)
		{
			moveForward(frameTime);
		}
		else if(movingBackward)
		{
			moveBackward(frameTime);
		}
	}
}

void FirstPersonCamera::toggleMouseRelativity()
{
	if(relativeMouseMode) {
		SDL_SetRelativeMouseMode(SDL_FALSE);
		relativeMouseMode = false;
	}
	else {
		SDL_SetRelativeMouseMode(SDL_TRUE);
		relativeMouseMode = true;
	}
}