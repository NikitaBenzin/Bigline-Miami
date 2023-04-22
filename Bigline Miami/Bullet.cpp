#include "Bullet.h"

// Constructors / Destructor
Bullet::Bullet()
{
}

Bullet::Bullet(sf::Texture& texture, float dir_x, float dir_y, float movement_speed)
{
	sprite.setTexture(texture);
	direction.x = dir_x;
	direction.y = dir_y;
	movementSpeed = movement_speed;
}

Bullet::~Bullet()
{
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
