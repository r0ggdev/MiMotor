#include "InputManager.h"


InputManager::InputManager():mouseCorrds(0.0f,0.0f)
{
}

InputManager::~InputManager()
{
}

void InputManager::setMouseCoords(float x, float y)
{
	mouseCorrds.x = x;
	mouseCorrds.y = y;
}

void InputManager::pressKey(unsigned int KeyCode)
{
	keys[KeyCode] = true;
}

void InputManager::releaseKey(unsigned int KeyCode)
{
	keys[KeyCode] = false;
}

bool InputManager::isKeyPressed(unsigned int keyCode)
{
	return false;
}

glm::vec2 InputManager::getMouseCoords()
{
	return glm::vec2();
}
