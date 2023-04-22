#pragma once

#include <map>
#include "Player.h"

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

	// Player
	Player* player;

	sf::View view;

	sf::Vector2i mousePosition;

	// Private functions
	void initWindow();
	void initTextures();

	void initPlayer();

public:
	// Constructor / Destructor
	Game();
	~Game();

	// Public functions
	void run();
	
	void update();
	void updatePollEvents();
	void updateInput();
	

	void render();
};

