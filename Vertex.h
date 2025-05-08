#pragma once
#include<GL/glew.h>

struct Position {
	float x;
	float y;
};

struct Color {
	GLuint r;
	GLuint g;
	GLuint b;
	GLuint a;
};

struct UV {
	float U;
	float V;
};

struct Vertex {
	Position position;
	Color color;
	UV uv;

	void setUV(float u, float v) {
		uv.U = u;
		uv.V = v;
	}

	void setPosition(float x, float y) {
		position.x = x;
		position.y = y;
	}

	void setColor(GLuint r, GLuint g, GLuint b, GLuint a) {
		color.r = r;
		color.g = g;
		color.b = b;
		color.a = a;
	}
};