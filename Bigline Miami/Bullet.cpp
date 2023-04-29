#include "Bullet.h"

// Constructors / Destructor
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

const sf::FloatRect Bullet::getBounds() const
{
	return sprite.getGlobalBounds();
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
