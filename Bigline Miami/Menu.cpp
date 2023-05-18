#include "Menu.h"

void Menu::initVariables(sf::RenderTarget& target)
{
	gameStart = false;
	gameExit = false;

	// Background
	bgTexture.loadFromFile("textures/mainMenuBg.png");
	btnsTexture = new sf::Texture;
	btnsTexture->loadFromFile("textures/mainMenuBtns.png");
	mainMenuBg = new sf::Sprite;
	mainMenuBg->setTexture(bgTexture);
}

void Menu::initBtns()
{
	for (short i = 0; i < 3; i++)
	{
		btns.push_back(new sf::RectangleShape);
		btns[i]->setSize(sf::Vector2f(300, 100));
		btns[i]->setPosition(200, (i+2) * 150);
		btns[i]->setOutlineColor(sf::Color::Black);
		btns[i]->setOutlineThickness(5);
		btns[i]->setTexture(btnsTexture);
		btns[i]->setTextureRect(sf::IntRect(0, i * 106, 320, 106));
	}
}

void Menu::initColors()
{
	// init Hover Color
	hoverColor = sf::Color(100, 100, 100, 150);
}

Menu::Menu()
{

}

Menu::Menu(sf::RenderTarget& target)
{
	initVariables(target);
	initBtns();
	initColors();
}

Menu::~Menu()
{
	delete mainMenuBg;

	for (short i = 0; i < btns.size(); i++)
	{
		delete btns[i];
	}

}

bool Menu::getGameStart()
{
	return gameStart;
}

bool Menu::getGameExit()
{
	return gameExit;
}

void Menu::updateEvents()
{
	// HOVER EFFECT
	for (short i = 0; i < btns.size(); i++)
	{
		if (btns[i]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			btns[i]->setFillColor(hoverColor);
		}
		else
		{
			// set the color off menu background
			btns[i]->setFillColor(sf::Color(62, 62, 62));
		}
	}

	// NEW GAME btn 
	if (btns[0]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition()))
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		gameStart = true;
	}

	// EXIT btn 
	if (btns[2]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition()))
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		gameExit = true;
	}
}

void Menu::update()
{
	updateEvents();
}

void Menu::render(sf::RenderTarget& target)
{
	target.draw(*mainMenuBg);
	
	for (short i = 0; i < btns.size(); i++)
	{
		target.draw(*btns[i]);
	}
}
