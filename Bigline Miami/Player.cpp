#include "Player.h"

// ------------------------------------ PRIVATE FUNCTIONS ------------------------------------ // 

void Player::initVariables()
{
	this->movementSpeed = 10.f;
}

void Player::initTexture()
{
	// Load a texture from file
	if (!texture.loadFromFile("textures/player.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file.\n";
	}
}

void Player::initSprite(sf::RenderTarget& window)
{
	// Set the texture to the sprite
	sprite.setTexture(texture);

	// Resize the sprite
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	sprite.scale(3, 3);
	sprite.setOrigin(sf::Vector2f(16.f, 16.f));
	sprite.setPosition(sf::Vector2f(window.getSize().x / 2 - 32, window.getSize().y / 2 - 32));
}

// -------------------------------- CONSTRUCTOR / DESTRUCTOR -------------------------------- // 

Player::Player(sf::RenderTarget& window)
{
	this->initVariables();
	this->initTexture();
	this->initSprite(window);
}

Player::~Player()
{

}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

// ------------------------------------ PUBLIC FUNCTIONS ------------------------------------ // 

void Player::move(const float dirX, const float dirY)
{
	sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const bool Player::canAttack()
{
	return false;
}

// ------------------------------------ UPDATE FUNCTIONS ------------------------------------ // 

void Player::updateAttack()
{

}

void Player::updatePlayerRotation()
{

}

void Player::update()
{
	updatePlayerRotation();
}

// ------------------------------------ RENDER ------------------------------------ // 

void Player::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}
