#include "Game.hpp"
#include<iostream>


void Game::_initVar()
{
	this->width = 1920;
	this->height = 1080;
	this->videoMode.height = height;
	this->videoMode.width = width;
	this->videoMode.bitsPerPixel = 32;
	this->snakeObj = new std::vector<Snake>();
	this->head = new Snake();
	head->setPosition(sf::Vector2f(500,500));
	this->snakeObj->push_back(*this->head);
	_time = sf::seconds(0.1f);
	food = new Food();
	text = new sf::Text();
	font.loadFromFile("IBMPlexSansThaiLooped-Thin.ttf");
	text->setFont(font);
	text->setPosition(860, 50);
	text->setCharacterSize(24);
	//text->setColor(sf::Color::White);
	score = 0;
	text->setStyle(sf::Text::Style::Bold);
	tail = new Snake();
	tail->setPosition(sf::Vector2f(440, 500));
	snakeObj->push_back(*this->tail);
}

void Game::_initWindow()
{
	this->window = new sf::RenderWindow();
	this->window->create(videoMode, "Snake",sf::Style::Fullscreen);
	this->window->setFramerateLimit(144);
}

Game::Game()
{
	_initVar();
	_initWindow();
}

Game::~Game()
{
	delete this;
}

bool Game::isRunning()
{
	return this->window->isOpen();
	
}

void Game::pollEvents()
{
	while (window->pollEvent(ev))
	{
		if (ev.type == sf::Event::KeyPressed)
		{
			if (ev.key.code == sf::Keyboard::Escape)
			{
				window->close();
			}
			sf::Vector2f newDirection = snakeDir;
			switch (ev.key.code)
			{
			case sf::Keyboard::W:
				newDirection = { 0.f, -16.f };
				break;
			case sf::Keyboard::S:
				newDirection = { 0.f, 16.f };
				break;
			case sf::Keyboard::A:
				newDirection = { -16.f, 0.f };
				break;
			case sf::Keyboard::D:
				newDirection = { 16.f, 0.f };
				break;
			default:
				break;
			}
			if (std::abs(snakeDir.x) != std::abs(newDirection.x) || std::abs(snakeDir.y) != std::abs(newDirection.y))
			{
				snakeDir = newDirection;
			}	
			
		}
	}

}
void Game::gameRender()
{
	this->window->clear(sf::Color(51, 52, 57, 255) );
	this->renderSnake(this->window);
	this->renderFood(this->window);
	this->window->draw(*text);
	this->window->display();
}

void Game::renderSnake(sf::RenderTarget* tr)
{
	for (int i = 0; i < snakeObj->size(); i++)
	{
		tr->draw(snakeObj->at(i).getSnakeSegment());
	}
}

void Game::renderFood(sf::RenderTarget* tr)
{
	tr->draw(*this->food->getFood());
}


void Game::update()
{	
	this->gameRender();
	this->pollEvents();
	this->checkBorderCollsion();
	
	
	
	this->moveParts();
	
	
	
	this->snakeObj->begin()->moveSnake(snakeDir * DeltaTime());
	if (this->checkCollision(*food) == 1) {
		this->addNewSegment();
	}
	
	
	sf::sleep(_time);
	
}

float Game::DeltaTime()
{
	return clock.restart().asSeconds()*40.f;
}

void Game::addNewSegment()
{
	Snake segment;
	for (int i = 0; i < snakeObj->size(); i++) {
		segment.setPosition(sf::Vector2f(snakeObj->back().getSnakeSegment().getPosition().x - 52, snakeObj->back().getSnakeSegment().getPosition().y));
	}
	//segment.setPosition(sf::Vector2f(tail->getPosition().x - 52, tail->getPosition().y));
	snakeObj->push_back(segment);

}

void Game::moveParts()
{
	for (int i = 1; i < snakeObj->size(); i++) {
		this->snakeObj->at(i).setPosition(sf::Vector2f(this->snakeObj->at(i - 1).getPosition()));
	}
	
}

sf::Vector2u Game::getWindowSize()
{
	return this->window->getSize();
}

int Game::checkCollision(Food food)
{
	if (this->head->getSnakeSegment().getGlobalBounds().intersects(food.getFood()->getGlobalBounds())) {
		this->food->setPos(food.getRandomPos());
		score++;
		return 1;
	}
	text->setString("Your score is:" + std::to_string(score));
	return 0;
}

void Game::checkBorderCollsion()
{
	if (snakeObj->at(0).getSnakeSegment().getGlobalBounds().left <= 0) {
		snakeObj->at(0).setPosition(sf::Vector2f(0, snakeObj->at(0).getSnakeSegment().getGlobalBounds().top));
	}
	if (snakeObj->at(0).getSnakeSegment().getGlobalBounds().left + snakeObj->at(0).getSnakeSegment().getGlobalBounds().width >= this->window->getSize().x) {
		snakeObj->at(0).setPosition(sf::Vector2f(window->getSize().x - snakeObj->at(0).getSnakeSegment().getGlobalBounds().width,snakeObj->at(0).getSnakeSegment().getGlobalBounds().top));
	}
	if (snakeObj->at(0).getSnakeSegment().getGlobalBounds().top <= 0) {
		snakeObj->at(0).setPosition(sf::Vector2f(snakeObj->at(0).getSnakeSegment().getGlobalBounds().left, 0));
	}
	if (snakeObj->at(0).getSnakeSegment().getGlobalBounds().top + snakeObj->at(0).getSnakeSegment().getGlobalBounds().height >= window->getSize().y) {
		snakeObj->at(0).setPosition(sf::Vector2f(snakeObj->at(0).getSnakeSegment().getGlobalBounds().left, window->getSize().y - snakeObj->at(0).getSnakeSegment().getGlobalBounds().height));
	}
}

