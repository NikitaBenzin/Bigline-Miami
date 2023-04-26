#include "Enemy.h"


// ------------------------------------ PRIVATE FUNCTIONS ------------------------------------ // 




void Enemy::initVariables()
{
    movementSpeed = 3.f;

    deltaTime = clock.restart().asSeconds();

    length = 100;

}

void Enemy::initTexture()
{
    texture.loadFromFile("textures/enemy-spritesheet.png");
}

void Enemy::initSprite()
{
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 32, 32, 32)); // start frame
    sprite.scale(4, 4);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(sf::Vector2f(100.f,350.f));
}

void Enemy::initTriangle()
{
    // enemy view
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0, 0));
    triangle.setPoint(1, sf::Vector2f(250, -150));
    triangle.setPoint(2, sf::Vector2f(250, 150));
    triangle.setOrigin(triangle.getPoint(0));
    triangle.setFillColor(sf::Color::Transparent);
    triangle.setOutlineColor(sf::Color::Green);
    triangle.setOutlineThickness(1);
    triangle.setPosition(sprite.getPosition().x, sprite.getPosition().y);
}

// -------------------------------- CONSTRUCTOR / DESTRUCTOR -------------------------------- // 

Enemy::Enemy()
{
    initVariables();
    initTexture();
    initSprite();
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


// ------------------------------------ UPDATE FUNCTIONS ------------------------------------ // 

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

void Enemy::stop()
{
    sprite.setTextureRect(sf::IntRect(0, 32, 32, 32)); // start frame
}

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

void Enemy::update(sf::Vector2f playerPosition, sf::FloatRect bounds)
{
    if (updateEnemyView(bounds))
    {
        updateEnemyRotation(playerPosition);
    }

    
}

// ------------------------------------ RENDER ------------------------------------ // 

void Enemy::render(sf::RenderTarget& target)
{
    target.draw(triangle);
    target.draw(sprite);
}
