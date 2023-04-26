#include "Game.h"

using namespace sf;
// ------------------------------------ PRIVATE FUNCTIONS ------------------------------------ // 

void Game::initVariables()
{
    currVelocity = sf::Vector2f(0.f, 0.f);

    // Initializing world Border
    worldBorder.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    worldBorder.setFillColor(sf::Color::Transparent);
    worldBorder.setOutlineColor(sf::Color::Black);
    worldBorder.setOutlineThickness(1);

    // view.reset(sf::FloatRect(0,0,640,480));
    shape.setRadius(100.f);
    shape.setFillColor(sf::Color::Green);
    
    playerDead = false;

    time = sf::seconds(0.1f);
}

void Game::initWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Bigline Miami");
    window->setFramerateLimit(60);
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

void Game::initEnemy()
{
    enemy = new Enemy;
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

/**
*   @ return void
*   - restart function
*   - delete player and enemy and re-create it
*/
void Game::restart()
{
    delete player;
    delete enemy;

    initPlayer();
    initEnemy();
    
    playerDead = false;
}



// -------------------------------- CONSTRUCTOR / DESTRUCTOR -------------------------------- // 

Game::Game()
{
    initWindow();
    initVariables();
    initTextures();
    initPlayer();
    initEnemy();
    initBullet();
}

Game::~Game()
{
    delete player;
    delete enemy;
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

void Game::updateGameIvents(sf::Vector2f playerPosition, sf::FloatRect bounds)
{
    // Kill the player if player was attacked by enemy
    if (enemy->updateEnemyMove(playerPosition, bounds))
    {
        //std::cout << "Player DEAD!!!!\n";
        enemy->enemyAttackAnimation();
        player->setTexture(0, 97, 32, 32);
        enemy->stop();
        playerDead = true;
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

    if (!playerDead)
    {
        updateInput();


        mousePosition = sf::Mouse::getPosition(*window);
        player->update(mousePosition, *window, view);
        enemy->update(sf::Vector2f(player->getPlayerCoordinateX(), player->getPlayerCoordinateY()), player->getPlayerGlobalBounds());

        updateBullets();

        updateGameIvents(sf::Vector2f(player->getPlayerCoordinateX(), player->getPlayerCoordinateY()), player->getPlayerGlobalBounds());
    }
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
        else if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::R)
            if (playerDead) restart();
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
                9.f,
                player->getRotation()));
           
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

    enemy->render(*window);

    for (auto* bullet : bullets)
    {
        bullet->render(*window);
    }

    //window->draw(shape);

	window->display();
}
