#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <fstream>

class Bullet
{
private:
	// Variables
	sf::Vector2f direction;
	float movementSpeed;
	float newWidth;
	float newHeight;
	float newX;
	float newY;

public:
	// Constructor / Destructor
	Bullet();
	Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed, float rotation);
	~Bullet();

	// this public variable need for manipulating it from game class (change color, scale...)
	sf::Sprite sprite;

	// Getters
	const sf::FloatRect getBounds() ;
	float getMovementSpeed();

	void update();
	void render(sf::RenderTarget& target);
};

