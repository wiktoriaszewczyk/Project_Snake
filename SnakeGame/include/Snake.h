#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include "Cell.h"

class Snake {
public:

private:
	std::list<Cell> _body;
	sf::Keyboard::Key _direction;
};