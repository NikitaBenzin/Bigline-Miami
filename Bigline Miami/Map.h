#pragma once

#include "Bullet.h"

class Map
{
private:

	static const short columns = 13;
	static const short rows = 7;
	int id = 0;

	sf::Texture ground, corner, wall, entrance, window;

	/*
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
	char map[rows][columns] =
	{
		(char)218, (char)209, (char)25, (char)209, (char)191, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		(char)27, (char)218, (char)209, (char)191, (char)182, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		(char)199, (char)192, (char)223, (char)217, (char)182, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		(char)199, ' ', ' ', ' ', (char)222, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		(char)27, ' ', ' ', ' ', (char)182, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		(char)192, (char)207, (char)24, (char)207, (char)217, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
	};

	sf::Sprite *mapParts[rows * columns];

	void initTexture();
	void initMapParts();
	void initMap();

public:
	Map();
	~Map();


	void update();
	void render(sf::RenderTarget& target);

};

