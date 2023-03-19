#include "Player.h"

//Private functions

void Player::initVariables()
{
	this->movementSpeed = 5.f;
	this->currentFrame = 0.f;
	this->hpMax = 10;
	this->hp = this->hpMax;
}

void Player::initSprite()
{
	this->playerTexture.loadFromFile("./Textures/playerTexture.png");
	this->playerSprite.setTexture(this->playerTexture);
	this->playerSprite.setTextureRect(sf::IntRect(48, 8, 48, 48));
}

//Constructor/Destructor
Player::Player(float x,float y)
{
	this->playerSprite.setPosition(x, y);

	this->initVariables();
	this->initSprite();
}

Player::~Player()
{

}

//Accessors
const sf::Sprite& Player::getShape() const
{
	return this->playerSprite;
}

void Player::setPlayerPos(sf::Vector2f pos)
{
	this->playerSprite.setPosition(pos);
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

//Functions
void Player::takeDamage(const int damage)
{
	if (this->hp > 0)
		this->hp -= damage;
	if (this->hp < 0)
		this->hp = 0;
}

void Player::gainHealth(const int health)
{
	if (this->hp < this->hpMax)
		this->hp += health;
	if (this->hp > this->hpMax)
		this->hp = this->hpMax;
}

void Player::updateInput()
{
	//Keyboard input movement
	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->playerSprite.move(-this->movementSpeed, 0.f);
		this->updateSprite('l');
	}
	//Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->playerSprite.move(this->movementSpeed, 0.f);
		this->updateSprite('r');
	}
	//Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->playerSprite.move(0.f, -this->movementSpeed);
		this->updateSprite('u');
	}
	//Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->playerSprite.move(0.f, this->movementSpeed);
		this->updateSprite('d');
	}
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{

	//Left
	if (this->playerSprite.getGlobalBounds().left <= 0.f)
		this->playerSprite.setPosition(0.f, this->playerSprite.getGlobalBounds().top);
	//Right
	if (this->playerSprite.getGlobalBounds().left + this->playerSprite.getGlobalBounds().width >= target->getSize().x)
		this->playerSprite.setPosition(target->getSize().x - this->playerSprite.getGlobalBounds().width, this->playerSprite.getGlobalBounds().top);
	//Top
	if (this->playerSprite.getGlobalBounds().top <= 0.f)
		this->playerSprite.setPosition(this->playerSprite.getGlobalBounds().left,0.f);
	//Bottom
	if (this->playerSprite.getGlobalBounds().top + this->playerSprite.getGlobalBounds().height >= target->getSize().y)
		this->playerSprite.setPosition(this->playerSprite.getGlobalBounds().left, target->getSize().y - this->playerSprite.getGlobalBounds().height);
}

void Player::updateSprite(char direction)
{
	//Updating sprite depends on direction
	switch (direction)
	{
		//left
	case 'l':
		if (this->currentFrame > 3) this->currentFrame -= 3;
		this->playerSprite.setTextureRect(sf::IntRect(48 * static_cast<unsigned>(this->currentFrame), 56,48,48));
		break;
		//right
	case 'r':
		if (this->currentFrame > 3) this->currentFrame -= 3;
		this->playerSprite.setTextureRect(sf::IntRect(48 * static_cast<unsigned>(this->currentFrame), 104, 48, 48));
		break;
		//up
	case 'u':
		if (this->currentFrame > 3) this->currentFrame -= 3;
		this->playerSprite.setTextureRect(sf::IntRect(48 * static_cast<unsigned>(this->currentFrame), 152, 48, 48));
		break;
		//down
	case 'd':
		if (this->currentFrame > 3) this->currentFrame -= 3;
		this->playerSprite.setTextureRect(sf::IntRect(48 * static_cast<unsigned>(this->currentFrame), 8, 48, 48));
		break;

	}
}

void Player::updateClockTime()
{
	//Updating current frame
	this->time = this->clock.getElapsedTime().asMicroseconds(); //assining time in microseconds
	this->clock.restart(); //restarting clock
	this->time = this->time / 800; //converting it in something like seconds 
	this->currentFrame += 0.005 * time; // making it looking like 1,2,3...
}

//Undates
void Player::update(const sf::RenderTarget* target)
{
	//Clock time update
	this->updateClockTime();

	//Input update
	this->updateInput();

	//Window bounds collision
	this->updateWindowBoundsCollision(target);
}

//Renders
void Player::render(sf::RenderTarget* target)
{
	target->draw(this->playerSprite);
}
