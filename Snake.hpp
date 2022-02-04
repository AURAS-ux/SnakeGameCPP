#pragma once
#include"SFML/Graphics.hpp"
enum Directions {
	STOP = 0,UP,LEFT,RIGHT,DOWN
};

class Snake
{
private:
	float snakeW;
	float snakeH;
	sf::RectangleShape* snakeSegment;
	sf::Clock clock;
	sf::Time _time;

	void _initVar();
	void _initSnake();
public:
	Snake();
	~Snake();
	sf::RectangleShape getSnakeSegment();
	void renderSegment(sf::RenderTarget*);
	void moveSnake(sf::Vector2f);
	float DeltaTime();
	void setPosition(sf::Vector2f);
	sf::Vector2f getPosition();
};

