#include "Bullet.h"

// -------------------------------- CONSTRUCTOR / DESTRUCTOR -------------------------------- //
/**
*   Bullet class base constructor
*/
Bullet::Bullet()
{
}
/**
*   Bullet class constructor
*	- accept arguments for positioning and moving bullets in the correct diraction
*/
Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed, float rotation)
{
	sprite.setTexture(*texture);

	sprite.setPosition(pos_x, pos_y);
	direction.x = dir_x;
	direction.y = dir_y;
	movementSpeed = movement_speed;
	sprite.setRotation(rotation + 90);
	sprite.setScale(0.55, 0.55);
}

Bullet::~Bullet()
{
}

// ------------------------------------ PUBLIC FUNCTIONS ------------------------------------ //

/**
*   @ return const sf::FloatRect
*	- global bounds of bullet rectangle is bigger 
*	  than bullet sprite, so i set it smaller and return new values of bounds
*/
const sf::FloatRect Bullet::getBounds() 
{
	newWidth = sprite.getGlobalBounds().width / 2.0f;
	newHeight = sprite.getGlobalBounds().height / 2.0f;
	newX = sprite.getGlobalBounds().left + sprite.getGlobalBounds().width / 4.0f;
	newY = sprite.getGlobalBounds().top + sprite.getGlobalBounds().height / 4.0f;

	return sf::FloatRect(sf::Vector2f(newX, newY), sf::Vector2f(newWidth, newHeight));
}

/**
*   @ return float
*	- getter of movement speed of bullet
*/
float Bullet::getMovementSpeed()
{
	return movementSpeed;
}

/**
*   @ return void
*   - update position of bullet
*/
void Bullet::update()
{
	// Movemet
	sprite.move(movementSpeed * direction);
}

/**
*   @ return void
*   - render bullet
*/
void Bullet::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}
