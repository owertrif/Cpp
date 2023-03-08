#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

/*
	Class that forging all components into game just like engine
*/

class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMd;
	sf::Event event;
	std::uint8_t scene;

	//Resources
	sf::Font font;

	//Textes
	sf::Text pointsText;
	sf::Text healthText;
	sf::Text restartButtonText;
	sf::Text exitButtonText;
	sf::Text playButtonText;

	//Buttons
	sf::RectangleShape buttonRestart;
	sf::RectangleShape buttonExit;
	sf::RectangleShape buttonPlay;

	//Game Logic
	int points;
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	unsigned maxEnemies;
	bool mouseHeld;
	bool endGame;

	//Objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//private Functions
	void initVariables();
	void initWindow();
	void initEnemies();
	void initFonts();
	void initTextes();
	void initButtons();

public:
	//Cunstructors/Destructors
	Game();
	virtual ~Game();

	//Accessors

	const bool running() const;
	const bool getEndGame() const;

	//Functions
	void spawnEnemy();

	void pollEvents();
	void updateMousePositions();
	void updateEnemies();
	void updateText();
	void updateEndGameBt();
	void updateMainMenuBt();
	void updateScene();
	void update();
	
	void renderEnemies(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
	void renderEndGameBt(sf::RenderTarget& target);
	void renderMainMenuBt(sf::RenderTarget& target);
	void renderScenes();
	void render();
	
};

#endif
