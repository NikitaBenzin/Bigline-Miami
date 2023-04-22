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
    shape.setRadius(100.f);
    shape.setFillColor(sf::Color::Green);
}

void Game::initTextures()
{
    textures["BULLET"] = new sf::Texture();
    textures["BULLET"]->loadFromFile("textures/bullet.png");
}


void Game::initPlayer()
{
    player = new Player(*window);
}



// -------------------------------- CONSTRUCTOR / DESTRUCTOR -------------------------------- // 

Game::Game()
{
    initWindow();
    initTextures();
    initPlayer();
}

Game::~Game()
{
    delete player;
    delete window;

    // Delete textures
    for (auto &i : textures)
    {
        delete i.second;
    }
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

    //gun->update(mousePosition, *window);
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

    window->draw(shape);

	window->display();
}
