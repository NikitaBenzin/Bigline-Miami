#include "Knife.h"


void Knife::initVaribles()
{
	time = sf::seconds(0.4f);
}

void Knife::initTexture()
{
	knifeTexture.loadFromFile("textures/knife.png");
}

void Knife::initSprite()
{
	// knife
	knife.setTexture(knifeTexture);
	knife.setScale(1.5, 1.5);
	knife.setOrigin(knife.getLocalBounds().width / 2, knife.getLocalBounds().height / 2);
	knife.setPosition(500, 500);
}

Knife::Knife()
{
	initVaribles();
	initTexture();
	initSprite();
}

Knife::~Knife()
{
}

bool Knife::timer()
{
	static sf::Clock clock;
	time = clock.getElapsedTime();

	if (time.asSeconds() >= 0.5f) {
		clock.restart();
		return true;
	}
	return false;
}

bool Knife::knifeCollision(sf::FloatRect playerBounds)
{
	if (knife.getGlobalBounds().intersects(playerBounds))
	{
		return true;
	}
	return false;
}

void Knife::setKnifeInvisible(bool state)
{
	if (state) this->knife.setScale(0, 0);
	else this->knife.setScale(1.5, 1.5);
}

void Knife::setKnifePosition(float plyerRotation, float pos_x, float pos_y)
{
	this->knife.setRotation(plyerRotation);
	this->knife.setPosition(pos_x, pos_y);
}

void Knife::render(sf::RenderTarget& target)
{
	target.draw(knife);
}
