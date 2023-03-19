#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <plog/Log.h>
#include "plog/Initializers/RollingFileInitializer.h"

class Player
{
private:

	//Sprite
	sf::Texture playerTexture;
	sf::Sprite	playerSprite;

	//Variables
	sf::Clock clock;
	float time;
	float currentFrame;
	float movementSpeed;
	int hp;
	int hpMax;

	//Functions
	void initVariables();
	void initSprite();

public:
	//Constructor/Destructor
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	//Accessors
	const sf::Sprite& getShape()const;
	void setPlayerPos(sf::Vector2f pos);
	const int& getHp()const;
	const int& getHpMax()const;

	//Functions
	void takeDamage(const int damage);
	void gainHealth(const int health);

	void updateInput();
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void updateSprite(char direction);
	void updateClockTime();
	void update(const sf::RenderTarget* target);

	void render(sf::RenderTarget* target);
};

#endif


