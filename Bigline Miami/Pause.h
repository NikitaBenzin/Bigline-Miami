#pragma once

#include "Gun.h"

class Pause
{
private:
	bool pause;
	bool quit;

	sf::Sprite* pauseBg;
	sf::Texture bgTexture;
	sf::Texture* btnsTexture;
	std::vector<sf::RectangleShape*> btns;
	sf::Color hoverColor;

	void initVariables();
	void initBtns();

public:
	Pause();
	~Pause();

	void setPause(bool pause);
	bool getPause();
	bool getQuit();

	void updateEvents();
	void update();
	void render(sf::RenderTarget& target);
};

