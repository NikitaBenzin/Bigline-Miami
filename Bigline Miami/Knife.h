#pragma once

#include "Bullet.h"

class Knife
{
private:
	// knife 
	sf::Sprite knife;
	sf::Texture knifeTexture;
	sf::Time time;

	// Privat functions
	void initVaribles();
	void initTexture();
	void initSprite();

public:
	Knife();
	~Knife();

	bool timer();

	bool knifeCollision(sf::FloatRect playerBounds);

	void setKnifeInvisible(bool state);
	void setKnifePosition(float plyerRotation, float pos_x, float pos_y);

	void render(sf::RenderTarget& target);
};

