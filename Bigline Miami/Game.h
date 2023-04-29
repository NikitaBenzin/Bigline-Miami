#pragma once

#include <map>
#include <math.h>


#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Knife.h"

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
	std::string ammo;
	Bullet* bulletFirst;
	sf::Vector2f currVelocity;

	sf::Time time;

	// Fonts
	sf::Font font;
	sf::Text ammoText;
	sf::Text restartText;
	sf::Color mainColor;
	sf::Color mainOutlineColor;


	// Player
	Player* player;
	bool playerDead;

	// Enemy
	Enemy* enemy;
	std::vector<Enemy*> enemies;


	// knife
	Knife* knife;



	sf::View view;
	sf::Vector2i mousePosition;

	float xForBullet;
	float yForBullet;


	// Private functions
	void initVariables();
	void initWindow();
	void initTextures();
	void initEnemies();
	void initText();
	void initPlayer();
	void initKnife();
	
	void initBullet();

	// restart function
	void restart();
	void clearEnemies();

public:
	// Constructor / Destructor
	Game();
	~Game();

	// Public functions
	void run();
	
	

	void updateText();
	void updateGameIvents(sf::Vector2f playerPosition, sf::FloatRect bounds);
	void update();
	void updateBullets();
	void updateEnemies();
	void updatePollEvents();
	void updateInput();
	

	void render();
};

