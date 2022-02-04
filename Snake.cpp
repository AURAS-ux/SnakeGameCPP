#include "Snake.hpp"


Snake::Snake()
{
	_initVar();
	_initSnake();
}

Snake::~Snake()
{
	//delete this->snakeSegment;
}

void Snake::_initVar()
{
	this->snakeW = 50.f;
	this->snakeH = 50.f;
	_time = sf::seconds(0.1f);
}

void Snake::_initSnake()
{
	snakeSegment = new sf::RectangleShape();
	snakeSegment->setSize(sf::Vector2f(snakeW, snakeH));
	//snakeSegment->setPosition(sf::Vector2f(500,500));
}


sf::RectangleShape Snake::getSnakeSegment()
{
	return *this->snakeSegment;
}

void Snake::renderSegment(sf::RenderTarget* tr)
{
	tr->draw(*this->snakeSegment);
}

void Snake::moveSnake(sf::Vector2f direction)
{
	snakeSegment->setPosition(snakeSegment->getPosition() + direction);
}

float Snake::DeltaTime()
{
	return clock.restart().asSeconds();
}

void Snake::setPosition(sf::Vector2f newPos)
{
	this->snakeSegment->setPosition(newPos);
}

sf::Vector2f Snake::getPosition()
{
	return this->snakeSegment->getPosition();
}




