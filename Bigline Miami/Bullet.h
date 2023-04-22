#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include <iostream>

class Bullet
{
private:
	sf::Sprite sprite;

	sf::Vector2f direction;
	float movementSpeed;

	//// Privat functions
	//void initVariables();
	//void initTexture();
	//void initSprite();


public:
	// Constructor / Destructor
	Bullet();
	Bullet(sf::Texture& texture, float dir_x, float dir_y, float movement_speed);
	~Bullet();
	

	void update();
	void render(sf::RenderTarget& target);

};

