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

    // font
    font.loadFromFile("fonts/mainFont.otf");
    mainColor = sf::Color(230, 120, 57);
    mainOutlineColor = sf::Color(33, 24, 27);
} 

void Game::initWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(1700, 800), "Bigline Miami");
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

void Game::initText()
{
    // ammo text
    ammoText.setFont(font);
    ammoText.setCharacterSize(42);
    ammoText.setFillColor(mainColor);
    ammoText.setOutlineThickness(2);
    ammoText.setOutlineColor(mainOutlineColor);
    ammoText.setPosition(50, window->getSize().y - 75);

    // restart Text
    restartText.setFont(font);
    restartText.setCharacterSize(42);
    restartText.setFillColor(mainColor);
    restartText.setOutlineThickness(2);
    restartText.setOutlineColor(mainOutlineColor);
    restartText.setPosition(window->getSize().x / 2 - 175, window->getSize().y / 2 - 50);
}

void Game::initEnemies()
{
    enemy = new Enemy(0, 0, true);
    enemies.push_back(new Enemy(150, 100, false));
    enemies.push_back(new Enemy(150, 400, false));
    enemies.push_back(new Enemy(150, 700, false));
}

void Game::initBullet()
{
    bulletFirst = (new Bullet(textures["BULLET"],
        ammoText.getPosition().x - 35,
        ammoText.getPosition().y + 10,
        0.f,
        0.f,
        5.f,
        270.f));
    bulletFirst->sprite.setScale(1.2,1.2);
    bulletFirst->sprite.setColor(sf::Color::Transparent);
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
    clearEnemies();

    initPlayer();
    initEnemies();
    
    playerDead = false;
    restartText.setString("");
}

void Game::clearEnemies()
{
    enemies.clear();
    // Delete enemies
    for (size_t i = 0; i < enemies.size(); i++)
    {
        delete enemies[i];
    }
}

void Game::initKnife()
{
    knife = new Knife;
}



// -------------------------------- CONSTRUCTOR / DESTRUCTOR -------------------------------- // 

Game::Game()
{
    initWindow();
    initVariables();
    initTextures();
    initText();
    initKnife();
    initPlayer();
    initEnemies();
    initBullet();
}

Game::~Game()
{
    delete player;
    delete knife;
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

    // Delete enemies
    for (auto* i : enemies)
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

    if (!playerDead)
    {
        updateInput();

        mousePosition = sf::Mouse::getPosition(*window);
        player->update(mousePosition, *window, view);

        updateBullets();

        updateGameIvents(sf::Vector2f(player->getPlayerCoordinateX(), player->getPlayerCoordinateY()), player->getPlayerGlobalBounds());
    }

    updateText();
}

void Game::updateGameIvents(sf::Vector2f playerPosition, sf::FloatRect bounds)
{
    for (size_t i = 0; i < enemies.size(); i++)
    {
        // Kill the player if player was attacked by enemy
        if (!enemies[i]->getEnemyDead() && enemies[i]->updateEnemyMove(playerPosition, bounds))
        {
            //std::cout << "Player DEAD!!!!\n";
            player->setTexture(0, 97, 32, 32);

            enemies[i]->stop();

            playerDead = true;
            restartText.setString("Press 'R' to restart");
        }
    }
    
    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right) 
        && knife->knifeCollision(player->getPlayerGlobalBounds()) 
        && knife->timer()
        && !player->WithWeapon())
    {
        knife->setKnifeInvisible(true);
        player->setWithKnife(true);
        player->setTexture(0, 128, 32, 32);
    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Right)
        && knife->timer()
        && player->WithKnife())
    {
        knife->setKnifeInvisible(false);
        knife->setKnifePosition(player->getRotation(), player->getPlayerCoordinateX(), player->getPlayerCoordinateY());
        player->setWithKnife(false);
    }

    
}

void Game::updateBullets()
{
    
    for (size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i]->update();

        // delete bullet if collision with window
        if (bullets[i]->sprite.getPosition().x < 0
            || bullets[i]->sprite.getPosition().x > window->getSize().x
            || bullets[i]->sprite.getPosition().y < 0
            || bullets[i]->sprite.getPosition().y > window->getSize().y)
        {
            bullets.erase(bullets.begin() + i);
        }

        for (size_t j = 0; j < enemies.size(); j++)
        {
            if (!bullets.empty() && enemies[j]->getBounds().intersects(bullets[i]->getBounds()) &&!enemies[j]->getEnemyDead())
            {
                bullets.erase(bullets.begin() + i);
                enemies[j]->setTexture(0, 64, 32, 32);
                enemies[j]->setDead(true);
                
            }
        }

        
    }
    for (size_t i = 0; i < enemies.size(); i++)
    {
        if (!enemies[i]->getEnemyDead())
        {
            enemies[i]->update(sf::Vector2f(player->getPlayerCoordinateX(), player->getPlayerCoordinateY()), player->getPlayerGlobalBounds());
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
                player->getPlayerCoordinateX(),
                player->getPlayerCoordinateY(),
                currVelocity.x,
                currVelocity.y,
                9.f,
                player->getRotation()));

        }
        else player->setTexture(0, 64, 32, 32);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && player->WithKnife())
    {
        for (size_t j = 0; j < enemies.size(); j++)
        {
            if (enemies[j]->getBounds().intersects(player->getPlayerGlobalBounds()) && !enemies[j]->getEnemyDead())
            {
                enemies[j]->setTexture(0, 64, 32, 32);
                enemies[j]->setDead(true);
            }
        }
    }
}


void Game::updateText()
{
    if (player->WithWeapon())
    {
        ammo = std::to_string(player->getGunAmmo());
        ammoText.setString(ammo);
        bulletFirst->sprite.setColor(sf::Color::White);
    }
    else
    {
        // delete text
        ammoText.setString("");
        window->draw(ammoText);
        bulletFirst->sprite.setColor(sf::Color::Transparent);
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

    for (auto* enemy : enemies)
    {
        enemy->render(*window);
    }

    knife->render(*window);

    player->render(*window);

    
    for (auto* bullet : bullets)
    {
        bullet->render(*window);
    }
    bulletFirst->render(*window);
    
    window->draw(ammoText);
    
    window->draw(restartText);

	window->display();
}
