#pragma once
#include <deque>
#include <SFML/Graphics.hpp>
#include "Cell.h"

/*
* _body - first element - tail, last element - head 
*/
class Snake {
public:
	Snake();
	~Snake();
	void clear();
	void restartSnake();
	sf::Sprite& getSprite(unsigned i);
	unsigned size();
	void move(sf::Keyboard::Key direction);

private:
	std::deque<Cell*> _body;
	sf::Texture _snakeTexture;
};