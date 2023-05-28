#pragma once

#include "Gun.h"

class Player
{
private:
	// Private variables
	sf::Sprite sprite;
	sf::Sprite legs;
	sf::Texture texture;
	sf::Clock clock;

	// Create the rectangle around player sprite
	sf::RectangleShape playerBorder;

	// Create the rectangle around gun sprite
	sf::RectangleShape gunBorder;

	// Weapon
	Gun* gun;

	sf::Time time;
	bool withWeapon;
	bool withKnife;

	float attackCooldown;
	float attackCooldownMax;

	// Player rotation
	sf::Vector2f spritePosition;
	float rotation;
	float dx;
	float dy;

	sf::Clock attackTimer;
	sf::Int32 attackTimerMax;
	sf::Int32 knifeAttackTimerMax;

	float movementSpeed;
	
	int currentFrame = 0; // current frame index 
	float elapsedTime = 0.0f; // elipsed time
	sf::Time deltaTime;
	float deltaTimeSeconds;

	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;

	// Privat functions
	void initVariables();
	void initTexture();
	void initSprite(sf::RenderTarget& window);
	void initWeapon();

public:
	// Constructor / Destructor
	Player(sf::RenderTarget& window);
	~Player();

	// Public functions
	bool timer(sf::Time& time);
	void move(const float dirX, const float dirY);
	void walkAnimation();

	// Actions with weapon
	bool weaponCollision();
	void knifeAttackAnimation();
	void attackAnimation();

	const bool canAttack();
	bool WithWeapon();
	bool WithKnife();

	// Setters
	void setPlayerPosition(float pos_x, float pos_y);
	void setTexture(int rectLeft, int rectTop, int rectWidth, int rectHeight);
	void setWithKnife(bool withKnife);
	void setGunPosition(float pos_x, float pos_y);

	// Getters
	unsigned short getGunAmmo();
	float getPlayerCoordinateX();
	float getPlayerCoordinateY();
	float getRotation();
	const bool getAttackTimer();
	const bool getAttackTimer(sf::Int32 TimerMax);
	sf::FloatRect getPlayerGlobalBounds();
	sf::Vector2f getAimDirNorm();


	void updateAttack();
	void updateAnimation(sf::RenderTarget& window, sf::View view);
	void updatePlayerRotation(sf::Vector2i mousePosition);
	void updateMousePos(sf::Vector2i mousePosition);
	void update(sf::Vector2i mousePosition, sf::RenderTarget& target, sf::View view);

	void render(sf::RenderTarget& target);

};

