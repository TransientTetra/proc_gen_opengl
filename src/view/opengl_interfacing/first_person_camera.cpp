#include <glm/ext.hpp>
#include "view/opengl_interfacing/first_person_camera.hpp"

FirstPersonCamera::FirstPersonCamera(float fov, float aspectRatio, float nearDraw, float farDraw, float speed)
	: Camera(fov, aspectRatio, nearDraw, farDraw)
{
	FirstPersonCamera::speed = speed;
	position = glm::vec3(.0f, .0f, .0f);
	direction = glm::vec3(.0f, -1.0f, .0f);
	up = glm::vec3(.0f, .0f, -1.0f);

	viewMatrix = glm::lookAt(position, direction, up);
}

void FirstPersonCamera::moveForward(float frameTime)
{
	setPosition(getPosition() + glm::vec3(.0f, .0f, 1.0f) * speed * frameTime * -1.0f);
}

void FirstPersonCamera::moveBackward(float frameTime)
{
	setPosition(getPosition() + glm::vec3(.0f, .0f, 1.0f) * speed * frameTime);
}

void FirstPersonCamera::moveLeft(float frameTime)
{
	setPosition(getPosition() + glm::vec3(1.0f, .0f, .0f) * speed * frameTime * -1.0f);
}

void FirstPersonCamera::moveRight(float frameTime)
{
	setPosition(getPosition() + glm::vec3(1.0f, .0f, .0f) * speed * frameTime);
}

void FirstPersonCamera::moveUp(float frameTime)
{
	setPosition(getPosition() + glm::vec3(.0f, 1.0f, .0f) * speed * frameTime * -1.0f);
}

void FirstPersonCamera::moveDown(float frameTime)
{
	setPosition(getPosition() + glm::vec3(.0f, 1.0f, .0f) * speed * frameTime);
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