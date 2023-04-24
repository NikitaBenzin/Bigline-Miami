#include "Enemy.h"

void Enemy::initVariables()
{

}

void Enemy::initTexture()
{
    texture.loadFromFile("textures/enemy.png");
}

void Enemy::initSprite()
{
    sprite.setTexture(texture);
    sprite.scale(4, 4);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(sf::Vector2f(300.f, 400.f));

}

Enemy::Enemy()
{
    initVariables();
    initTexture();
    initSprite();
}

Enemy::~Enemy()
{
}

float Enemy::getEnemyPosX()
{
    return sprite.getPosition().x;
}

float Enemy::getEnemyPosY()
{
    return sprite.getPosition().y;
}

void Enemy::updateEnemyRotation(sf::Vector2f playerPosition)
{
    sf::Vector2f spritePosition = sprite.getPosition();
    dx = playerPosition.x - spritePosition.x;
    dy = playerPosition.y - spritePosition.y;
    rotation = std::atan2(dy, dx) * 180 / 3.14159265;
    sprite.setRotation(rotation);
}

void Enemy::update(sf::Vector2f playerPosition)
{
    updateEnemyRotation(playerPosition);
}

void Enemy::render(sf::RenderTarget& target)
{
    target.draw(sprite);
}
