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
	Game(sf::RenderWindow& window);
	bool isGameOver();
	void startGame();
	void drawStartScreen();
	void drawGame();
	void setDirection(sf::Keyboard::Key direction);
	sf::Keyboard::Key getDirection();
	void update();

private:
	sf::RenderWindow& _window;
	bool _gameOver = true;
	sf::Keyboard::Key _direction = sf::Keyboard::Key::Unknown;

	sf::Font _font;
	sf::Text _currentScoreText;
	sf::Text _bestScoreText;
	sf::Text _pressEnterText;
	sf::Texture _backgroundStartScreenTexture;
	sf::Texture _backgroundTexture;
	sf::Texture _appleTexture;
	sf::Sprite _backgroundStartScreenSprite;
	sf::Sprite _backgroundSprite;

	Cell _apple;
	Snake _snake;

	int _bestScore = 0;
	int _currentScore = 0;

};