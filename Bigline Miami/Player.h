#pragma once

#include "Gun.h"

class Player
{
private:
	sf::Sprite sprite;
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
	float rotation;
	float dx;
	float dy;

	sf::Clock attackTimer;
	sf::Int32 attackTimerMax;
	sf::Int32 knifeAttackTimerMax;

	// Private variables
	float movementSpeed;

	
	int currentFrame = 0; // current frame index 
	float elapsedTime = 0.0f; // elipsed time

	
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;

	// Privat functions
	void initVariables();
	void initTexture();
	void initSprite(sf::RenderTarget& window);

	// Weapon section
	void initWeapon();

public:
	// Constructor / Destructor
	Player(sf::RenderTarget& window);
	~Player();

	bool timer(sf::Time& time);

	// Public functions
	void move(const float dirX, const float dirY);

	unsigned short getGunAmmo();
	float getPlayerCoordinateX();
	float getPlayerCoordinateY();
	
	float getRotation();

	sf::Vector2f getAimDirNorm();

	void setPlayerPosition(float pos_x, float pos_y);
	void setTexture(int rectLeft, int rectTop, int rectWidth, int rectHeight);

	void setWithKnife(bool withKnife);

	// Actions with weapon
	bool weaponCollision();
	void knifeAttackAnimation();
	void attackAnimation();
	const bool getAttackTimer();
	const bool getAttackTimer(sf::Int32 TimerMax);
	const bool canAttack();
	bool WithWeapon();
	bool WithKnife();

	sf::FloatRect getPlayerGlobalBounds();

	void walkAnimation();

	void updateAttack();
	void updateAnimation(sf::RenderTarget& window, sf::View view);
	void updatePlayerRotation(sf::Vector2i mousePosition);
	void updateMousePos(sf::Vector2i mousePosition);
	void update(sf::Vector2i mousePosition, sf::RenderTarget& target, sf::View view);

	void render(sf::RenderTarget& target);

};

