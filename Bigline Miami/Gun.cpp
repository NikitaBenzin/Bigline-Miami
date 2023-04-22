#include "Gun.h"

// ------------------------------------ PRIVATE FUNCTIONS ------------------------------------ // 

void Gun::initVariables()
{
	//// Init rectangle around player
	//border.setSize(sf::Vector2f(32, 32));
	//border.scale(1.5, 1.5);
	//border.setFillColor(sf::Color::Transparent);
	//border.setOutlineColor(sf::Color::Red);
	//border.setOutlineThickness(2);
}

void Gun::initTexture()
{
	// Load a texture from file
	if (!texture.loadFromFile("textures/pistol-gun.png"))
	{
		std::cout << "ERROR::GUN::INITTEXTURE::Could not load texture file.\n";
	}
}

void Gun::initSprite()
{
	// Set the texture to the sprite
	sprite.setTexture(texture);
	sprite.scale(2.5, 2.5);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	// sprite.setRotation(45);
	sprite.setPosition(500, 400);

	//border.setPosition(sf::Vector2f(getPositionX() - 24, getPositionY() - 24));
}

float Gun::getPositionX()
{
	return sprite.getPosition().x;
}

float Gun::getPositionY()
{
	return sprite.getPosition().y;
}

void Gun::makeInvisible()
{
	sprite.setColor(sf::Color::Transparent);
}

void Gun::makeVisible()
{
	sprite.setColor(sf::Color::White);
}

void Gun::dropTheWeapon(float player_pos_x, float player_pos_y)
{
	sprite.setPosition(sf::Vector2f(player_pos_x, player_pos_y));
}

// -------------------------------- CONSTRUCTOR / DESTRUCTOR -------------------------------- // 


Gun::Gun()
{
	initVariables();
	initTexture();
	initSprite();
}

Gun::~Gun()
{
}

// ------------------------------------ PUBLIC FUNCTIONS ------------------------------------ // 


float Gun::getBoundsX()
{
	//return border.getPosition().x;
	return false;
}

float Gun::getBoundsY()
{
	//return border.getPosition().y;
	return false;
}

// ------------------------------------ UPDATE FUNCTIONS ------------------------------------ // 

void Gun::update(sf::Vector2i mousePosition, sf::RenderTarget& target)
{

}

// ------------------------------------ RENDER ------------------------------------ // 

void Gun::render(sf::RenderTarget& target)
{
	//target.draw(border);
	target.draw(sprite);
}
