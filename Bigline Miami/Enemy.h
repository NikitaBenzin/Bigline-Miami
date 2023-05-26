#pragma once


#include "Bullet.h"

class Enemy
{
private:

	sf::Sprite sprite;
	sf::Texture texture;
	sf::Clock clock;

	// Create triangle and two rects which will be enemy view
	sf::ConvexShape triangle;
	sf::RectangleShape longView;
	sf::RectangleShape rectangleView;

	// Enemy rotation
	float rotation;
	float dx;
	float dy;

	float movementSpeed;
	bool enemyDead;
	bool enemyCknocked;

	// for animations
	sf::Time deltaTimeForAnim;
	int currentFrame = 0; 
	float elapsedTime = 0.0f; 

	sf::Vector2f direction;
	float deltaTime;
	float length;

	float newWidth;
	float newHeight;
	float newX;
	float newY;

	sf::Clock gameTimer;
	sf::Int32 enemyCknockTime;

	float viewLengthTriangle;
	float viewWidthTriangle;
	float viewLength;
	float viewWidth;

	// Privat functions
	void initVariables();
	void initTexture();
	void initSprite(float pos_x, float pos_y);
	void initTriangle();

public:
	// Constructor / Destructor
	Enemy();
	Enemy(float pos_x, float pos_y, bool is_dead);
	~Enemy();

	// Setters
	void setTexture(int rectLeft, int rectTop, int rectWidth, int rectHeight);
	void setEnemyView(float view_length);
	void setEnemyViewLength(float view_length, float view_width);
	void setRectangleViewSize(float size);
	void setDead(bool dead);
	void setPosition(float pos_x, float pos_y);
	void setCknocked(bool state);

	// Getters
	float getEnemyPosX();
	float getEnemyPosY();
	float getEnemyViewLength();
	float getEnemyViewWidth();
	float getRectangleViewSize();
	float getEnemyViewLengthTriangle();
	float getEnemyViewWidthTriangle();
	bool getCknocked();
	bool getEnemyDead();
	sf::FloatRect getViewRectangleBounds();
	sf::FloatRect getViewRectBounds();
	sf::FloatRect getBounds();
	sf::FloatRect getViewBounds();

	void stop();
	void enemyWalkAnimaton();
	void enemyAttackAnimation();
	const bool timer();
	
	// Update functions
	void updateEnemyDead();
	bool updateEnemyView(sf::FloatRect bounds);
	bool updateEnemyMove(sf::Vector2f playerPosition, sf::FloatRect bounds);
	void updateEnemyRotation(sf::Vector2f playerPosition);
	void update(sf::Vector2f playerPosition, sf::FloatRect bounds);

	void render(sf::RenderTarget& target);
};

