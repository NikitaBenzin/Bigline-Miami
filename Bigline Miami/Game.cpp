#include "Game.h"

// ------------------------------------ PRIVATE FUNCTIONS ------------------------------------ // 
/**
*   @ return void
*   - initialization of all variables which don't have own init func
*/
void Game::initVariables()
{
    currVelocity = sf::Vector2f(0.f, 0.f);

    // Initializing world Border
    worldBorder.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    worldBorder.setFillColor(sf::Color::Transparent);
    worldBorder.setOutlineColor(sf::Color::Black);
    worldBorder.setOutlineThickness(1);

    playerDead = false;

    time = sf::seconds(0.1f);

    // font
    font.loadFromFile("fonts/mainFont.otf");
    mainColor = sf::Color(230, 120, 57);
    mainOutlineColor = sf::Color(33, 24, 27);

    // arrow Go!
    arrowTexture.loadFromFile("./textures/arrow.png");
    arrow.setTexture(arrowTexture);
    arrow.setScale(0.2, 0.2);
} 

/**
*   @ return void
*   - initialization of window and set window frame limit
*/
void Game::initWindow()
{
     window = new sf::RenderWindow(sf::VideoMode::getFullscreenModes()[0], "Bigline Miami", sf::Style::Fullscreen);
    //window = new sf::RenderWindow(sf::VideoMode(1880, 920), "Bigline Miami");
    window->setFramerateLimit(60);
}

/**
*   @ return void
*   - initialization of menu and pause
*/
void Game::initMenu()
{
    menu = new Menu;
    pause = new Pause;
}

/**
*   @ return void
*   - initialization of textures for bullets
*/
void Game::initTextures()
{
    textures["BULLET"] = new sf::Texture();
    textures["BULLET"]->loadFromFile("textures/bullet.png");
}

/**
*   @ return void
*   - initialization of player and set bool variable playerDead to false
*/
void Game::initPlayer()
{
    player = new Player(*window);
}

/**
*   @ return void
*   - initialization of text, font and colors
*/
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

    // win Text 
    winText.setFont(font);
    winText.setCharacterSize(84);
    winText.setFillColor(mainColor);
    winText.setOutlineThickness(2);
    winText.setOutlineColor(mainOutlineColor);
    winText.setPosition(window->getSize().x / 2 - 210, window->getSize().y / 2 - 50);
    winText.setString("LEVEL CLEAR");
}

/**
*   @ return void
*   - initialization of enemies
*   - adding in enemies vector array
*   - also create enemy which is not in array because without this hero game closing when player kill enemies
*/
void Game::initEnemies()
{
    enemy = new Enemy(0, 0, true);
}

/**
*   @ return void
*   - initialization of bullet which is showing when player with gun
*   - decoration thing
*/
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
*   - also set bool playerDead to false and clear restart text
*/
void Game::restart()
{
    delete player;
    delete enemy;
    delete knife;
    clearEnemies();

    initPlayer();
    initEnemies();
    initKnife();

    playerDead = false;
    restartText.setString("");

    setEnemies(menu->getGameSelectedLevel());
}

/**
*   @ return void
*   - clear all enemies from array (for game restart)
*/
void Game::clearEnemies()
{
    enemies.clear();
    // Delete enemies
    for (size_t i = 0; i < enemies.size(); i++)
    {
        delete enemies[i];
    }
}

void Game::setEnemies(short selected_level)
{
    if (selected_level == 1)
    {
        enemies.push_back(new Enemy(100, 450, false));
        enemies[0]->setRotation(-45);
        enemies.push_back(new Enemy(150, 520, false));
        enemies[1]->setRotation(-40);

        enemies.push_back(new Enemy(100, 750, false));
        enemies[2]->setRotation(45);

        enemies.push_back(new Enemy(1250, 150, false));
        enemies[3]->setRotation(135);

        enemies.push_back(new Enemy(1600, 160, false));
        

        enemies.push_back(new Enemy(1200, 900, false));
        enemies[5]->setRotation(-45);

        enemies.push_back(new Enemy(1700, 720, false));
        enemies[6]->setRotation(90);

        player->setPlayerPosition(810, 980);
        player->setGunPosition(1350, 125);
        knife->setKnifePosition(0, 810, 750);
        arrow.setPosition(25, 710);
        aliveEnemies = enemies.size();
    }
    else if (selected_level == 2)
    {
        enemies.push_back(new Enemy(50, 450, false));

        //enemies.push_back(new Enemy(400, 50, false));
        //enemies[1]->setRotation(90);

        //enemies.push_back(new Enemy(100, 950, false));
        //enemies[2]->setRotation(-45);

        //enemies.push_back(new Enemy(410, 900, false));
        //enemies[3]->setRotation(-90);

        //enemies.push_back(new Enemy(1100, 450, false));
        //enemies[4]->setRotation(180);

        //enemies.push_back(new Enemy(1400, 350, false));
        //enemies[5]->setRotation(180);

        //enemies.push_back(new Enemy(1850, 100, false));
        //enemies[6]->setRotation(180);

        //enemies.push_back(new Enemy(1350, 650, false));
        //enemies[7]->setRotation(135);

        player->setPlayerPosition(1700, 650);
        player->setGunPosition(600, 100);
        knife->setKnifePosition(0, 1700, 850);
        arrow.setPosition(25, 75);
        aliveEnemies = enemies.size();
    }
    else if (selected_level == 3)
    {
        enemies.push_back(new Enemy(100, 150, false));
        enemies[0]->setRotation(90);

        enemies.push_back(new Enemy(500, 150, false));
        enemies[1]->setRotation(180);

        enemies.push_back(new Enemy(320, 400, false));
        enemies[2]->setRotation(55);

        enemies.push_back(new Enemy(800, 350, false));
        enemies[3]->setRotation(90);

        enemies.push_back(new Enemy(1150, 650, false));
        enemies[4]->setRotation(-90);

        enemies.push_back(new Enemy(1850, 150, false));
        enemies[5]->setRotation(180);

        enemies.push_back(new Enemy(1450, 450, false));
        enemies[6]->setRotation(90);

        enemies.push_back(new Enemy(1750, 550, false));
        enemies[7]->setRotation(125);

        player->setPlayerPosition(100, 980);
        player->setGunPosition(150, 100);
        knife->setKnifePosition(0, 250, 990);
        aliveEnemies = enemies.size();
    }
}

/**
*   @ return void
*   - initialization of knife
*/
void Game::initKnife()
{
    knife = new Knife;
}

/**
*   @ return void
*   - initialization of map
*/
void Game::initMap()
{
    map = new Map;
}

// -------------------------------- CONSTRUCTOR / DESTRUCTOR -------------------------------- // 

/**
*   Game class constructor
*   - call all init functions
*/
Game::Game()
{
    initWindow();
    initVariables();
    initMenu();
    initTextures();
    initText();
    initKnife();
    initPlayer();
    initEnemies();
    initBullet();
    initMap();
}

/**
*   Game class destructor
*   - delete all variables and clear memory
*/
Game::~Game()
{
    delete player;
    delete knife;
    delete enemy;
    delete bulletFirst;
    delete map;
    delete menu;
    delete pause;
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

/**
*   @ return void
*   - Game loop which call update and render
*   - is working while window is open
*/
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
*   - update enemies and player collision
*   - update player and knife collision
*   - update player and walls collision
*/
void Game::updateGameIvents(sf::Vector2f playerPosition, sf::FloatRect bounds)
{
    for (size_t i = 0; i < enemies.size(); i++)
    {
        // Kill the player if player was attacked by enemy
        if (!enemies[i]->getEnemyDead() 
            && !enemies[i]->getCknocked() 
            && enemies[i]->updateEnemyMove(playerPosition, bounds))
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

    // check player and map collision
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (map->updateWallCollision(player->getPlayerCoordinateX(), player->getPlayerCoordinateY() - 16))
        {
            player->setPlayerPosition(player->getPlayerCoordinateX(), player->getPlayerCoordinateY());
        }
        else player->move(0, -0.5);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (map->updateWallCollision(player->getPlayerCoordinateX() - 16, player->getPlayerCoordinateY()))
        {
            player->setPlayerPosition(player->getPlayerCoordinateX(), player->getPlayerCoordinateY());
        }
        else player->move(-0.5, 0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (map->updateWallCollision(player->getPlayerCoordinateX() + 16, player->getPlayerCoordinateY()))
        {
            player->setPlayerPosition(player->getPlayerCoordinateX(), player->getPlayerCoordinateY());
        }
        else player->move(0.5, 0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (map->updateWallCollision(player->getPlayerCoordinateX(), player->getPlayerCoordinateY() + 16))
        {
            player->setPlayerPosition(player->getPlayerCoordinateX(), player->getPlayerCoordinateY());
        }
        else player->move(0, 0.5);
    }
}

/**
*   @ return void
*   - update bullets collision with walls and screen
*/
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
        // delete bullet if collision with wall
        else if (map->updateWallCollision(bullets[i]->getBounds()))
        {
            bullets.erase(bullets.begin() + i);
        }
        // enemy kill by bullets
        for (size_t j = 0; j < enemies.size(); j++)
        {
            if (!bullets.empty() && enemies[j]->getBounds().intersects(bullets[i]->getBounds()) && !enemies[j]->getEnemyDead())
            {
                bullets.erase(bullets.begin() + i);
                enemies[j]->setTexture(0, 64, 32, 32);
                enemies[j]->setDead(true);
                --aliveEnemies;
            }
        }
    }

}

/**
*   @ return void
*   - update enemies positions
*/
void Game::updateEnemies()
{
    for (size_t i = 0; i < enemies.size(); i++)
    {
        if (!enemies[i]->getEnemyDead() && !enemies[i]->getCknocked())
        {
            enemies[i]->update(sf::Vector2f(player->getPlayerCoordinateX(), player->getPlayerCoordinateY()), player->getPlayerGlobalBounds());
        }

        if (enemies[i]->getCknocked())
        {
            if (enemies[i]->timer())
            {
                enemies[i]->setTexture(0, 32, 32, 32);
                enemies[i]->setCknocked(false);
            }

        }
    }
}

/**
*   @ return void
*   - update window events and keyboard input
*/
void Game::updatePollEvents()
{
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
        // event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape || 
        else if (menu->getGameExit() || pause->getQuit())
            window->close();
        else if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::R) {
            if (playerDead) restart();
        }
        else if (menu->getGameStart() && event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
        {
            if (!pause->getPause() && player->timer(time) && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) pause->setPause(true);
            else if (player->timer(time) && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) pause->setPause(false);
        }
    }
}

/**
*   @ return void
*   - update mouse input
*   - implements knife kill, arm hit and bullet creating
*/
void Game::updateInput()
{
    // shooting
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
    // knife kill
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && player->WithKnife())
    {
        for (size_t j = 0; j < enemies.size(); j++)
        {
            if (enemies[j]->getBounds().intersects(player->getPlayerGlobalBounds()) && !enemies[j]->getEnemyDead())
            {
                enemies[j]->setTexture(0, 64, 32, 32);
                enemies[j]->setDead(true);
                --aliveEnemies;
            }
        }
    }
    // arm hit
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !player->WithKnife() && !player->WithWeapon())
    {
        for (size_t j = 0; j < enemies.size(); j++)
        {
            if (enemies[j]->getBounds().intersects(player->getPlayerGlobalBounds()) 
                && !enemies[j]->getEnemyDead()
                && !enemies[j]->getCknocked())
            {
                enemies[j]->setTexture(32, 64, 32, 32);
                enemies[j]->setCknocked(true);
            }
            
        }
    }
}

/**
*   @ return void
*   - update text (show how much ammo in the gun) 
*/
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

/**
*   @ return void
*   - update enemies view collision with walls
*/
void Game::updateEnemiesView()
{
    for (short i = 0; i < enemies.size(); i++)
    {

        if (map->updateWallCollision(enemies[i]->getViewBounds())
            && !enemies[i]->getEnemyDead()
            && enemies[i]->getEnemyViewLength() > 20
            && enemies[i]->getEnemyViewLength() < 680)
        {
            enemies[i]->setEnemyViewLength(enemies[i]->getEnemyViewLength() - 10, enemies[i]->getEnemyViewWidth() - 5);
            if (!map->updateWallCollision(enemies[i]->getViewRectBounds()) 
                && enemies[i]->getEnemyViewLengthTriangle() < 620)
                enemies[i]->setEnemyView(enemies[i]->getEnemyViewLengthTriangle() + 10);
            enemies[i]->setRectangleViewSize(enemies[i]->getRectangleViewSize() + 10);
        }
        else if (!map->updateWallCollision(enemies[i]->getViewBounds())
            && !enemies[i]->getEnemyDead()
            && enemies[i]->getEnemyViewLength() <= 620)
        {
            enemies[i]->setEnemyViewLength(enemies[i]->getEnemyViewLength() + 10, enemies[i]->getEnemyViewWidth() + 5);
            if (map->updateWallCollision(enemies[i]->getViewRectBounds()))
                enemies[i]->setEnemyView(enemies[i]->getEnemyViewLengthTriangle() - 10);

            enemies[i]->setRectangleViewSize(enemies[i]->getRectangleViewSize() - 10);
        }

        if (map->updateWallCollision(enemies[i]->getViewRectBounds()) && enemies[i]->getEnemyViewLength() >= 30)
        {
            enemies[i]->setEnemyView(enemies[i]->getEnemyViewLengthTriangle() - 20);
        }

    }
}

/**
*   @ return void
*   - update enemies collision with walls
*/
void Game::updateEnemiesWallCollision()
{
    for (short i = 0; i < enemies.size(); i++)
    {
        if (map->updateWallCollision(enemies[i]->getEnemyPosX(), enemies[i]->getEnemyPosY()))
        {

            if (map->updateCollisionDiraction(enemies[i]->getEnemyPosX(), enemies[i]->getEnemyPosY(), enemies[i]->getBounds()) == 1)
            {
                enemies[i]->setPosition(enemies[i]->getEnemyPosX() - 5, enemies[i]->getEnemyPosY());
            }
            else if (map->updateCollisionDiraction(enemies[i]->getEnemyPosX(), enemies[i]->getEnemyPosY(), enemies[i]->getBounds()) == 2)
            {
                enemies[i]->setPosition(enemies[i]->getEnemyPosX() + 5, enemies[i]->getEnemyPosY());
            }
            else if (map->updateCollisionDiraction(enemies[i]->getEnemyPosX(), enemies[i]->getEnemyPosY(), enemies[i]->getBounds()) == 3)
            {
                enemies[i]->setPosition(enemies[i]->getEnemyPosX(), enemies[i]->getEnemyPosY() + 5);
            }
            else if (map->updateCollisionDiraction(enemies[i]->getEnemyPosX(), enemies[i]->getEnemyPosY(), enemies[i]->getBounds()) == 4)
            {
                enemies[i]->setPosition(enemies[i]->getEnemyPosX() - 5, enemies[i]->getEnemyPosY() - 5);
            }
        }
    }
}

/**
*   @ return void
*   - update all staff
*/
void Game::update()
{
    updatePollEvents();

    if (!menu->getGameStart())
    {
        menu->update(*window);
        if (menu->getGameSelectedLevel() == 1) {
            map->setLevel(1);
            setEnemies(1);
            menu->setGameStart(true);
        }
        else if (menu->getGameSelectedLevel() == 2) {
            map->setLevel(2);
            setEnemies(2);
            menu->setGameStart(true);
        }
        else if (menu->getGameSelectedLevel() == 3) {
            map->setLevel(3);
            setEnemies(3);
            menu->setGameStart(true);
        }
    }
    else
    {
        if (!playerDead && !pause->getPause() && !gameComplete)
        {
            updateInput();
            mousePosition = sf::Mouse::getPosition(*window);
            player->update(mousePosition, *window, view);
            updateBullets();
            updateGameIvents(sf::Vector2f(player->getPlayerCoordinateX(), player->getPlayerCoordinateY()), player->getPlayerGlobalBounds());
            updateEnemies();
            updateEnemiesView();
            updateEnemiesWallCollision();
            
        }
        updateText();
        pause->update();

        if (aliveEnemies == 0 && map->exitCollision(player->getPlayerGlobalBounds()) && menu->getGameSelectedLevel() != 3)
        {
            menu->setGameSelectedLevel(menu->getGameSelectedLevel() + 1);
            restart();
            map->setLevel(menu->getGameSelectedLevel());
        }

    }
}

// ------------------------------------ RENDER ------------------------------------ // 
/**
*   @ return void
*   - render all staff
*/
void Game::render()
{
    window->clear(sf::Color(205, 205, 205));

	// Draw staff here...

    if (!menu->getGameStart())
    {
        menu->render(*window);
    }
    else
    {
        if (!pause->getPause())
        {
            map->render(*window);

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

            if (aliveEnemies == 0 && menu->getGameSelectedLevel() != 3)
            {
                winText.setString("LEVEL CLEAR");
                window->draw(winText);
                window->draw(arrow);
            }
            else if (aliveEnemies == 0 && menu->getGameSelectedLevel() == 3 && map->exitCollision(player->getPlayerGlobalBounds()))
            {
                winText.setString("BRO SAVED");
                window->draw(winText);
                gameComplete = true;
            }
        }
        else pause->render(*window);
    }

	window->display();
}
