#ifndef PROC_GEN_OPENGL_CAMERA_HPP
#define PROC_GEN_OPENGL_CAMERA_HPP


#include <glm/glm.hpp>

class Camera
{
protected:
	float fov; //radians
	float aspectRatio;
	float nearDraw;
	float farDraw;

	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 up;

	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
public:
	//all angles in radians
	Camera(float fov, float aspectRatio, float nearDraw, float farDraw);

	float getFOV() const;
	void setFOV(float fov);

	float getAspectRatio() const;
	void setAspectRatio(float aspectRatio);

	float getNearDraw() const;
	void setNearDraw(float nearDraw);

	float getFarDraw() const;
	void setFarDraw(float farDraw);

	const glm::mat4 &getViewMatrix() const;
	const glm::mat4 &getProjectionMatrix() const;

	const glm::vec3 &getPosition() const;
	const glm::vec3 &getDirection() const;
	const glm::vec3 &getUp() const;
	glm::vec3 getRight();

	void setPosition(const glm::vec3 &position);
	void setDirection(const glm::vec3 &direction, const glm::vec3 &up);

	void move(const float& delta, const glm::vec3& vec);
	void rotate(const float& angle, const glm::vec3& vec);

	void moveX(const float& delta);
	void moveY(const float& delta);
	void moveZ(const float& delta);

	void rotateX(const float& angle); //radians
	void rotateY(const float& angle); //radians
	void rotateZ(const float& angle); //radians
};


#endif //PROC_GEN_OPENGL_CAMERA_HPP
