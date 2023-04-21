#include "Game.h"


// ------------------------------------ PRIVATE FUNCTIONS ------------------------------------ // 

void Game::initWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Bigline Miami");
    window->setFramerateLimit(60);

    // создание вида
    //view.zoom(2);

    // Initializing world Border
    worldBorder.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    worldBorder.setFillColor(sf::Color::Transparent);
    worldBorder.setOutlineColor(sf::Color::Black);
    worldBorder.setOutlineThickness(1);

    // view.reset(sf::FloatRect(0,0,640,480));

}


void Game::initPlayer()
{
    player = new Player(*window);

    shape.setRadius(100.f);
    shape.setFillColor(sf::Color::Green);
}

// -------------------------------- CONSTRUCTOR / DESTRUCTOR -------------------------------- // 

Game::Game()
{
    initWindow();
    initPlayer();
}

Game::~Game()
{
    delete player;
    delete window;
}

// ------------------------------------ PUBLIC FUNCTIONS ------------------------------------ // 

void Game::run()
{
    while (window->isOpen())
    {
        update();
        render();
    }
}

// ------------------------------------ UPDATE FUNCTIONS ------------------------------------ // 
/**
*   @ return void
*   - update all staff
*/
void Game::update()
{
    updatePollEvents();

    //updateInput();

    mousePosition = sf::Mouse::getPosition(*window);
    player->update(mousePosition, *window, view);


}

void Game::updatePollEvents()
{
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
        else if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
            window->close();
    }
}

void Game::updateInput()
{
    
}



// ------------------------------------ RENDER ------------------------------------ // 
/**
*   @ return void
*   - render all staff
*/
void Game::render()
{
    window->clear(sf::Color::White);

	// Draw staff here...
    player->render(*window);
    window->draw(worldBorder);
    window->draw(shape);

	window->display();
}
