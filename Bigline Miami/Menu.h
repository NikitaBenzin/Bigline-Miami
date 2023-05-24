#pragma once

#include "Gun.h"

class Menu
{
private:
	bool gameStart;
	bool gameExit;
	bool gameInfo;

	sf::Sprite* mainMenuBg;
	sf::Texture bgTexture;
	sf::Texture* btnsTexture;
	std::vector<sf::RectangleShape*> btns;
	sf::Color hoverColor;

	void initVariables();
	void initColors();
	void initBtns();

	// For INFO btn
	sf::RectangleShape* infoBg;
	sf::Texture *infoBgTexture;
	void openInfo(sf::RenderTarget& target);
	// scrollbar for info 
	std::vector<sf::RectangleShape*> scrollbar;
	sf::Vector2f mousePos;
	float newY;
	bool isDragging;

public:
	Menu();
	~Menu();

	bool getGameStart();
	bool getGameExit();

	void updateEvents(sf::RenderTarget& target);
	void update(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

