#pragma once

#include "Gun.h"

class Menu
{
private:
	// Private variables
	bool gameStart;
	bool gameExit;
	bool gameInfo;

	sf::Sprite* mainMenuBg;
	sf::Texture bgTexture;
	sf::Texture* btnsTexture;
	std::vector<sf::RectangleShape*> btns;
	sf::Color hoverColor;

	// For INFO btn
	sf::RectangleShape* infoBg;
	sf::Texture* infoBgTexture;
	void openInfo(sf::RenderTarget& target);
	// scrollbar for info 
	std::vector<sf::RectangleShape*> scrollbar;
	sf::Vector2f mousePos;
	float newY;
	bool isDragging;

	// Private functions
	void initVariables();
	void initColors();
	void initBtns();

public:
	// Constructor / Destructor
	Menu();
	~Menu();

	// Public functions
	bool getGameStart();
	bool getGameExit();

	void updateEvents(sf::RenderTarget& target);
	void update(sf::RenderTarget& target);

	void render(sf::RenderTarget& target);
};