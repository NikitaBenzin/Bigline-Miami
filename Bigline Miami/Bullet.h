#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <fstream>
class Bullet
{
private:
	

	sf::Vector2f direction;
	float movementSpeed;

	//// Privat functions
	//void initVariables();
	//void initTexture();
	//void initSprite();


public:
	// Constructor / Destructor
	Bullet();
	Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed, float rotation);
	~Bullet();
	sf::Sprite sprite;
	// Accessor
	const sf::FloatRect getBounds() const;

	float getMovementSpeed();

	void update();
	void render(sf::RenderTarget& target);

};

