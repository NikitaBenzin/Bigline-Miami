#pragma once

#include "Bullet.h"

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

	void makeInvisible();
	void makeVisible();

	void dropTheWeapon(float player_pos_x, float player_pos_y);

	float getBoundsX();
	float getBoundsY();

	void update(sf::Vector2i mousePosition, sf::RenderTarget& target);
	void render(sf::RenderTarget& target);

};
