#include <glm/ext.hpp>
#include <sdl2/include/SDL2/SDL_quit.h>
#include <sdl2/include/SDL2/SDL_mouse.h>
#include "view/opengl_interfacing/above_camera.hpp"

AboveCamera::AboveCamera(float fov, float aspectRatio, float nearDraw, float farDraw, float speed)
	: Camera(fov, aspectRatio, nearDraw, farDraw)
{
	AboveCamera::speed = speed;
	position = glm::vec3(.0f, .0f, .0f);
	direction = glm::vec3(.0f, -1.0f, .0f);
	up = glm::vec3(.0f, .0f, -1.0f);

	viewMatrix = glm::lookAt(position, direction, up);

	SDL_SetRelativeMouseMode(SDL_FALSE);
	relativeMouseMode = false;
}

void AboveCamera::moveForward(float frameTime)
{
	setPosition(getPosition() + glm::vec3(.0f, .0f, 1.0f) * speed * frameTime * -1.0f);
}

void AboveCamera::moveBackward(float frameTime)
{
	setPosition(getPosition() + glm::vec3(.0f, .0f, 1.0f) * speed * frameTime);
}

void AboveCamera::moveLeft(float frameTime)
{
	setPosition(getPosition() + glm::vec3(1.0f, .0f, .0f) * speed * frameTime * -1.0f);
}

void AboveCamera::moveRight(float frameTime)
{
	setPosition(getPosition() + glm::vec3(1.0f, .0f, .0f) * speed * frameTime);
}

void AboveCamera::moveUp(float frameTime)
{
	setPosition(getPosition() + glm::vec3(.0f, 1.0f, .0f) * speed * frameTime * -1.0f);
}

void AboveCamera::moveDown(float frameTime)
{
	setPosition(getPosition() + glm::vec3(.0f, 1.0f, .0f) * speed * frameTime);
}

void AboveCamera::rotate(float xoffset, float yoffset)
{

}

void AboveCamera::move(float frameTime)
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

	if(!movingUp || !movingDown)
	{
		if(movingUp)
		{
			moveUp(frameTime);
		}
		else if(movingDown)
		{
			moveDown(frameTime);
		}
	}

	if(!movingRight || !movingLeft)
	{
		if(movingRight)
		{
			moveRight(frameTime);
		}
		else if(movingLeft)
		{
			moveLeft(frameTime);
		}
	}
}

void AboveCamera::toggleMouseRelativity()
{

}