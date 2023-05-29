#pragma once

#include <SFML/Audio.hpp>

#include <map>
#include <math.h>

#include "Menu.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Knife.h"
#include "Map.h"
#include "Pause.h"

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

	// Music
	sf::Music music;
	sf::Music gameMusic;

	// Fonts
	sf::Font font;
	sf::Text ammoText;
	sf::Text restartText;
	sf::Color mainColor;
	sf::Color mainOutlineColor;
	sf::Text winText;

	// win thing
	sf::Texture arrowTexture;
	sf::Sprite arrow;
	bool gameComplete;

	// Player
	Player* player;
	bool playerDead;

	// Enemies
	Enemy* enemy;
	std::vector<Enemy*> enemies;
	short aliveEnemies;

	// Knife
	Knife* knife;

	// Map
	Map* map;

	// Pause
	Pause* pause;

	// View (i wanted to do screen zoom but mouse positioning is broke every time i change screen view) 
	sf::View view;
	sf::Vector2i mousePosition;

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
	void setEnemies(short selected_level);
public:
	// Constructor / Destructor
	Game();
	~Game();

	// Public functions
	void run();

	void updateMusic();
	void updateText();
	void updateGameIvents(sf::Vector2f playerPosition, sf::FloatRect bounds);
	void updateBullets();
	void updateEnemies();
	void updatePollEvents();
	void updateInput();
	void updateEnemiesView();
	void updateEnemiesWallCollision();
	void update();

	void render();
};

