#include "Menu.h"

void Menu::initVariables()
{
	gameStart = false;
	gameExit = false;
	gameInfo = false;

	// Background
	bgTexture.loadFromFile("textures/mainMenuBg.png");
	btnsTexture = new sf::Texture;
	btnsTexture->loadFromFile("textures/mainMenuBtns.png");
	mainMenuBg = new sf::Sprite;
	mainMenuBg->setTexture(bgTexture);

	// Info bg
	infoBg = new sf::RectangleShape;
	infoBgTexture = new sf::Texture;
	infoBgTexture->loadFromFile("textures/infoBg.png");
	scrollbar.push_back(new sf::RectangleShape);
	scrollbar.push_back(new sf::RectangleShape);
	isDragging = false;
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

void Menu::openInfo(sf::RenderTarget& target)
{
	// info BG 
	infoBg->setSize(sf::Vector2f(720, 1280));
	infoBg->setOrigin(infoBg->getSize().x / 2, 0);
	infoBg->setPosition(target.getSize().x / 2, 10);
	infoBg->setFillColor(sf::Color(150, 150, 150));
	infoBg->setOutlineColor(sf::Color::Black);
	infoBg->setOutlineThickness(1);
	infoBg->setTexture(infoBgTexture);

	// info scrollbar
	// scrollbar bg
	scrollbar[0]->setSize(sf::Vector2f(25, target.getSize().y - 20));
	scrollbar[0]->setPosition(infoBg->getPosition().x + infoBg->getSize().x/2 + 5, 10);
	scrollbar[0]->setFillColor(sf::Color(150, 150, 150));
	// scrollbar slider
	scrollbar[1]->setSize(sf::Vector2f(25, infoBg->getSize().y / 6));
	scrollbar[1]->setPosition(scrollbar[0]->getPosition().x, scrollbar[0]->getPosition().y);
	scrollbar[1]->setFillColor(sf::Color(139, 30, 30));
	
	// BACK btn
	btns.push_back(new sf::RectangleShape);
	btns[3]->setSize(sf::Vector2f(300, 100));
	btns[3]->setPosition(200, 150);
	btns[3]->setOutlineColor(sf::Color::Black);
	btns[3]->setOutlineThickness(5);
	btns[3]->setTexture(btnsTexture);
	btns[3]->setTextureRect(sf::IntRect(0, 318, 320, 106));
}

void Menu::initColors()
{
	// init Hover Color
	hoverColor = sf::Color(100, 100, 100, 150);
}

Menu::Menu()
{
	initVariables();
	initBtns();
	initColors();
}

Menu::~Menu()
{
	delete mainMenuBg;
	delete infoBg;
	for (short i = 0; i < btns.size(); i++)
	{
		delete btns[i];
	}

	for (short i = 0; i < scrollbar.size(); i++)
	{
		delete scrollbar[i];
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

void Menu::updateEvents(sf::RenderTarget& target)
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
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left) && !gameInfo)
	{
		gameStart = true;
	}

	// EXIT btn 
	if (btns[2]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition()))
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left) && !gameInfo)
	{
		gameExit = true;
	}

	// INFO btn
	if (btns[1]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition()))
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		openInfo(target);
		gameInfo = true;
	}

	if (gameInfo)
	{
		if (scrollbar[1]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) isDragging = true;
		}
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			isDragging = false;
		}
		if (isDragging)
		{
			mousePos = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
			newY = mousePos.y - scrollbar[1]->getSize().y / 2.f;

			if (newY < scrollbar[0]->getPosition().y)
			{
				newY = scrollbar[0]->getPosition().y;
			}
			else if (newY + scrollbar[1]->getSize().y > scrollbar[0]->getPosition().y + scrollbar[0]->getSize().y)
			{
				newY = scrollbar[0]->getPosition().y + scrollbar[0]->getSize().y - scrollbar[1]->getSize().y;
			}
			
			scrollbar[1]->setPosition(scrollbar[0]->getPosition().x, newY);
			infoBg->setPosition(infoBg->getPosition().x, -newY / 4);
		}

		// INFO btn
		if (btns[3]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition()))
			&& sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			gameInfo = false;
		}
	}

}

void Menu::update(sf::RenderTarget& target)
{
	updateEvents(target);
}

void Menu::render(sf::RenderTarget& target)
{
	target.draw(*mainMenuBg);
	if (!gameInfo)
	{
		for (short i = 0; i < 3; i++)
		{
			target.draw(*btns[i]);
		}
	}
	else
	{
		target.draw(*infoBg);
		for (short i = 0; i < scrollbar.size(); i++)
		{
			target.draw(*scrollbar[i]);
		}
		target.draw(*btns[3]);
	}
}
