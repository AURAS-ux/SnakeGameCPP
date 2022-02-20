#include "Food.hpp"

void Food::initFood()
{
	this->getRandomPos();
	food->setPosition(foodPosition);
	food->setSize(foodSize);
}

void Food::initVar()
{
	foodSize.x = 50;
	foodSize.y = 50;
	food = new sf::RectangleShape();
	srand(time(NULL));
}

sf::Vector2f Food::getRandomPos()
{
	foodPosition.x = rand() % 1800;
	foodPosition.y = rand() % 800;
	return sf::Vector2f(foodPosition.x, foodPosition.y);
}

void Food::setPos(sf::Vector2f pos)
{
	this->food->setPosition(pos);
}

Food::Food()
{
	initVar();
	initFood();
	food->setFillColor(sf::Color::Red);
	
}

Food::~Food()
{
}

sf::RectangleShape* Food::getFood()
{
	return this->food;
}
