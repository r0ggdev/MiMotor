#pragma once
#include <GL/glew.h>
#include<string>
#include "GLTexture.h"

using namespace std;

class Sprite
{
private:
	float x;
	float y;
	int width;
	int height;
	GLuint vboID;
	string texturePath;
	GLTexture texture;

public:
	Sprite();
	~Sprite();
	
	void init(float x, float y, int width, int height, string texturePath);
	void draw();
};

