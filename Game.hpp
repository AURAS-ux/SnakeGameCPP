#pragma once
#include"SFML/Graphics.hpp"
#include"Snake.hpp"
#include"Food.hpp"
class Game
{
private:
	int width;
	int height;
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	std::vector<Snake>* snakeObj;
	Snake* head;
	Snake* tail;
	sf::Vector2f snakeDir;
	sf::Clock clock;
	sf::Time _time;
	Food* food;
	sf::Text* text;
	int score;
	sf::Font font;

	void _initVar();
	void _initWindow();
	void pollEvents();
	void gameRender();
	void renderSnake(sf::RenderTarget*);
	void renderFood(sf::RenderTarget*);
public:
	Game();
	~Game();
	bool isRunning();
	void update();
	float DeltaTime();
	void addNewSegment();
	void moveParts();
	sf::Vector2u getWindowSize();
	void checkCollision(Food);
	void checkBorderCollsion();
};

