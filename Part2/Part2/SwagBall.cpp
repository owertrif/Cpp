#include "SwagBall.h"



//Constructor/Destructor
SwagBall::SwagBall(const sf::RenderWindow& window, int type)
	: type(type)
{
	this->initVariables();
	this->initShape(window);
}

SwagBall::~SwagBall()
{

}

//Public functions

const sf::CircleShape& SwagBall::getShape() const
{
	return this->shape;
}

const int& SwagBall::getType() const
{
	return this->type;
}

void SwagBall::setType(int type)
{
	this->type = type;
}

//Updates
void SwagBall::update()
{
}

//Renders
void SwagBall::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}




//Private functions
void SwagBall::initVariables()
{

}

void SwagBall::initShape(const sf::RenderWindow& window)
{
	this->shape.setRadius(static_cast<float>(rand() % 11 + 10));
	sf::Color color;
	switch (this->type)
	{
	case DEFAULT:
		color = sf::Color(rand() % 256, rand() % 256, rand() % 256, 255);
		this->shape.setFillColor(color);
		break;
	case DAMAGING:
		this->shape.setFillColor(sf::Color::Red);
		this->shape.setOutlineColor(sf::Color::Yellow);
		this->shape.setOutlineThickness(2.f);
		break;
	case HEALING:
		this->shape.setFillColor(sf::Color::Green);
		this->shape.setOutlineColor(sf::Color::Yellow);
		this->shape.setOutlineThickness(2.f);
		break;
	default:
		break;
	}
	
	this->shape.setPosition(sf::Vector2f(
		static_cast<float>(rand() % window.getSize().x ),
		static_cast<float>(rand() % window.getSize().y)
	));

	if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= window.getSize().x)
		this->shape.setPosition(window.getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
	if (this->shape.getGlobalBounds().left <= 0.f)
		this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);

	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= window.getSize().y)
		this->shape.setPosition(this->shape.getGlobalBounds().left, window.getSize().y - this->shape.getGlobalBounds().height);
	if (this->shape.getGlobalBounds().top <= 0.f)
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
}