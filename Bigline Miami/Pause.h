#pragma once

#include "Gun.h"

class Pause
{
private:
	// Private variables
	bool pause;
	bool quit;

	sf::Sprite* pauseBg;
	sf::Texture bgTexture;
	sf::Texture* btnsTexture;
	std::vector<sf::RectangleShape*> btns;
	sf::Color hoverColor;

	// Private functions
	void initVariables();
	void initBtns();

public:
	Pause();
	~Pause();

	// Public functions
	void setPause(bool pause);
	void setQiut(bool quit);

	bool getPause();
	bool getQuit();

	void updateEvents();
	void update();
	void render(sf::RenderTarget& target);
};

