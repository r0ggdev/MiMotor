#pragma once
#include <SDL3/SDL.h>
#include <GL/eglew.h>
#include <iostream>
#include "Sprite.h"
#include "GLSProgram.h"
#include "InputManager.h"
#include "Camera2D.h"
#include <vector>

using namespace std;

enum class GameState {
	PLAY, EXIT
};


class MainGame
{

private:
	int width;
	int height;
	float time = 0;
	InputManager inputManager;
	Camera2D camera2D;
	Sprite sprite;
	vector<Sprite*> sprites;
	GLSProgram program;
	SDL_Window* window;
	void init();
	void processInput();
	void initShaders();

public:
	MainGame();
	~MainGame();
	GameState gameState;
	void run();
	void update();
	void draw();
};

