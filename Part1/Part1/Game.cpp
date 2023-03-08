#include "Game.h"
#include "plog/Log.h"



//Constructor/Destructor
Game::Game()
{
	PLOGD << "Game launched";
	this->initVariables();
	this->initWindow();
	this->initEnemies();
	this->initFonts();
	this->initTextes();
	this->initButtons();
}

Game::~Game()
{
	PLOGD << "Game closed";
	delete this->window;
}

//Fuctions

void Game::update()
{
	this->pollEvents();

	
	this->updateScene();

	//endgame condition
	if (this->health <= 0)
		this->endGame = true;
}

void Game::renderEnemies(sf::RenderTarget& target)
{
	for(auto &e : this->enemies)
	target.draw(e);
}

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->pointsText);
	target.draw(this->healthText);
}

void Game::renderEndGameBt(sf::RenderTarget& target)
{
	target.draw(this->buttonRestart);
	target.draw(this->buttonExit);

	target.draw(this->restartButtonText);
	target.draw(this->exitButtonText);
}

void Game::renderMainMenuBt(sf::RenderTarget& target)
{
	target.draw(this->buttonPlay);
	target.draw(this->playButtonText);
}

void Game::renderScenes()
{
	switch (this->scene)
	{
	case 0:
		this -> renderMainMenuBt(*this->window);
		break;
	case 1:
		if (this->endGame == false)
		{

			this->renderEnemies(*this->window);

			this->renderText(*this->window);
		}
		else
		{
			this->renderEndGameBt(*this->window);
		}
		break;
	}
}

void Game::render()
{
	/*
		-clears old frame
		-render new objects
		-display the objects

		Renders the game objects.
	*/
	this->window->clear();

	//Draw grafics
	this->renderScenes();

	this->window->display();
}

void Game::spawnEnemy()
{
	/*
	@return void
		
		Spawn the enemy and defines starter position and color.
		-set enemy random type
		-set enemy random position
		-Adds enemy to the vector

	*/

	

	//randomize enemy type
	int type{ rand() % 5 };

	switch (type)
	{
	case 0:
		this->enemy.setSize(sf::Vector2f(10.0f, 10.0f));
		this->enemy.setFillColor(sf::Color(sf::Color::Magenta));
		break;
	case 1:
		this->enemy.setSize(sf::Vector2f(30.0f, 30.0f));
		this->enemy.setFillColor(sf::Color(sf::Color::Blue));
		break;
	case 2:
		this->enemy.setSize(sf::Vector2f(50.0f, 50.0f));
		this->enemy.setFillColor(sf::Color(sf::Color::Cyan));
		break;
	case 3:
		this->enemy.setSize(sf::Vector2f(70.0f, 70.0f));
		this->enemy.setFillColor(sf::Color(sf::Color::Red));
		break;
	case 4:
		this->enemy.setSize(sf::Vector2f(100.0f, 100.0f));
		this->enemy.setFillColor(sf::Color(sf::Color::Green));
		break;
	default:
		this->enemy.setSize(sf::Vector2f(100.0f, 100.0f));
		this->enemy.setFillColor(sf::Color(sf::Color::Yellow));
		break;
	}

	//set the position
	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>((this->window->getSize().x - this->enemy.getSize().x))),
		0.0f
	);

	//spawn the enemy
	this->enemies.push_back(this->enemy);
}

void Game::pollEvents()
{
	/*
		-cheking that event is poling
		-cheking the type of event 
		-doing some stuff according to event type

		Updating events so they can be cheked.
	*/
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)this->window->close();
			break;
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}
}

void Game::updateMousePositions()
{
	/*
	@ return void
		Updates the mouse position:
			-Mouse position relative to window (Vector2i)

	*/

	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateEnemies()
{
	/*
	@ return void 

		-checks if there maximum number of enemies reached
		-checks if the timer reached his maximum and updates it
		-moves the enemy downwards
		-removes the enemies at the click upon them
		-removes the enemies at the edge of the window 

		Updating enemies
	*/
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer == this->enemySpawnTimerMax)
		{
			//Spawn an enemy and reset the timer
			this->enemySpawnTimer = 0.0f;
			this->spawnEnemy();
		}
		else
			this->enemySpawnTimer += 1.0f;
		
	}

	//moving enemies
	for (int i{0}; i<this->enemies.size();i++)
	{
		this->enemies[i].move(0.0f, 2.0f);
		
		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->health -= 1;
		}
	}

		//checked if clicked upon
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->mouseHeld == false)
		{
			this->mouseHeld = true;
			bool deleted{ false };
			for (size_t i{ 0 }; i < this->enemies.size() && deleted == false; i++)
			{
				if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
				{
					//gain points
					if (this->enemies[i].getFillColor() == sf::Color::Magenta)
						this->points += 10;
					else if (this->enemies[i].getFillColor() == sf::Color::Blue)
						this->points += 7;
					else if (this->enemies[i].getFillColor() == sf::Color::Cyan)
						this->points += 5;
					else if (this->enemies[i].getFillColor() == sf::Color::Red)
						this->points += 3;
					else if (this->enemies[i].getFillColor() == sf::Color::Green)
						this->points += 1;

					//delete the enemy
					deleted = true;
					this->enemies.erase(this->enemies.begin() + i);
				}
			}
		}
	}
	else
	{
		this->mouseHeld = false;
	}
}

void Game::updateText()
{
	/*
	@return void
		Updating dynamic text
	*/

	//changing points number
	std::stringstream ss;

	ss << "Points: " << this->points;

	this->pointsText.setString(ss.str());

	//changing health number
	std::stringstream ssh;

	ssh << "Health: " << this->health;

	this->healthText.setString(ssh.str());
}

void Game::updateEndGameBt()
{
	/*
	@return void
		Updating end game buttons
	*/

	//checking if clicked upon them
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->buttonRestart.getGlobalBounds().contains(this->mousePosView))
		{
			this->enemies.clear();
			this->endGame = false;
			this->health = 5;
			this->points = 0;
		}
		if (this->buttonExit.getGlobalBounds().contains(this->mousePosView))
		{
			this->window->close();
		}
	}
}

void Game::updateMainMenuBt()
{
	/*
	@return void
		Updating main menu buttons
	*/

	//checking if clicked upon them
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->buttonPlay.getGlobalBounds().contains(this->mousePosView))
		{
			this->scene = 1;
		}
	}
}

void Game::updateScene()
{
	/*
	@return void 
		Updating specified scenes
	*/
	switch (scene)
	{
	case 0:
		this->updateMousePositions();

		this->updateMainMenuBt();
	case 1:
		if (this->endGame == false)
		{
			this->updateMousePositions();

			this->updateText();

			this->updateEnemies();
		}
		else
		{
			this->updateMousePositions();

			this->updateEndGameBt();
		}
		break;
	default:
		break;
	}
}


//private functions
void Game::initVariables()
{
	/*
	@ return void
		Initializing variables that has no default init or we net to specialise it.
	*/
	this->window = nullptr;

	//Game logic
	this->points = 0;
	this->enemySpawnTimerMax = 10.0f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
	this->mouseHeld = false;
	this->health = 5;
	this->endGame = false;
	this->scene = 0;
}

void Game::initWindow()
{
	/*
	@ return void

		-seting the window height
		-seting the window width
		-creating the window

		Initialising window.
	*/
	this->videoMd.height = 600;
	this->videoMd.width = 800;
	this->window = new sf::RenderWindow(this->videoMd, "Part1",sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
	/*
	@return void

		-setting size of the object
		-adding textures or something else like this
		
		Initializing enemy object.
	*/

	this->enemy.setPosition(50.0f, 50.0f);
	this->enemy.setSize(sf::Vector2f(100.0f,100.0f));
	this->enemy.setFillColor(sf::Color(sf::Color::Red));
}

void Game::initFonts()
{
	//Initializing fonts
	if (this->font.loadFromFile("./Fonts/Roboto-Regular.ttf")) // HAVE a problem with this font
	{
		PLOGD << "ERROR::GAME::INITFONTS::Fail to load font" << '\n';
	}
}

void Game::initTextes()
{
	/*
	@return void
		Initializing Textes
		-seting font
		-seting position
		-seting font size
		-seting font color
		-seting default text
	*/

	//Point text
	this->pointsText.setFont(this->font);
	this->pointsText.setPosition(10.f, 0.f);
	this->pointsText.setCharacterSize(24);
	this->pointsText.setFillColor(sf::Color::White);
	this->pointsText.setString("NONE");

	//Health text
	this->healthText.setFont(this->font);
	this->healthText.setCharacterSize(24);
	this->healthText.setFillColor(sf::Color::Red);
	this->healthText.setStyle(sf::Text::Bold);
	this->healthText.setPosition(sf::Vector2f(this->window->getSize().x - 120, 0.0f));
	this->healthText.setString("NONE");

	//Restart button text
	this->restartButtonText.setFont(this->font);
	this->restartButtonText.setCharacterSize(24);
	this->restartButtonText.setFillColor(sf::Color::Blue);
	this->restartButtonText.setString("Restart");
	this->restartButtonText.setPosition(
		(this->window->getSize().x - this->buttonRestart.getSize().x) / 2 - 40,
		(this->window->getSize().y - this->buttonRestart.getSize().y) / 2 - 15
		);

	//Exit button text
	this->exitButtonText.setFont(this->font);
	this->exitButtonText.setCharacterSize(24);
	this->exitButtonText.setFillColor(sf::Color::Blue);
	this->exitButtonText.setString("Exit");
	this->exitButtonText.setPosition(
		this->window->getSize().x / 2 - this->buttonExit.getSize().x / 2 - 20,
		this->window->getSize().y / 2 - this->buttonExit.getSize().y / 2 + 20 + this->buttonRestart.getSize().y + 35
	);

	//Play button text
	this->playButtonText.setFont(this->font);
	this->playButtonText.setCharacterSize(24);
	this->playButtonText.setFillColor(sf::Color::Blue);
	this->playButtonText.setString("Play");
	this->playButtonText.setPosition(
		(this->window->getSize().x - this->buttonPlay.getSize().x) / 2 - 40,
		(this->window->getSize().y - this->buttonPlay.getSize().y) / 2 - 15
	);
}

void Game::initButtons()
{
	/*
	@return void
		Initializing buttons
		-set size
		-set position
		-set color
	*/

	//Restart button
	this->buttonRestart.setSize(sf::Vector2f(100.f, 50.f));

	this->buttonRestart.setPosition(
		this->window->getSize().x / 2 - this->buttonRestart.getSize().x / 2,
		this->window->getSize().y / 2 - this->buttonRestart.getSize().y / 2
	);
	this->buttonRestart.setFillColor(sf::Color::White);

	//Exit button
	this->buttonExit.setSize(sf::Vector2f(100.f, 50.f));

	this->buttonExit.setPosition(
		this->window->getSize().x / 2 - this->buttonExit.getSize().x / 2,
		this->window->getSize().y / 2 - this->buttonExit.getSize().y / 2 + 20 + this->buttonRestart.getSize().y
	);
	this->buttonExit.setFillColor(sf::Color::White);

	//Play button
	this->buttonPlay.setSize(sf::Vector2f(100.f, 50.f));

	this->buttonPlay.setPosition(
		this->window->getSize().x / 2 - this->buttonRestart.getSize().x / 2,
		this->window->getSize().y / 2 - this->buttonRestart.getSize().y / 2
	);
	this->buttonPlay.setFillColor(sf::Color::White);
}

//accessors

const bool Game::running() const
{
	/*
	@return bool;
		
		-returns true if the game is running, else returns false

		Checking if the game running.

	*/

	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	//Checking if the game ends
	//@ return const bool
	return this->endGame;
}
