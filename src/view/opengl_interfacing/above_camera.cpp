#include <glm/ext.hpp>
#include "view/opengl_interfacing/above_camera.hpp"

AboveCamera::AboveCamera(float fov, float aspectRatio, float nearDraw, float farDraw, float speed)
	: Camera(fov, aspectRatio, nearDraw, farDraw)
{
	AboveCamera::speed = speed;
	position = glm::vec3(.0f, .0f, .0f);
	direction = glm::vec3(.0f, -1.0f, .0f);
	up = glm::vec3(.0f, .0f, -1.0f);

	viewMatrix = glm::lookAt(position, direction, up);
}

float AboveCamera::getSpeed() const
{
	return speed;
}

void AboveCamera::moveForward()
{
	setPosition(getPosition() + glm::vec3(.0f, .0f, 1.0f) * speed * -1.0f);
}

void AboveCamera::moveBackward()
{
	setPosition(getPosition() + glm::vec3(.0f, .0f, 1.0f) * speed);
}

void AboveCamera::moveLeft()
{
	setPosition(getPosition() + glm::vec3(1.0f, .0f, .0f) * speed * -1.0f);
}

void AboveCamera::moveRight()
{
	setPosition(getPosition() + glm::vec3(1.0f, .0f, .0f) * speed);
}

void AboveCamera::moveUp()
{
	setPosition(getPosition() + glm::vec3(.0f, 1.0f, .0f) * speed * -1.0f);
}

void AboveCamera::moveDown()
{
	setPosition(getPosition() + glm::vec3(.0f, 1.0f, .0f) * speed);
}

void AboveCamera::move()
{
	if(!movingForward || !movingBackward)
	{
		if(movingForward)
		{
			moveForward();
		}
		else if(movingBackward)
		{
			moveBackward();
		}
	}

	if(!movingUp || !movingDown)
	{
		if(movingUp)
		{
			moveUp();
		}
		else if(movingDown)
		{
			moveDown();
		}
	}

	if(!movingRight || !movingLeft)
	{
		if(movingRight)
		{
			moveRight();
		}
		else if(movingLeft)
		{
			moveLeft();
		}
	}
}

void AboveCamera::setMovingForward(const bool movingForward)
{
	this->movingForward = movingForward;
}

void AboveCamera::setMovingBackward(const bool movingBackward)
{
	this->movingBackward = movingBackward;
}

void AboveCamera::setMovingLeft(const bool movingLeft)
{
	this->movingLeft = movingLeft;
}

void AboveCamera::setMovingRight(const bool movingRight)
{
	this->movingRight = movingRight;
}

void AboveCamera::setMovingUp(const bool movingUp)
{
	this->movingUp = movingUp;
}

void AboveCamera::setMovingDown(const bool movingDown)
{
	this->movingDown = movingDown;
}