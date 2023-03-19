#ifndef SWAGBALL_H
#define SWAGBALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <plog/Log.h>
#include "plog/Initializers/RollingFileInitializer.h"

enum SwagBallType{DEFAULT = 0, DAMAGING, HEALING, NROFTYPES};

class SwagBall
{
private:
	//Objects
	sf::CircleShape shape;
	int type;


	//Functions
	void initShape(const sf::RenderWindow& window);
	void initVariables();
public:
	//Constructor/Destructor
	SwagBall(const sf::RenderWindow& window, int type);
	virtual ~SwagBall();

	//Accessor
	const sf::CircleShape& getShape()const;
	const int& getType()const;
	void setType(int type);

	//Functions

	void update();

	void render(sf::RenderTarget* target);
};

#endif // !


