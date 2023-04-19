#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	

	// Private variables
	float movementSpeed;

	float attackCooldown;
	float attackCooldownMax;

	// Privat functions
	void initVariables();
	void initTexture();
	void initSprite(sf::RenderTarget& window);

public:
	// Constructor / Destructor
	Player(sf::RenderTarget& window);
	~Player();

	// Accessor
	const sf::Vector2f& getPos() const;
	//const sf::FloatRect getBounds() const;

	// Public functions
	void move(const float dirX, const float dirY);
	const bool canAttack();

	
	void updateAttack();
	void updatePlayerRotation();
	void update();
	void render(sf::RenderTarget& target);

};

