#include "Pause.h"

// ------------------------------------ PRIVATE FUNCTIONS ------------------------------------ // 

void Pause::initVariables()
{
	pause = false;
	quit = false;

	// Background
	bgTexture.loadFromFile("textures/mainMenuBg.png");
	btnsTexture = new sf::Texture;
	btnsTexture->loadFromFile("textures/mainMenuBtns.png");
	pauseBg = new sf::Sprite;
	pauseBg->setTexture(bgTexture);

	// init Hover Color
	hoverColor = sf::Color(100, 100, 100);
}

void Pause::initBtns()
{
	for (short i = 0; i < 2; i++)
	{
		btns.push_back(new sf::RectangleShape);
		btns[i]->setSize(sf::Vector2f(300, 100));
		btns[i]->setPosition(600, (i + 3) * 150);
		btns[i]->setOutlineColor(sf::Color::Black);
		btns[i]->setOutlineThickness(5);
		btns[i]->setTexture(btnsTexture);
		btns[i]->setTextureRect(sf::IntRect(0, (i + 5) * 106, 320, 106));
	}
}

// -------------------------------- CONSTRUCTOR / DESTRUCTOR -------------------------------- //

Pause::Pause()
{
	initVariables();
	initBtns();
}

Pause::~Pause()
{
	for (short i = 0; i < btns.size(); i++)
	{
		delete btns[i];
	}
}

// ------------------------------------ PUBLIC FUNCTIONS ------------------------------------ // 

void Pause::setPause(bool pause)
{
	this->pause = pause;
}

void Pause::setQiut(bool quit)
{
	this->quit = quit;
}


bool Pause::getPause()
{
	return pause;
}

bool Pause::getQuit()
{
	return quit;
}

// ------------------------------------ UPDATE FUNCTIONS ------------------------------------ //

void Pause::updateEvents()
{
	// HOVER EFFECT
	for (short i = 0; i < btns.size(); i++)
	{
		if (btns[i]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition()))) btns[i]->setFillColor(hoverColor);
		else btns[i]->setFillColor(sf::Color(62, 62, 62));
	}

	// RESUME btn 
	if (btns[0]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition()))
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left) && pause)
	{
		pause = false;
	}

	// QUIT btn
	if (btns[1]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition()))
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left) && pause)
	{
		quit = true;
	}

}

void Pause::update()
{
	updateEvents();
}

// ------------------------------------ RENDER ------------------------------------ // 

void Pause::render(sf::RenderTarget& target)
{
	target.draw(*pauseBg);
	for (short i = 0; i < btns.size(); i++)
	{
		target.draw(*btns[i]);
	}
}
