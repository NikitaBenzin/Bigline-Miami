#include "Game.h"

using namespace sf;
// ------------------------------------ PRIVATE FUNCTIONS ------------------------------------ // 

void Game::initWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Bigline Miami");
    window->setFramerateLimit(60);

    currVelocity = sf::Vector2f(0.f, 0.f);

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

void Game::initBullet()
{
    bulletFirst = (new Bullet(textures["BULLET"],
        player->getPlayerCoordinateX() - 29,
        player->getPlayerCoordinateY() - 74,
        0.f,
        0.f,
        5.f,
        0.f));
}



// -------------------------------- CONSTRUCTOR / DESTRUCTOR -------------------------------- // 

Game::Game()
{
    initWindow();
    initTextures();
    initPlayer();
    initBullet();
}

Game::~Game()
{
    delete player;
    delete bulletFirst;
    delete window;

    // Delete textures
    for (auto &i : textures)
    {
        delete i.second;
    }

    // Delete bullets
    for (auto *i : bullets)
    {
        delete i;
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

    updateInput();
    

    mousePosition = sf::Mouse::getPosition(*window);
    player->update(mousePosition, *window, view);

    updateBullets();
}

void Game::updateBullets()
{
    
    for (size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i]->update();

        if (bullets[i]->sprite.getPosition().x < 0
            || bullets[i]->sprite.getPosition().x > window->getSize().x
            || bullets[i]->sprite.getPosition().y < 0
            || bullets[i]->sprite.getPosition().y > window->getSize().y)
        {
            bullets.erase(bullets.begin() + i);
        }
    }
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
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && player->WithWeapon())
    {
        currVelocity = player->getAimDirNorm() * bulletFirst->getMovementSpeed();
        if (player->canAttack())
        {
            player->setTexture(32, 64, 32, 32);
            bullets.push_back(new Bullet(textures["BULLET"], 
                player->getPlayerCoordinateX() ,
                player->getPlayerCoordinateY() ,
                currVelocity.x, 
                currVelocity.y, 
                5.f,
                player->getRotation()));
            std::cout << player->getRotation() << std::endl;
            std::cout << player->getPlayerCoordinateX() << std::endl;
           
        }
        else player->setTexture(0, 64, 32, 32);
    }
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

    for (auto* bullet : bullets)
    {
        bullet->render(*window);
    }

    //window->draw(shape);

	window->display();
}
