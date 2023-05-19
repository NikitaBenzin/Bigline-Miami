#pragma once

#include <map>
#include <math.h>

#include "Menu.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Knife.h"
#include "Map.h"

class Game
{
private:
	// Variables
	sf::RenderWindow* window;
	sf::Event event;
	sf::RectangleShape worldBorder;

	// Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;
	std::string ammo;
	Bullet* bulletFirst;
	sf::Vector2f currVelocity;

	sf::Time time;

	// Menu
	Menu* menu;

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

	// MAP
	Map* map;


	sf::View view;
	sf::Vector2i mousePosition;

	float xForBullet;
	float yForBullet;


	// Private functions
	void initVariables();
	void initWindow();
	void initMenu();
	void initTextures();
	void initEnemies();
	void initText();
	void initPlayer();
	void initKnife();
	void initMap();
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
	void updateEnemiesView();
	

	void render();
};

