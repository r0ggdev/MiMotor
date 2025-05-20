#include "Camera2D.h"

void Camera2D::init(int screenWidth, int screenHeight) {
	screenHeight = screenHeight;
	screenWidth = screenWidth;
	orthoMatrix = glm::ortho(0.0f, (float)screenWidth,
		0.0f, (float)screenHeight);
}

void Camera2D::update() {
	if (needsUpdateMatrix) {
		glm::vec3 translate(-position.x,
			-position.y, 0.0f);
		cameraMatrix = glm::translate(orthoMatrix, translate);
		//glm::vec3 scale(scale, scale, 0.0f);
		needsUpdateMatrix = false;
	}
}

Camera2D::Camera2D() :scale(1.0f),
screenWidth(500),
screenHeight(500),
cameraMatrix(1.0f)
{
}


Camera2D::~Camera2D()
{
}