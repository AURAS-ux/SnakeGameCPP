#pragma once
#include"SFML/Graphics.hpp"
#include<time.h>

class Food
{
private:
	sf::Vector2f foodSize;
	sf::Vector2f foodPosition;
	sf::RectangleShape* food;

	void initFood();
	void initVar();
	
public:
	Food();
	~Food();
	sf::RectangleShape* getFood();
	sf::Vector2f getRandomPos();
	void setPos(sf::Vector2f);
};

