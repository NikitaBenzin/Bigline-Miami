#pragma once

#include "Bullet.h"

class Gun
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	unsigned short pistolAmmo;

	// Privat functions
	void initVariables();
	void initTexture();
	void initSprite();

public:
	// Constructor / Destructor
	Gun();
	~Gun();

	// Public functions
	void setPistolAmmo(unsigned short pistolAmmo);
	void setPosition(float pos_x, float pos_y);
	void setRotation(float rotation);

	float getPositionX();
	float getPositionY();
	unsigned short getPistolAmmo();

	bool gunCollision(sf::FloatRect bounds);
	void makeInvisible();
	void makeVisible();
	void dropTheWeapon(float player_pos_x, float player_pos_y);

	void render(sf::RenderTarget& target);
};
