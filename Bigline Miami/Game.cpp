#include "Game.h"


// ------------------------------------ PRIVATE FUNCTIONS ------------------------------------ // 

void Game::initWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(1200, 720), "Bigline Miami");
    window->setFramerateLimit(60);
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
        sf::Vector2i position = sf::Mouse::getPosition();
        //std::cout << position.x << " " << position.y << "\n";
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

    updateInput();

    player->update();
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
    // Move player
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        player->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player->move(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        player->move(0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        player->move(0.f, 1.f);
}



// ------------------------------------ RENDER ------------------------------------ // 
/**
*   @ return void
*   - render all staff
*/
void Game::render()
{
	window->clear();

	// Draw staff here...
    player->render(*window);
    //window->draw(shape);

	window->display();
}
