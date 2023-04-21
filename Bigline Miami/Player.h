#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Clock clock;
	// Create the rectangle around player sprite
	sf::RectangleShape border;


	// Private variables
	float movementSpeed;

	bool isRunning;
	int currentFrame = 0; // òåêóùèé èíäåêñ ñïðàéòà
	float elapsedTime = 0.0f; // ïðîøåäøåå âðåìÿ



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

	float getPlayerCoordinateX();
	float getPlayerCoordinateY();

	void walkAnimation();
	void updateAttack();
	void updateAnimation(sf::RenderTarget& window, sf::View view);
	void updatePlayerRotation(sf::Vector2i mousePosition);
	void update(sf::Vector2i mousePosition, sf::RenderTarget& target, sf::View view);
	void render(sf::RenderTarget& target);

};

