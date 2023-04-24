#pragma once


#include "Bullet.h"

class Enemy
{
private:
	sf::Sprite sprite;
	sf::Texture texture;


	// Enemy rotation
	float rotation;
	float dx;
	float dy;



	// Privat functions
	void initVariables();
	void initTexture();
	void initSprite();

public:
	// Constructor / Destructor
	Enemy();
	~Enemy();

	float getEnemyPosX();
	float getEnemyPosY();

	void updateEnemyRotation(sf::Vector2f playerPosition);
	void update(sf::Vector2f playerPosition);

	void render(sf::RenderTarget& target);
};

