#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <plog/Log.h>
#include "plog/Initializers/RollingFileInitializer.h"

#include "Player.h"
#include "SwagBall.h"



class Game
{
private:
	//Window
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;
	
	//objects
	Player player;
	std::vector<SwagBall> swagballs;
	
	//Text
	sf::Font font;
	sf::Text guiText;

	//Variables
	sf::Clock clock;
	float timer;
	float spawnTimerMax;
	int maxSwagBals;
	int points;

	//Functions
	void initVariables();
	void initWindow();
	void initFont();
	void initText();
	void setPlayerPos();

public:
	//Constructor/Destructor
	Game();
	~Game();

	//Accesors
	const bool& getEndGame() const;
	//Modifiers

	//Functions
	bool running();
	void pollEvents();
	void spawnSwagBalls();
	const int randomizeType() const;

	void update();
	void updateClock();
	void updateCollision();
	void updateGui();
	void updatePlayer();

	void render();
	void renderSwagBalls(sf::RenderTarget* target);
	void renderGui(sf::RenderTarget* target);
};

#endif
