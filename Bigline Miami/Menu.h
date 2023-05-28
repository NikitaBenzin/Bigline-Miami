#pragma once

#include "Gun.h"

class Menu
{
private:
	// Private variables
	bool gameStart;
	bool gameExit;
	bool gameInfo;
	bool gameSelectLevel;

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

	// For Select Level
	sf::Texture* btnsLevelTexture;
	void openSelectLevel(sf::RenderTarget& target);
	short selectedLevel;

	// Private functions
	void initVariables();
	void initColors();
	void initBtns();

public:
	// Constructor / Destructor
	Menu();
	~Menu();

	// Public functions
	void setGameStart(bool gameStart);
	void setGameSelectedLevel(short selectedLevel);

	bool getGameStart();
	bool getGameExit();
	short getGameSelectedLevel();

	void updateEvents(sf::RenderTarget& target);
	void update(sf::RenderTarget& target);

	void render(sf::RenderTarget& target);
};