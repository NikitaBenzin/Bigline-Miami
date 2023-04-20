#pragma once

#include "Player.h"

class Game
{
private:
	// Variables
	sf::RenderWindow* window;
	sf::Event event;
	sf::CircleShape shape;
	sf::RectangleShape background;
	// Player
	Player* player;
	
	sf::View view;

	sf::Vector2i mousePosition;

	// Private functions
	void initWindow();
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

