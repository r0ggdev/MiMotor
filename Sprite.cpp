#include "Sprite.h"
#include "Vertex.h"
#include "ImageLoader.h"
#include <cstddef>

Sprite::Sprite()
{
	vboID = 0;
}

Sprite::~Sprite()
{
}

void Sprite::init(float x, float y, int width, int height, string texturePath)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	if (vboID == 0) {
		glGenBuffers(1, &vboID);
	}
	texture = ImageLoader::loadPNG(texturePath);


	/*
	float vertexData[12];
	vertexData[0] = x + width;
	vertexData[1] = y + height;

	vertexData[2] = x;
	vertexData[3] = y + height;

	vertexData[4] = x;
	vertexData[5] = y ;

	vertexData[6] = x;
	vertexData[7] = y;

	vertexData[8] = x + width;
	vertexData[9] = y;

	vertexData[10] = x + width;
	vertexData[11] = y + height;
	*/

	Vertex vertexData[6];
	vertexData[0].setPosition(x + width, y + height);
	vertexData[1].setPosition(x, y + height);
	vertexData[2].setPosition(x, y);
	vertexData[3].setPosition(x, y);
	vertexData[4].setPosition(x + width, y);
	vertexData[5].setPosition(x + width, y + height);

	for (int i = 0; i < 6; i++) {
		vertexData[i].setColor(255, 0, 124, 0);
	}
	vertexData[1].setColor(225, 12, 163, 0);
	vertexData[4].setColor(135, 42, 15, 0);


	vertexData[0].setUV(1.0f, 1.0f);
	vertexData[1].setUV(0.0f, 1.0f);
	vertexData[2].setUV(0.0f, 0.0f);
	vertexData[3].setUV(0.0f, 0.0f);
	vertexData[4].setUV(1.0f, 0.0f);
	vertexData[5].setUV(1.0f, 1.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void Sprite::draw()
{
	// Vertex
	// -> Position
	// -> Color
	glBindTexture(GL_TEXTURE_2D, texture.id);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),(void*)offsetof(Vertex, position));
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
