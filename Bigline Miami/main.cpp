#include "Game.h"

int main()
{
    Game game;
    game.run();

    return 0;
}



//#include <SFML/Graphics.hpp>
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Scrollbar Example");
//
//    sf::RectangleShape scrollbar(sf::Vector2f(20.f, 400.f));
//    scrollbar.setPosition(780.f, 100.f);
//    scrollbar.setFillColor(sf::Color::White);
//
//    sf::RectangleShape slider(sf::Vector2f(20.f, 80.f));
//    slider.setPosition(780.f, 100.f);
//    slider.setFillColor(sf::Color::Blue);
//
//    sf::RectangleShape content(sf::Vector2f(760.f, 600.f));
//    content.setPosition(20.f, 0.f);
//    content.setFillColor(sf::Color::White);
//
//    sf::RectangleShape square(sf::Vector2f(100.f, 100.f));
//    square.setPosition(50.f, 50.f);
//    square.setFillColor(sf::Color::Red);
//
//    bool isDragging = false;
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            // Обработка событий мыши
//            if (event.type == sf::Event::MouseButtonPressed)
//            {
//                if (event.mouseButton.button == sf::Mouse::Left)
//                {
//                    sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
//                    if (slider.getGlobalBounds().contains(mousePos))
//                        isDragging = true;
//                }
//            }
//            else if (event.type == sf::Event::MouseButtonReleased)
//            {
//                if (event.mouseButton.button == sf::Mouse::Left)
//                    isDragging = false;
//            }
//            else if (event.type == sf::Event::MouseMoved)
//            {
//                if (isDragging)
//                {
//                    sf::Vector2f mousePos = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
//                    float newY = mousePos.y - slider.getSize().y / 2.f;
//                    slider.setPosition(slider.getPosition().x, newY);
//                    content.setPosition(content.getPosition().x, -newY * (content.getSize().y - window.getSize().y) / (scrollbar.getSize().y - slider.getSize().y));
//                }
//            }
//        }
//
//        window.clear();
//        window.draw(scrollbar);
//        window.draw(slider);
//        window.draw(content);
//        window.draw(square);
//        window.display();
//    }
//
//    return 0;
//}


//#include "Game.h"
//
//const short columns = 6;
//const short rows = 6;
//
//int posX = 0;
//int posY = 0;
//
//int id = 0;
//int currentId = id;
//short value;
//int counter = 0;
//
//sf::RectangleShape* walls[columns * rows];
//std::map<int, char> mapLabirint[rows][columns];
//
//bool findEmptySpace()
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			if (mapLabirint[i][j].empty())
//			{
//				posX = i;
//				posY = j;
//				return true;
//			}
//		}
//	}
//	return false;
//}
//
//
//void drawWall(short value)
//{
//
//	switch (value)
//	{
//
//	// top value
//	case 1:
//		walls[id-1]->setSize(sf::Vector2f(50, 100));
//		walls[id-1]->setPosition(posX * 50, posY * 50 - 50);
//		walls[id-1]->setFillColor(sf::Color::Black);
//		break;
//
//	// right value
//	case 2:
//		walls[id - 1]->setSize(sf::Vector2f(100, 50));
//		walls[id - 1]->setPosition(posX * 50, posY * 50 - 50);
//		walls[id - 1]->setFillColor(sf::Color::Black);
//		break;
//
//	// bottom value
//	case 3:
//		walls[id - 1]->setSize(sf::Vector2f(50, 100));
//		walls[id - 1]->setPosition(posX * 50, posY * 50);
//		walls[id - 1]->setFillColor(sf::Color::Black);
//		break;
//
//	// left value
//	case 4:
//		walls[id - 1]->setSize(sf::Vector2f(100, 50));
//		walls[id - 1]->setPosition(posX * 50, posY * 50);
//		walls[id - 1]->setFillColor(sf::Color::Black);
//		break;
//
//	case 5:
//
//		walls[id]->setSize(sf::Vector2f(50, 50));
//		walls[id]->setPosition(posX * 50, posY * 50);
//		walls[id]->setFillColor(sf::Color::Black);
//		walls[id]->setOutlineColor(sf::Color::Black);
//		walls[id]->setOutlineThickness(3);
//
//		break;
//	default:
//		drawWall(value);
//		break;
//	}
//
//}
//
//int main()
//{
//
//	srand(time(NULL));
//	sf::RenderWindow window(sf::VideoMode(1200, 720), "SFML works!");
//
//	sf::RectangleShape priamougolnik;
//	sf::RectangleShape shape1, shape2;
//	priamougolnik.setSize(sf::Vector2f(100, 50));
//	priamougolnik.setPosition(100 - 50, 600);
//	priamougolnik.setFillColor(sf::Color::Red);
//
//	shape1.setSize(sf::Vector2f(50, 50));
//	shape1.setPosition(100, 600);
//	shape1.setOutlineColor(sf::Color::White);
//	shape1.setOutlineThickness(2);
//	shape1.setFillColor(sf::Color::Black);
//
//	shape2.setSize(sf::Vector2f(50, 50));
//	shape2.setPosition(150, 600);
//	shape2.setOutlineColor(sf::Color::White);
//	shape2.setOutlineThickness(2);
//	shape2.setFillColor(sf::Color::Black);
//
//
//	//char labirint[rows][columns] = 
//	//{ 
//	//  ' ', ' ', '#', ' ', ' ', '#',
//	//  '#', '#', ' ', '#', ' ', '#',
//	//  ' ', '#', ' ', '#', ' ', '#',
//	//  ' ', '#', ' ', ' ', '#', '#',
//	//  ' ', '#', ' ', '#', ' ', '#',
//	//  ' ', ' ', '#', '#', ' ', '#',
//	//};
//
//	//char labirint[rows][columns];
//
//	
//
//	for (int i = 0; i < columns*rows; i++)
//	{
//		walls[i] = new sf::RectangleShape;
//		walls[i]->setSize(sf::Vector2f(50, 50));
//		walls[i]->setPosition(posX * 50, posY * 50);
//		walls[i]->setFillColor(sf::Color::Black);
//		walls[i]->setOutlineColor(sf::Color::White);
//		walls[i]->setOutlineThickness(2);
//
//	}
//
//	// GENERATE MAZE
//	mapLabirint[posX][posY].emplace(id, 1);
//	++id;
//
//	while (id != rows * columns)
//	{
//		if (posX != 0 && mapLabirint[posX - 1][posY].empty() ||
//			posY != columns - 1 && mapLabirint[posX][posY + 1].empty() ||
//			posX != rows - 1 && mapLabirint[posX + 1][posY].empty() ||
//			posY != 0 && mapLabirint[posX][posY - 1].empty())
//		{
//
//			value = rand() / 10000 + 1;
//
//			switch (value)
//			{
//				// top value
//			case 1:
//				if (posX != 0 && mapLabirint[posX - 1][posY].empty())
//				{
//					mapLabirint[posX - 1][posY].emplace(id, 179);
//
//					
//
//					--posX;
//					drawWall(value);
//					
//					++counter;
//					++id;
//				}
//				break;
//
//				// right value
//			case 2:
//				if (posY != columns - 1 && mapLabirint[posX][posY + 1].empty())
//				{
//					mapLabirint[posX][posY + 1].emplace(id, 196);
//
//					
//					++posY;
//					drawWall(value);
//					++counter;
//					++id;
//				}
//				break;
//				// bottom value
//			case 3:
//				if (posX != rows - 1 && mapLabirint[posX + 1][posY].empty())
//				{
//					
//					mapLabirint[posX + 1][posY].emplace(id, 193);
//					++posX;
//					drawWall(value);
//					++counter;
//					++id;
//				}
//				break;
//				// left value
//			case 4:
//				if (posY != 0 && mapLabirint[posX][posY - 1].empty())
//				{
//					mapLabirint[posX][posY - 1].emplace(id, 191);
//
//					
//					--posY;
//					drawWall(value);
//					++counter;
//					++id;
//				}
//				break;
//			}
//
//		}
//		else
//		{
//			if (findEmptySpace())
//			{
//				mapLabirint[posX][posY].emplace(id, 22);
//				drawWall(5);
//			
//				++counter;
//				++id;
//			}
//
//		}
//	
//
//	}
//
//	//// INITIALIZE WALLS
//	//id = 0;
//	//for (int i = 0; i < rows; i++)
//	//{
//	//	for (int j = 0; j < columns; j++)
//	//	{
//	//		if (labirint[i][j] == '#')
//	//		{
//	//			walls[id]->setSize(sf::Vector2f(50, 50));
//	//			walls[id]->setPosition(j * 50, i * 50);
//	//			walls[id]->setFillColor(sf::Color::Black);
//	//			walls[id]->setOutlineColor(sf::Color::White);
//	//			walls[id]->setOutlineThickness(2);
//	//			++id;
//	//		}
//	//		else if (labirint[i][j] == 'S')
//	//		{
//	//			walls[id]->setSize(sf::Vector2f(50, 50));
//	//			walls[id]->setPosition(j * 50, i * 50);
//	//			walls[id]->setFillColor(sf::Color::Black);
//	//			walls[id]->setOutlineColor(sf::Color::White);
//	//			walls[id]->setOutlineThickness(2);
//	//			++id;
//	//		}
//	//	}
//	//}
//
//
//	// SFML WORKS
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		window.clear();
//
//		for (int i = 0; i < id; i++)
//		{
//			window.draw(*walls[i]);
//		}
//
//		
//		window.draw(shape1);
//		window.draw(shape2);
//		window.draw(priamougolnik);
//
//		window.display();
//	}
//
//	for (int i = 0; i < columns * rows; i++)
//	{
//		delete walls[i];
//	}
//	return 0;
//}

