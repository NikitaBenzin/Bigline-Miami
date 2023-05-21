#include "Enemy.h"


// ------------------------------------ PRIVATE FUNCTIONS ------------------------------------ // 




void Enemy::initVariables()
{
    movementSpeed = 3.f;

    deltaTime = clock.restart().asSeconds();

    length = 100;

    gameTimer.restart();
    enemyCknockTime = 5000;

    enemyDead = false;
    enemyCknocked = false;
}

void Enemy::initTexture()
{
    texture.loadFromFile("textures/enemy-spritesheet.png");
}

void Enemy::initSprite(float pos_x, float pos_y)
{
    // enemy sprite
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 32, 32, 32)); // start frame
    sprite.scale(2, 2);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(pos_x, pos_y);
}

void Enemy::initTriangle()
{
    // enemy view
    viewLength = 350;
    viewWidth = 150;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0, 0));
    triangle.setPoint(1, sf::Vector2f(viewLength, -viewWidth));
    triangle.setPoint(2, sf::Vector2f(viewLength, viewWidth));
    triangle.setOrigin(triangle.getPoint(0));
    triangle.setFillColor(sf::Color::Transparent);
    //triangle.setOutlineColor(sf::Color::Green);
    //triangle.setOutlineThickness(1);
    triangle.setPosition(sprite.getPosition().x, sprite.getPosition().y);
}

// -------------------------------- CONSTRUCTOR / DESTRUCTOR -------------------------------- // 

Enemy::Enemy()
{
}


Enemy::Enemy(float pos_x, float pos_y, bool is_dead)
{
    enemyDead = is_dead;
    initVariables();
    initTexture();
    initSprite(pos_x, pos_y);
    initTriangle();
}


Enemy::~Enemy()
{
}

// ------------------------------------ PUBLIC FUNCTIONS ------------------------------------ // 


float Enemy::getEnemyPosX()
{
    return sprite.getPosition().x;
}

float Enemy::getEnemyPosY()
{
    return sprite.getPosition().y;
}

void Enemy::setTexture(int rectLeft, int rectTop, int rectWidth, int rectHeight)
{
    if (!enemyDead)
    {
        sprite.setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
    }
}



void Enemy::enemyWalkAnimaton()
{
    deltaTimeForAnim = clock.restart();
    float deltaTimeSeconds = deltaTimeForAnim.asSeconds();

    elapsedTime += deltaTimeSeconds * 4;
    if (elapsedTime >= 0.1f) {
        currentFrame++;
        if (currentFrame > 11) {
            currentFrame = 0;
        }
        sprite.setTextureRect(sf::IntRect(currentFrame * 32, 0, 32, 32));
        elapsedTime = 0.0f;
    }
}



void Enemy::enemyAttackAnimation()
{
    deltaTimeForAnim = clock.restart();
    float deltaTimeSeconds = deltaTimeForAnim.asSeconds();

    elapsedTime += deltaTimeSeconds * 4;
    if (elapsedTime >= 0.07f) {
        currentFrame++;
        if (currentFrame > 5) {
            currentFrame = 0;
        }
        sprite.setTextureRect(sf::IntRect(currentFrame * 32, 32, 32, 32));
        elapsedTime = 0.0f;
    }
}

sf::FloatRect Enemy::getBounds()
{
    newWidth = sprite.getGlobalBounds().width / 2.0f;
    newHeight = sprite.getGlobalBounds().height / 2.0f;
    newX = sprite.getGlobalBounds().left + sprite.getGlobalBounds().width / 4.0f;
    newY = sprite.getGlobalBounds().top + sprite.getGlobalBounds().height / 4.0f;

    return sf::FloatRect(sf::Vector2f(newX, newY), sf::Vector2f(newWidth, newHeight));
}

sf::FloatRect Enemy::getViewBounds()
{
    newWidth = triangle.getGlobalBounds().width / 2.0f;
    newHeight = triangle.getGlobalBounds().height / 2.0f;
    newX = triangle.getGlobalBounds().left + triangle.getGlobalBounds().width / 2.0f;
    newY = triangle.getGlobalBounds().top + triangle.getGlobalBounds().height / 4.0f;

    return sf::FloatRect(sf::Vector2f(newX, newY), sf::Vector2f(newWidth, newHeight));
}

void Enemy::setDead(bool dead)
{
    enemyDead = dead;
}

bool Enemy::getEnemyDead()
{
    return enemyDead;
}

void Enemy::setEnemyView(float view_length, float view_width)
{
    viewLength = view_length;
    viewWidth = view_width;
    triangle.setPoint(1, sf::Vector2f(viewLength, -viewWidth));
    triangle.setPoint(2, sf::Vector2f(viewLength, viewWidth));
}

void Enemy::stop()
{
    sprite.setTextureRect(sf::IntRect(0, 32, 32, 32)); // start frame
}

void Enemy::setPosition(float pos_x, float pos_y)
{
    sprite.setPosition(sf::Vector2f(pos_x, pos_y));
}

float Enemy::getEnemyViewLength()
{
    return viewLength;
}

float Enemy::getEnemyViewWidth()
{
    return viewWidth;
}
// ------------------------------------ UPDATE FUNCTIONS ------------------------------------ // 



bool Enemy::updateEnemyView(sf::FloatRect bounds)
{
    triangle.setPosition(sprite.getPosition().x, sprite.getPosition().y);
    // check triangle bounds with player
    if (triangle.getGlobalBounds().intersects(bounds))
    {
        //std::cout << "Collision detected!" << std::endl;
        return true;
    }
    return false;

}

void Enemy::updateEnemyDead()
{
    if (enemyDead)
    {
        sprite.setTextureRect(sf::IntRect(0, 64, 32, 32)); // start frame
    }
}

bool Enemy::updateEnemyMove(sf::Vector2f playerPosition, sf::FloatRect bounds)
{
    
    if (updateEnemyView(bounds))
    {
        // std::cout << length << std::endl;  50
        if (length > 0)
        {
            direction /= length;
        }
        // attack range
        if (length <= 65)
        {
            // move enemy in player direction 
            sprite.move(direction * movementSpeed);
            // if length will be < 65 enemy trying attack the player and if length < 50 player lose :)
            enemyAttackAnimation();
            if (length <= 50) return true;
        }
        else {
            // move enemy in player direction 
            sprite.move(direction * movementSpeed);
            // if player in enemy view - play animation
            enemyWalkAnimaton();
        }
        deltaTime = clock.restart().asSeconds();
        // calculate move direction for enemy
        direction = playerPosition - sprite.getPosition();
        length = sqrt(direction.x * direction.x + direction.y * direction.y);
    }
    else sprite.setTextureRect(sf::IntRect(0, 32, 32, 32)); // start frame
    return false;
}



void Enemy::updateEnemyRotation(sf::Vector2f playerPosition)
{
    sf::Vector2f spritePosition = sprite.getPosition();
    dx = playerPosition.x - spritePosition.x;
    dy = playerPosition.y - spritePosition.y;
    rotation = std::atan2(dy, dx) * 180 / 3.14159265;
    sprite.setRotation(rotation);
    triangle.setRotation(rotation);
}



void Enemy::Cknocked(bool state)
{
    enemyCknocked = state;
}

bool Enemy::getCknocked()
{
    if (enemyCknocked) return true;
    else return false;
}

void Enemy::update(sf::Vector2f playerPosition, sf::FloatRect bounds)
{
    updateEnemyDead();

    if (updateEnemyView(bounds))
    {
        updateEnemyRotation(playerPosition);
    }
}

const bool Enemy::timer()
{
    if (gameTimer.getElapsedTime().asMilliseconds() >= enemyCknockTime)
    {
        gameTimer.restart();
        return true;
    }
    return false;
}

// ------------------------------------ RENDER ------------------------------------ // 

void Enemy::render(sf::RenderTarget& target)
{
    target.draw(triangle);
    target.draw(sprite);
}

