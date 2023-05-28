#pragma once

#include "Bullet.h"

class Map
{
private:
	// Private variables
	static const short columns = 1;
	static const short rows = 1;
	static const short mapItems = 7;
	int id = 0;

	short selectedLevel = 1;

	sf::Texture ground, corner, wall, entrance, window;

	/*
		For craeting map in two level array
		After creating a map, call initTexture,initMap and initMapParts
		in constructor =D

		218 - to right top corner	
		191 - to bottom top corner  
		192 - to right bottom corner
		217 - to top bottom corner 

		199 - left wall 
		207 - bottom wall 
		209 - top wall 
		182 - right wall

		24 - bottom window
		25 - top window
		26 - right window
		27 - left window

		1 - player
		2 - enemy

		221 - left entrance
		222 - right entrance
		220 - top entrance
		223 - bottom entrance

		' ' - clear space
	*/
	char map[rows][columns] = {0};

	sf::Sprite *mapParts[rows * columns];

	sf::RectangleShape* mapRectangles[mapItems];

	// Private functions
	void initVariables();
	void initTexture();
	void initMapParts();
	void initMap();
	void initWalls();

	void setWalls();

public:
	Map();
	~Map(); 

	void setLevel(short selectedLevel);

	bool updateWallCollision(sf::FloatRect bounds);
	bool updateWallCollision(float pos_x, float pos_y);
	short updateCollisionDiraction(float pos_x, float pos_y, sf::FloatRect bounds);
	void update(sf::FloatRect player_bounds);

	void render(sf::RenderTarget& target);

};

