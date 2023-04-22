#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Gun
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	// Create the rectangle around gun sprite
	//sf::RectangleShape border;

	// Private variables


	// Privat functions
	void initVariables();
	void initTexture();
	void initSprite();


public:
	// Constructor / Destructor
	Gun();
	~Gun();

	// Public functions
	float getPositionX();
	float getPositionY();

	float getBoundsX();
	float getBoundsY();

	void update(sf::Vector2i mousePosition, sf::RenderTarget& target);
	void render(sf::RenderTarget& target);

};
