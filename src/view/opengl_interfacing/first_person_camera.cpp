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

	angle = 0.0f;
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
	glm::vec3 _up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraRight = glm::normalize(glm::cross(_up, forward));
	setPosition(getPosition() + cameraRight * speed * frameTime);
}

void FirstPersonCamera::moveRight(float frameTime)
{
	glm::vec3 _up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraRight = glm::normalize(glm::cross(_up, forward));
	setPosition(getPosition() + cameraRight * speed * frameTime * -1.0f);
}

void FirstPersonCamera::moveUp(float frameTime)
{
	setPosition(getPosition() + glm::vec3(.0f, 1.0f, .0f) * speed * frameTime);
}

void FirstPersonCamera::moveDown(float frameTime)
{
	setPosition(getPosition() + glm::vec3(.0f, 1.0f, .0f) * speed * frameTime * -1.0f);
}

void FirstPersonCamera::rotateX(float xoffset)
{
	static const glm::vec3 _up(0.0f, 1.0f, 0.0f);

	glm::mat4 rotation = glm::rotate(-xoffset * sensitivity, _up);

	glm::vec3 newForward = glm::vec3(glm::normalize(rotation * glm::vec4(forward, 0.0)));
	glm::vec3 newUp = glm::vec3(glm::normalize(rotation * glm::vec4(up, 0.0)));
	setForward(newForward, newUp);
}

void FirstPersonCamera::rotateY(float yoffset)
{
	angle += yoffset;

	// TODO improve this code after deciding what to do with forward vector
	if(angle > .0f) {
		angle = .0f;
	}
	else if(angle < -600.0f) {
		angle = -600.0f;
	}
	else {
		glm::vec3 right = glm::normalize(glm::cross(up, forward));

		glm::vec3 newForward = glm::vec3(glm::normalize(glm::rotate(yoffset * sensitivity, right) * glm::vec4(forward, 0.0)));
		glm::vec3 newUp = glm::normalize(glm::cross(forward, right));
		setForward(newForward, newUp);
	}

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