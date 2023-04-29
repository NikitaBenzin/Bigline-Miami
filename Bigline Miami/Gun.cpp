#include "Gun.h"

// ------------------------------------ PRIVATE FUNCTIONS ------------------------------------ // 

void Gun::initVariables()
{
	pistolAmmo = 6;
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
	sprite.scale(1.25, 1.25);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	// sprite.setRotation(45);
	sprite.setPosition(500, 400);
}

float Gun::getPositionX()
{
	return sprite.getPosition().x;
}

float Gun::getPositionY()
{
	return sprite.getPosition().y;
}

unsigned short Gun::getPistolAmmo()
{
	return pistolAmmo;
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

void Gun::setPistolAmmo(unsigned short pistolAmmo)
{
	this->pistolAmmo = pistolAmmo;
}

void Gun::setPosition(float pos_x, float pos_y)
{
	sprite.setPosition(sf::Vector2f(pos_x, pos_y));
}

void Gun::setRotation(float rotation)
{
	sprite.setRotation(rotation);
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
