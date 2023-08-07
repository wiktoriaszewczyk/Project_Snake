#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "Snake.h"

/*
* _direction - Left, Right, Down, Up, Enter (null direction -  the snake is not moving)
*/
class Game {
public:
	Game();
	void draw(sf::RenderWindow& window);
	void setDirection(sf::Keyboard::Key direction);
	sf::Keyboard::Key getDirection();

private:
	bool _gameOver = false;
	sf::Keyboard::Key _direction = sf::Keyboard::Key::Enter;

	sf::Texture _backgroundTexture;
	sf::Texture _appleTexture;

	sf::Sprite _backgroundSprite;
	Cell _apple;
	Snake snake;

};