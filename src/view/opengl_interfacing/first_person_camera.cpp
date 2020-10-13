#include <sdl2/include/SDL2/SDL_quit.h>
#include <sdl2/include/SDL2/SDL_mouse.h>
#include "view/opengl_interfacing/first_person_camera.hpp"
#include <glm/gtx/transform.hpp>

FirstPersonCamera::FirstPersonCamera(float fov, float aspectRatio, float nearDraw, float farDraw, float speed, float sensitivity)
	: Camera(fov, aspectRatio, nearDraw, farDraw)
{
	FirstPersonCamera::speed = speed;
	FirstPersonCamera::sensitivity = sensitivity;
	position = glm::vec3(.0f, .0f, .0f);
	direction = glm::vec3(.0f, -1.0f, .0f);
	forward = glm::vec3(.0f, -1.0f, .0f);
	up = glm::vec3(.0f, .0f, -1.0f);

	viewMatrix = glm::lookAt(position, direction, up);
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

void FirstPersonCamera::rotateX(float xoffset)
{
	xoffset *= sensitivity;

	static const glm::vec3 _up(0.0f, 1.0f, 0.0f);

	glm::mat4 rotation = glm::rotate(-xoffset, _up);

	glm::vec3 newForward = glm::vec3(glm::normalize(rotation * glm::vec4(forward, 0.0)));
	glm::vec3 newUp = glm::vec3(glm::normalize(rotation * glm::vec4(up, 0.0)));
	setForward(newForward, newUp);
}

void FirstPersonCamera::rotateY(float yoffset)
{
	yoffset *= sensitivity;

	glm::vec3 right = glm::normalize(glm::cross(up, forward));

	glm::vec3 newForward = glm::vec3(glm::normalize(glm::rotate(yoffset, right) * glm::vec4(forward, 0.0)));
	glm::vec3 newUp = glm::normalize(glm::cross(forward, right));
	setForward(newForward, newUp);
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