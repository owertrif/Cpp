#include "Game.h"

//Private functions
void Game::initVariables()
{
	this->endGame = false;
	this->maxSwagBals = 10;
	this->timer = 0.f;
	this->spawnTimerMax = 0.7f;
	this->points = 0;
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

//Constructor/Destructor
Game::Game()
{
	this->initWindow();
	this->initVariables();
	this->setPlayerPos();
	this->initFont();
	this->initText();
}

Game::~Game()
{
	delete this->window;
}

//Public functions

bool Game::running()
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::spawnSwagBalls()
{
	if (this->timer >= this->spawnTimerMax)
	{
		
		if (this->swagballs.size() < this->maxSwagBals)
		{
			SwagBall ball(*this->window, this->randomizeType());

			this->swagballs.push_back(ball);
			

			this->timer = 0.f;
		}
	}
}


const int Game::randomizeType() const
{
	int type = SwagBallType::DEFAULT;
	int randVal = rand() % 101;

	if (randVal > 60 && randVal <= 80)
		type = SwagBallType::DAMAGING;
	else if (randVal > 80 && randVal <= 100)
		type = SwagBallType::HEALING;

	return type;
}

//Updates
void Game::update()
{
	this->pollEvents();

	this->updateClock();

	this->spawnSwagBalls();

	this->updatePlayer();

	this->updateCollision();
	
	this->updateGui();
}

void Game::updateClock()
{
	if (this->timer < this->spawnTimerMax)
		this->timer += this->clock.getElapsedTime().asSeconds();
	clock.restart();
}

const bool& Game::getEndGame() const
{
	return this->endGame;
}

void Game::updateCollision()
{
	//Check the collision
	for (size_t i = 0; i < this->swagballs.size(); i++)
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->swagballs[i].getShape().getGlobalBounds()))
		{
			switch (this->swagballs[i].getType())
			{
			case SwagBallType::DEFAULT:
				//add points
				this->points++;
				break;
			case SwagBallType::DAMAGING:
				this->player.takeDamage(2);
				break;
			case SwagBallType::HEALING:
				this->player.gainHealth(1);
				break;
			default:
				break;
			}

			

			//remove the ball
			this->swagballs.erase(this->swagballs.begin() + i);
		}
	}
	
}

void Game::updateGui()
{
	std::stringstream ss;

	ss << "Points: " << this->points << "\n"
		<< "Health: " << this->player.getHp() << " / " << this->player.getHpMax();

	this->guiText.setString(ss.str());
}

 //Renders
void Game::render()
{
	this->window->clear();

	//Draw stuff
	this->player.render(this->window);

	this->renderSwagBalls(this->window);

	this->renderGui(this->window);

	this->window->display();
}

void Game::renderGui(sf::RenderTarget* target)
{
	target->draw(this->guiText);
}

void Game::updatePlayer()
{
	this->player.update(this->window);

	if (this->player.getHp() <= 0)
	{
		this->endGame = true;
	}
}

//Inits
void Game::initFont()
{
	if (!this->font.loadFromFile("Fonts/Cabin-Regular-TTF.ttf"))
	{
		PLOGD << "Error: font not loaded";
	}
}

void Game::initText()
{
	//GUI text init
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(32);
	this->guiText.setString("TEST");
}

void Game::setPlayerPos()
{
	this->player.setPlayerPos(
		sf::Vector2f(this->window->getSize().x / 2 - this->player.getShape().getGlobalBounds().width / 2, 
			this->window->getSize().y / 2 - this->player.getShape().getGlobalBounds().height / 2)
	);
}




void Game::renderSwagBalls(sf::RenderTarget* target)
{
	for (auto sb : this->swagballs)
		sb.render(target);
}
