#include "Game.h"


int main()
{
    Game game;
    game.run();

    return 0;
}
//
//#include <SFML/Graphics.hpp>
//#include <iostream>
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
//    window.setFramerateLimit(60);
//
//    // создаем красный и синий квадраты
//    sf::RectangleShape redSquare(sf::Vector2f(50, 50));
//    redSquare.setFillColor(sf::Color::Red);
//    redSquare.setPosition(100, 100);
//
//    sf::RectangleShape blueSquare(sf::Vector2f(50, 50));
//    blueSquare.setFillColor(sf::Color::Blue);
//    blueSquare.setPosition(500, 300);
//    sf::Clock clock;
//    float deltaTime = clock.restart().asSeconds();
//    // устанавливаем скорость красного квадрата
//    float redSpeed = 100;
//    float blueSpeed = 150;
//    while (window.isOpen())
//    {
//        // обработка событий
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//            {
//                window.close();
//            }
//        }
//
//
//        deltaTime = clock.restart().asSeconds();
//        // вычисляем направление движения красного квадрата
//        sf::Vector2f direction = blueSquare.getPosition() - redSquare.getPosition();
//        float length = sqrt(direction.x * direction.x + direction.y * direction.y);
//        if (length > 0)
//        {
//            direction /= length;
//        }
//
//        // перемещаем красный квадрат в направлении синего квадрата
//        redSquare.move(direction * redSpeed * deltaTime);
//
//        // обрабатываем нажатия клавиш для перемещения синего квадрата
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//        {
//            blueSquare.move(-blueSpeed * deltaTime, 0);
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//        {
//            blueSquare.move(blueSpeed * deltaTime, 0);
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//        {
//            blueSquare.move(0, -blueSpeed * deltaTime);
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//        {
//            blueSquare.move(0, blueSpeed * deltaTime);
//        }
//
        // // проверяем столкновение красного и синего квадрата
        //if (redSquare.getGlobalBounds().intersects(blueSquare.getGlobalBounds()))
        //{
        //    std::cout << "Collision!" << std::endl;
        //}
//
//        // очищаем окно и рисуем объекты
//        window.clear(sf::Color::White);
//        window.draw(redSquare);
//        window.draw(blueSquare);
//        window.display();
//    }
//
//    return 0;
//}
