#include "Map.h"

// ------------------------------------ PRIVATE FUNCTIONS ------------------------------------ // 

void Map::initVariables()
{
	selectedLevel = 1;
}

void Map::initTexture()
{
	ground.loadFromFile("./textures/map-sheet.png", sf::IntRect(0, 0, 32, 32));
	corner.loadFromFile("./textures/map-sheet.png", sf::IntRect(32, 0, 32, 32));
	wall.loadFromFile("./textures/map-sheet.png", sf::IntRect(64, 0, 32, 32));
	entrance.loadFromFile("./textures/map-sheet.png", sf::IntRect(96, 0, 32, 32));
	window.loadFromFile("./textures/map-sheet.png", sf::IntRect(128, 0, 32, 32));
}

void Map::initMapParts()
{
	for (int i = 0; i < columns*rows; i++)
	{
		mapParts[i] = new sf::Sprite;
	}
}

void Map::initMap()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			//1 - player
			//2 - enemy

			//' ' - clear space
			if (map[i][j] == ' ')
			{
				mapParts[id]->setPosition(j * 128, i * 128);
				mapParts[id]->setTexture(ground);
				mapParts[id]->setScale(4, 4);
				++id;
			}
			//218 - to right top corner
			else if (map[i][j] == (char)218)
			{
				mapParts[id]->setPosition(j * 128, i * 128);
				mapParts[id]->setTexture(corner);
				mapParts[id]->setScale(4, 4);
				++id;
			}
			//191 - to bottom top corner
			else if (map[i][j] == (char)191)
			{
				mapParts[id]->setPosition(j * 128 + 128, i * 128);
				mapParts[id]->setTexture(corner);
				mapParts[id]->setRotation(90);
				mapParts[id]->setScale(4, 4);
				++id;
			}
			//217 - to top bottom corner
			else if (map[i][j] == (char)217)
			{
				mapParts[id]->setPosition(j * 128 + 128, i * 128 + 128);
				mapParts[id]->setTexture(corner);
				mapParts[id]->setRotation(180);
				mapParts[id]->setScale(4, 4);
				++id;
			}
			//192 - to right bottom corner
			else if (map[i][j] == (char)192)
			{
				mapParts[id]->setPosition(j * 128, i * 128 + 128);
				mapParts[id]->setTexture(corner);
				mapParts[id]->setRotation(270);
				mapParts[id]->setScale(4, 4);
				++id;
			}
			//199 - left wall
			else if (map[i][j] == (char)199)
			{
				mapParts[id]->setPosition(j * 128, i * 128);
				mapParts[id]->setTexture(wall);
				mapParts[id]->setScale(4, 4);
				++id;
			}
			//207 - bottom wall
			else if (map[i][j] == (char)207)
			{
				mapParts[id]->setPosition(j * 128, i * 128 + 128);
				mapParts[id]->setTexture(wall);
				mapParts[id]->setRotation(270);
				mapParts[id]->setScale(4, 4);
				++id;
			}
			//209 - top wall
			else if (map[i][j] == (char)209)
			{
				mapParts[id]->setPosition(j * 128 + 128, i * 128);
				mapParts[id]->setTexture(wall);
				mapParts[id]->setRotation(90);
				mapParts[id]->setScale(4, 4);
				++id;
			}
			//182 - right wall
			else if (map[i][j] == (char)182)
			{
				mapParts[id]->setPosition(j * 128 + 128, i * 128 + 128);
				mapParts[id]->setTexture(wall);
				mapParts[id]->setRotation(180);
				mapParts[id]->setScale(4, 4);
				++id;
			}
			//24 - bottom window
			else if (map[i][j] == (char)24)
			{
				mapParts[id]->setPosition(j * 128, i * 128 + 128);
				mapParts[id]->setTexture(window);
				mapParts[id]->setRotation(270);
				mapParts[id]->setScale(4, 4);
				++id;
			}
			//25 - top window
			else if (map[i][j] == (char)25)
			{
				mapParts[id]->setPosition(j * 128 + 128, i * 128);
				mapParts[id]->setTexture(window);
				mapParts[id]->setRotation(90);
				mapParts[id]->setScale(4, 4);
				++id;
			}
			//26 - right window
			else if (map[i][j] == (char)26)
			{
				mapParts[id]->setPosition(j * 128, i * 128);
				mapParts[id]->setTexture(window);
				mapParts[id]->setRotation(180);
				mapParts[id]->setScale(4, 4);
				++id;
			}
			//27 - left window
			else if (map[i][j] == (char)27)
			{
				mapParts[id]->setPosition(j * 128, i * 128);
				mapParts[id]->setTexture(window);
				mapParts[id]->setScale(4, 4);
				++id;
			}
			//221 - left entrance
			else if (map[i][j] == (char)221)
			{
				mapParts[id]->setPosition(j * 128, i * 128);
				mapParts[id]->setTexture(entrance);
				mapParts[id]->setScale(4, 4);
				++id;
			}
			//222 - right entrance
			else if (map[i][j] == (char)222)
			{
				mapParts[id]->setPosition(j * 128 + 128, i * 128 + 128);
				mapParts[id]->setTexture(entrance);
				mapParts[id]->setRotation(180);
				mapParts[id]->setScale(4, 4);
				++id;
			}
			//220 - top entrance
			else if (map[i][j] == (char)220)
			{
				mapParts[id]->setPosition(j * 128, i * 128);
				mapParts[id]->setTexture(entrance);
				mapParts[id]->setRotation(90);
				mapParts[id]->setScale(4, 4);
				++id;
			}
			//223 - bottom entrance
			else if (map[i][j] == (char)223)
			{
				mapParts[id]->setPosition(j * 128, i * 128 + 128);
				mapParts[id]->setTexture(entrance);
				mapParts[id]->setRotation(270);
				mapParts[id]->setScale(4, 4);
				++id;
			}
		}

	}
}

void Map::initWalls()
{
	for (int i = 0; i < mapItems; i++)
	{
		mapRectangles[i] = new sf::RectangleShape;
		mapRectangles[i]->setFillColor(sf::Color::Black);
	}
}

void Map::setWalls()
{
	if (selectedLevel == 1)
	{
		mapRectangles[0]->setSize(sf::Vector2f(380, 40));
		mapRectangles[0]->setPosition(0, 600);

		mapRectangles[1]->setSize(sf::Vector2f(40, 350));
		mapRectangles[1]->setPosition(350, 600);

		mapRectangles[2]->setSize(sf::Vector2f(40, 900));
		mapRectangles[2]->setPosition(600, 250);

		mapRectangles[3]->setSize(sf::Vector2f(40, 500));
		mapRectangles[3]->setPosition(1000, 600);

		mapRectangles[4]->setSize(sf::Vector2f(400, 40));
		mapRectangles[4]->setPosition(1000, 600);

		mapRectangles[5]->setSize(sf::Vector2f(40, 425));
		mapRectangles[5]->setPosition(1475, 0);

		mapRectangles[6]->setSize(sf::Vector2f(400, 40));
		mapRectangles[6]->setPosition(1590, 600);

	}
	else if (selectedLevel == 2)
	{
		mapRectangles[0]->setSize(sf::Vector2f(40, 625));
		mapRectangles[0]->setPosition(200, 265);

		mapRectangles[1]->setSize(sf::Vector2f(450, 40));
		mapRectangles[1]->setPosition(200, 265);

		mapRectangles[2]->setSize(sf::Vector2f(40, 445));
		mapRectangles[2]->setPosition(610, 275);

		mapRectangles[3]->setSize(sf::Vector2f(450, 40));
		mapRectangles[3]->setPosition(200, 850);

		mapRectangles[4]->setSize(sf::Vector2f(40, 900));
		mapRectangles[4]->setPosition(940, 260);

		mapRectangles[5]->setSize(sf::Vector2f(40, 625));
		mapRectangles[5]->setPosition(1300, 260);

		mapRectangles[6]->setSize(sf::Vector2f(650, 40));
		mapRectangles[6]->setPosition(1300, 260);
	}
	else if (selectedLevel == 3)
	{
		mapRectangles[0]->setSize(sf::Vector2f(300, 40));
		mapRectangles[0]->setPosition(0, 510);

		mapRectangles[1]->setSize(sf::Vector2f(40, 550));
		mapRectangles[1]->setPosition(450, 0);

		mapRectangles[2]->setSize(sf::Vector2f(40, 550));
		mapRectangles[2]->setPosition(450, 700);
					  
		mapRectangles[3]->setSize(sf::Vector2f(1100, 40));
		mapRectangles[3]->setPosition(900, 510);

		mapRectangles[4]->setSize(sf::Vector2f(40, 325));
		mapRectangles[4]->setPosition(1200, 185);

		mapRectangles[5]->setSize(sf::Vector2f(40, 325));
		mapRectangles[5]->setPosition(1500, 510);

		mapRectangles[6]->setSize(sf::Vector2f(450, 40));
		mapRectangles[6]->setPosition(1200, 185);
	}
}

// -------------------------------- CONSTRUCTOR / DESTRUCTOR -------------------------------- // 

Map::Map()
{
	initVariables();
	initWalls();
}

Map::~Map()
{
	//for (int i = 0; i < columns * rows; i++)
	//{
	//	delete mapParts[i];
	//}

	for (int i = 0; i < 1; i++)
	{
		delete mapRectangles[i];
	}
}

// ------------------------------------ PUBLIC FUNCTIONS ------------------------------------ // 

void Map::setLevel(short selectedLevel)
{
	this->selectedLevel = selectedLevel;
	setWalls();
}

// ------------------------------------ UPDATE FUNCTIONS ------------------------------------ // 

bool Map::updateWallCollision(sf::FloatRect bounds)
{
	for (int i = 0; i < mapItems; i++)
	{
		// Collision enemy view wuth walls
		if (bounds.intersects(mapRectangles[i]->getGlobalBounds()))
		{
			return true;
		}
	}
	return false;
}

bool Map::updateWallCollision(float pos_x, float pos_y)
{
	for (int i = 0; i < mapItems; i++)
	{
		// Collision with wall
		if (pos_x > mapRectangles[i]->getPosition().x
			&& pos_x < mapRectangles[i]->getPosition().x + mapRectangles[i]->getSize().x
			&& pos_y > mapRectangles[i]->getPosition().y
			&& pos_y < mapRectangles[i]->getPosition().y + mapRectangles[i]->getSize().y)
		{
			return true;
		}
	}
	return false;
}

/**
*	- this update function is only for player
*/
short Map::updateCollisionDiraction(float pos_x, float pos_y, sf::FloatRect bounds)
{
	for (int i = 0; i < mapItems; i++)
	{
		if (bounds.intersects(mapRectangles[i]->getGlobalBounds()))
		{


			if (pos_x > mapRectangles[i]->getPosition().x)
			{
				// Left
				if (pos_x + 6 > mapRectangles[i]->getPosition().x + mapRectangles[i]->getSize().x)
				{
					return 2;
				}
				// bottom
				else if (pos_y > mapRectangles[i]->getPosition().y)
				{
					// top
					if (pos_y + 6 < mapRectangles[i]->getPosition().y + mapRectangles[i]->getSize().y)
					{
						return 4;
					}
					else return 3;
				}
				else return 1;
			}

		}
	}

	return 0;
}

void Map::update(sf::FloatRect player_bounds)
{
}

// ------------------------------------ RENDER ------------------------------------ //

void Map::render(sf::RenderTarget& target)
{
	for (int i = 0; i < mapItems; i++)
	{
		target.draw(*mapRectangles[i]);
	}
}
