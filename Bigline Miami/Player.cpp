#include "Player.h"

// ------------------------------------ PRIVATE FUNCTIONS ------------------------------------ // 


void Player::initVariables()
{
	// Set movement speed and bool is running
	movementSpeed = 10.f;

	withWeapon = false;

	time = sf::seconds(0.1f);

	// Set variables for attack
	attackTimer.restart();
	attackTimerMax = 1;
	attackCooldownMax = 20.f;
	attackCooldown = attackCooldownMax;

	// Init rectangle around player
	playerBorder.setSize(sf::Vector2f(32, 32));
	playerBorder.setOrigin(playerBorder.getLocalBounds().width / 2, playerBorder.getLocalBounds().height / 2);
	playerBorder.scale(5, 5);
	playerBorder.setFillColor(sf::Color::Transparent);
	//playerBorder.setOutlineColor(sf::Color::Green);
	//playerBorder.setOutlineThickness(0.5);

	// Init rectangle around player
	gunBorder.setSize(sf::Vector2f(32, 32));
	gunBorder.scale(2, 2);
	gunBorder.setFillColor(sf::Color::Transparent);
	//gunBorder.setOutlineColor(sf::Color::Red);
	//gunBorder.setOutlineThickness(1);
}

bool Player::timer(sf::Time& time)
{
	static sf::Clock clock;
	time = clock.getElapsedTime();

	// Проверяем, прошла ли одна секунда
	if (time.asSeconds() >= 0.5f) {
		clock.restart();
		return true;
	}
	return false;
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
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32)); // ïåðâûé ñïðàéò
	sprite.scale(3.5, 3.5);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(sf::Vector2f(window.getSize().x / 2 - 32, window.getSize().y / 2 - 32));

	playerBorder.setPosition(sf::Vector2f(window.getSize().x / 2 - 32, window.getSize().y / 2 - 32));
}

void Player::initWeapon()
{
	gun = new Gun;
	gunBorder.setPosition(gun->getPositionX() - 32, gun->getPositionY() - 32);
}

// -------------------------------- CONSTRUCTOR / DESTRUCTOR -------------------------------- // 

Player::Player(sf::RenderTarget& window)
{
	initVariables();
	initTexture();
	initWeapon();
	initSprite(window);
}

Player::~Player()
{
	delete gun;
}

// ------------------------------------ PUBLIC FUNCTIONS ------------------------------------ // 

void Player::move(const float dirX, const float dirY)
{
	sprite.move(movementSpeed * dirX, movementSpeed * dirY);
}

float Player::getPlayerCoordinateX()
{
	return sprite.getPosition().x;
}

float Player::getPlayerCoordinateY()
{
	return sprite.getPosition().y;
}

float Player::getRotation()
{
	return rotation;
}



sf::Vector2f Player::getAimDirNorm()
{
	return aimDirNorm;
}

void Player::setTexture(int rectLeft, int rectTop, int rectWidth, int rectHeight)
{
	sprite.setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
}

// weapon collision
bool Player::weaponCollision()
{
	// Collision with gun border
	if (sprite.getPosition().x > gunBorder.getPosition().x
		&& sprite.getPosition().x < gunBorder.getPosition().x + 64
		&& sprite.getPosition().y > gunBorder.getPosition().y
		&& sprite.getPosition().y < gunBorder.getPosition().y + 64
		&& !withWeapon)
	{
		return true;
	}
	else return false;
}

void Player::attackAnimation()
{
	sf::Time deltaTime = clock.restart(); // ïîëó÷åíèå ïðîøåäøåãî âðåìåíè
	float deltaTimeSeconds = deltaTime.asSeconds(); // ïðåîáðàçîâàíèå â ñåêóíäû

	elapsedTime += deltaTimeSeconds * 4;
	if (elapsedTime >= 0.07f) { // âðåìÿ ìåæäó ñïðàéòàìè
		currentFrame++;
		if (currentFrame > 8) { // êîëè÷åñòâî ñïðàéòîâ â îäíîì öèêëå
			currentFrame = 0;
		}
		sprite.setTextureRect(sf::IntRect(currentFrame * 32, 32, 32, 32)); // óñòàíîâêà íîâîãî ïðÿìîóãîëüíèêà òåêñòóðû
		elapsedTime = 0.0f;
	}
}

const bool Player::getAttackTimer()
{
	if (attackTimer.getElapsedTime().asMilliseconds() >= attackTimerMax)
	{
		attackTimer.restart();
		return true;
	}
	return false;
}

const bool Player::canAttack()
{
	if (attackCooldown >= attackCooldownMax)
	{
		attackCooldown = 0.f;
		return true;
	}
	return false;
}



bool Player::WithWeapon()
{
	return withWeapon;
}

// Walk Animation
void Player::walkAnimation()
{
	sf::Time deltaTime = clock.restart(); // ïîëó÷åíèå ïðîøåäøåãî âðåìåíè
	float deltaTimeSeconds = deltaTime.asSeconds(); // ïðåîáðàçîâàíèå â ñåêóíäû

	elapsedTime += deltaTimeSeconds * 4;
	if (elapsedTime >= 0.1f) { // âðåìÿ ìåæäó ñïðàéòàìè
		currentFrame++;
		if (currentFrame > 15) { // êîëè÷åñòâî ñïðàéòîâ â îäíîì öèêëå
			currentFrame = 0;
		}
		sprite.setTextureRect(sf::IntRect(currentFrame * 32, 0, 32, 32)); // óñòàíîâêà íîâîãî ïðÿìîóãîëüíèêà òåêñòóðû
		elapsedTime = 0.0f;
	}
}

// ------------------------------------ UPDATE FUNCTIONS ------------------------------------ // 


void Player::updateAttack()
{
	if (attackCooldown < attackCooldownMax)
		attackCooldown += 0.5f;
}

void Player::updateAnimation(sf::RenderTarget& window, sf::View view)
{

	// Move player
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || 
		sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
		sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		// W 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			/*view.move(0, -10);
			window.setView(view);*/
			sprite.move(0, -5);

			if (!withWeapon)
			{
				// Attack without weapon
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if (getAttackTimer()) attackAnimation();
				}
				else {
					walkAnimation();
				}
			}
			// Collision with player border
			if (sprite.getPosition().y < playerBorder.getPosition().y - 64)
			{
				playerBorder.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + 64));
				//view.setCenter(getPlayerCoordinateX(), getPlayerCoordinateY());
				//window.setView(view);
			}
			if (sprite.getPosition().y - 16 + playerBorder.getSize().y / 2 < 16) {
				sprite.setPosition(sf::Vector2f(sprite.getPosition().x, 16));
			}
		}


		// A 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			sprite.move(-5, 0);
			//view.move(-10, 0);
			//window.setView(view);
			if (!withWeapon)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if (getAttackTimer()) attackAnimation();
				}
				else {
					walkAnimation();
				}

			}
			if (sprite.getPosition().x < playerBorder.getPosition().x - 64)
			{
				playerBorder.setPosition(sf::Vector2f(sprite.getPosition().x + 64, sprite.getPosition().y));
				//view.setCenter(getPlayerCoordinateX(), getPlayerCoordinateY());
				//window.setView(view);
			}
			if (sprite.getPosition().x - playerBorder.getSize().x / 2 <= 0) {
				sprite.setPosition(sf::Vector2f(16, sprite.getPosition().y));
			}
		}

		// D 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			sprite.move(5, 0);
			//view.move(10, 0);
			//window.setView(view);
			
			if (!withWeapon)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if (getAttackTimer()) attackAnimation();
				}
				else {
					walkAnimation();
				}

			}
			if (sprite.getPosition().x > playerBorder.getPosition().x + 64)
			{
				playerBorder.setPosition(sf::Vector2f(sprite.getPosition().x - 64, sprite.getPosition().y));
				//view.setCenter(getPlayerCoordinateX(), getPlayerCoordinateY());
				//window.setView(view);
			}
			if (sprite.getPosition().x + playerBorder.getSize().x / 2 >= window.getSize().x) {
				sprite.setPosition(sf::Vector2f(window.getSize().x - 16, sprite.getPosition().y));
			}
		}


		// S
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			sprite.move(0, 5);
			//view.move(0, 10);
			//window.setView(view);
			
			if (!withWeapon)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if (getAttackTimer()) attackAnimation();
				}
				else {
					walkAnimation();
				}

			}
			if (sprite.getPosition().y > playerBorder.getPosition().y + 64)
			{
				playerBorder.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y - 64));
				//view.setCenter(getPlayerCoordinateX(), getPlayerCoordinateY());
				//window.setView(view);
			}
			if (sprite.getPosition().y + 16 + playerBorder.getSize().y / 2 > window.getSize().y) {
				sprite.setPosition(sf::Vector2f(sprite.getPosition().x, window.getSize().y - 16));
			}
		}
		

	}
	else if (!withWeapon){
		sprite.setTextureRect(sf::IntRect(0, 0, 32, 32)); // set sprite to the start
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !withWeapon) {
		if (getAttackTimer()) attackAnimation();
	}

	// pick up a weapon
	// right click, weapon collision and timer in 0.1s after that take the gun
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && weaponCollision() && timer(time)) {
		gun->makeInvisible(); 
		withWeapon = true;
		gunBorder.setSize(sf::Vector2f(0, 0));
		sprite.setTextureRect(sf::IntRect(0, 64, 32, 32));
		std::cout << "gun\n";
	}
	// drop a weapon
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && withWeapon && timer(time))
	{
		gun->makeVisible();
		withWeapon = false;
		gun->dropTheWeapon(sprite.getPosition().x, sprite.getPosition().y);
		gun->setRotation(rotation);
		gun->setPosition(sprite.getPosition().x + 15, sprite.getPosition().y - 15);
		gunBorder.setSize(sf::Vector2f(32, 32));
		gunBorder.setPosition(gun->getPositionX() - 32, gun->getPositionY() - 32);
	}

}

/**
*	@ return void
*	- rotate the player sprite to the cursor 
*/
void Player::updatePlayerRotation(sf::Vector2i mousePosition)
{
	sf::Vector2f spritePosition = sprite.getPosition();
	dx = mousePosition.x - spritePosition.x;
	dy = mousePosition.y - spritePosition.y;
	rotation = std::atan2(dy, dx) * 180 / 3.14159265;
	sprite.setRotation(rotation);
}

void Player::updateMousePos(sf::Vector2i mousePosition)
{
	// Mouse pos
	playerCenter = sf::Vector2f(getPlayerCoordinateX(), getPlayerCoordinateY());
	mousePosWindow = sf::Vector2f(mousePosition);
	aimDir = mousePosWindow - playerCenter;
	aimDirNorm = aimDir / static_cast<float>(sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));
}

void Player::update(sf::Vector2i mousePosition, sf::RenderTarget& target, sf::View view)
{
	updatePlayerRotation(mousePosition);
	updateAttack();
	updateAnimation(target, view);
	updateMousePos(mousePosition);
}

// ------------------------------------ RENDER ------------------------------------ // 

void Player::render(sf::RenderTarget& target)
{
	target.draw(playerBorder);
	gun->render(target);
	target.draw(gunBorder);
	target.draw(sprite);
}
