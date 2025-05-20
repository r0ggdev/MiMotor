#pragma once
#include <glm/glm.hpp>
#include "SpriteBatch.h"
#include "GLTexture.h"
#include <string>
#include <vector>

#include "Human.h"

using namespace std;

const float AGENT_WIDTH = 60.0f;
const float AGENT_RADIUS = AGENT_WIDTH / 2;

class Entity
{
protected:
	glm::vec2 position;
	float speed;
	void checkTilePosition(const vector<string>& levelData, vector <glm::vec2>&collideTilePosition, float x, float y);

	void collideWithTitle(glm::vec2 titlePos);

public:
	Entity();
	glm::vec2 getPosition()const {
		return position;
	}

	virtual void update(const vector<string>& levelData, vector<Human*>& humans, vector<Zombie*> zombies) = 0;

	void draw(SpriteBatch& spritebatch);

	virtual ~Entity();

	bool collideAgent(Entity* entity);

};