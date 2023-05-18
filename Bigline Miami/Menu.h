#pragma once

#include "Gun.h"

class Menu
{
private:
	bool gameStart;
	bool gameExit;

	sf::Sprite* mainMenuBg;
	sf::Texture bgTexture;
	sf::Texture* btnsTexture;
	std::vector<sf::RectangleShape*> btns;
	sf::Color hoverColor;

	void initVariables(sf::RenderTarget& target);
	void initColors();
	void initBtns();

public:
	Menu();
	Menu(sf::RenderTarget& target);
	~Menu();

	bool getGameStart();
	bool getGameExit();

	void updateEvents();
	void update();
	void render(sf::RenderTarget& target);
};

