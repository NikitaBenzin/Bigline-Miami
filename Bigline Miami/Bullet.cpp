#include "Bullet.h"

// -------------------------------- CONSTRUCTOR / DESTRUCTOR -------------------------------- //
Bullet::Bullet()
{
}

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

const sf::FloatRect Bullet::getBounds() 
{
	newWidth = sprite.getGlobalBounds().width / 2.0f;
	newHeight = sprite.getGlobalBounds().height / 2.0f;
	newX = sprite.getGlobalBounds().left + sprite.getGlobalBounds().width / 4.0f;
	newY = sprite.getGlobalBounds().top + sprite.getGlobalBounds().height / 4.0f;

	return sf::FloatRect(sf::Vector2f(newX, newY), sf::Vector2f(newWidth, newHeight));
}

float Bullet::getMovementSpeed()
{
	return movementSpeed;
}

// update
void Bullet::update()
{
	// Movemet
	sprite.move(movementSpeed * direction);
}

// render
void Bullet::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}
