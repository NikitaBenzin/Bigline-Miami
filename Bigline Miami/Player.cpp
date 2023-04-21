#include "Player.h"

// ------------------------------------ PRIVATE FUNCTIONS ------------------------------------ // 

void Player::initVariables()
{
	// Set movement speed and bool is running
	movementSpeed = 10.f;
	isRunning = false;

	// Init rectangle around player
	border.setSize(sf::Vector2f(32, 32));
	border.setOrigin(border.getLocalBounds().width / 2, border.getLocalBounds().height / 2);
	border.scale(5, 5);
	border.setFillColor(sf::Color::Transparent);
	border.setOutlineColor(sf::Color::Red);
	border.setOutlineThickness(0.5);
}

void Player::initTexture()
{
	// Load a texture from file
	if (!texture.loadFromFile("textures/player-spritesheet.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file.\n";
	}
}

void Player::initSprite(sf::RenderTarget& window)
{
	// Set the texture to the sprite
	sprite.setTexture(texture);

	// Resize the sprite
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32)); // первый спрайт
	sprite.scale(1.2, 1.2);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(sf::Vector2f(window.getSize().x / 2 - 32, window.getSize().y / 2 - 32));

	border.setPosition(sf::Vector2f(window.getSize().x / 2 - 32, window.getSize().y / 2 - 32));
}

// -------------------------------- CONSTRUCTOR / DESTRUCTOR -------------------------------- // 

Player::Player(sf::RenderTarget& window)
{
	this->initVariables();
	this->initTexture();
	this->initSprite(window);
}

Player::~Player()
{

}

const sf::Vector2f& Player::getPos() const
{
	return sprite.getPosition();
}

// ------------------------------------ PUBLIC FUNCTIONS ------------------------------------ // 

void Player::move(const float dirX, const float dirY)
{
	sprite.move(movementSpeed * dirX, movementSpeed * dirY);
}

const bool Player::canAttack()
{
	return false;
}

// ------------------------------------ UPDATE FUNCTIONS ------------------------------------ // 

// Walk Animation
void Player::walkAnimation()
{
	sf::Time deltaTime = clock.restart(); // получение прошедшего времени
	float deltaTimeSeconds = deltaTime.asSeconds(); // преобразование в секунды

	elapsedTime += deltaTimeSeconds * 4;
	if (elapsedTime >= 0.1f) { // время между спрайтами
		currentFrame++;
		if (currentFrame > 15) { // количество спрайтов в одном цикле
			currentFrame = 0;
		}
		sprite.setTextureRect(sf::IntRect(currentFrame * 32, 0, 32, 32)); // установка нового прямоугольника текстуры
		elapsedTime = 0.0f;
	}
}

void Player::updateAttack()
{

}


void Player::updateAnimation(sf::RenderTarget& window, sf::View view)
{


	// Move player
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || 
		sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		
		isRunning = true;

		// W 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			/*view.move(0, -10);
			window.setView(view);*/
			sprite.move(0, -5);
			walkAnimation();

			if (sprite.getPosition().y < border.getPosition().y - 64)
			{
				border.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + 64));

			}
		}


		// A 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			sprite.move(-5, 0);
			//view.move(-10, 0);
			//window.setView(view);
			walkAnimation();

			if (sprite.getPosition().x < border.getPosition().x - 64)
			{
				border.setPosition(sf::Vector2f(sprite.getPosition().x + 64, sprite.getPosition().y));

			}
		}

		// D 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			sprite.move(5, 0);
			//view.move(10, 0);
			//window.setView(view);

			walkAnimation();
				
			if (sprite.getPosition().x > border.getPosition().x + 64)
			{
				border.setPosition(sf::Vector2f(sprite.getPosition().x - 64, sprite.getPosition().y));

			}
		}


		// S
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			sprite.move(0, 5);
			//view.move(0, 10);
			//window.setView(view);
			walkAnimation();

			if (sprite.getPosition().y > border.getPosition().y + 64)
			{
				border.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y - 64));

			}
		}
	}
	else {
		isRunning = false;
		sprite.setTextureRect(sf::IntRect(0, 0, 32, 32)); // в начальную позицию
	}

}


void Player::updatePlayerRotation(sf::Vector2i mousePosition)
{
	sf::Vector2f spritePosition = sprite.getPosition();
	float dx = mousePosition.x - spritePosition.x;
	float dy = mousePosition.y - spritePosition.y;
	float rotation = std::atan2(dy, dx) * 180 / 3.14159265;
	sprite.setRotation(rotation);
}

void Player::update(sf::Vector2i mousePosition, sf::RenderTarget& target, sf::View view)
{
	updatePlayerRotation(mousePosition);
	updateAnimation(target, view);
}

// ------------------------------------ RENDER ------------------------------------ // 

void Player::render(sf::RenderTarget& target)
{
	target.draw(border);
	target.draw(sprite);
}
