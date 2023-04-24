#pragma once

#include <map>
#include <math.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Game
{
private:
	// Variables
	sf::RenderWindow* window;
	sf::Event event;
	sf::CircleShape shape;
	sf::RectangleShape worldBorder;

	// Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	Bullet* bulletFirst;
	sf::Vector2f currVelocity;


	// Player
	Player* player;

	// Enemy
	Enemy* enemy;

	sf::View view;

	sf::Vector2i mousePosition;

	float xForBullet;
	float yForBullet;

	// Private functions
	void initWindow();
	void initTextures();

	void initPlayer();
	void initEnemy();
	void initBullet();

public:
	// Constructor / Destructor
	Game();
	~Game();

	// Public functions
	void run();
	
	void update();
	void updateBullets();
	void updatePollEvents();
	void updateInput();
	

	void render();
};

