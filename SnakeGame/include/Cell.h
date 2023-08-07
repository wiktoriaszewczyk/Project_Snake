#pragma once
#include <SFML/Graphics.hpp>

// Representation of an apple or part of a snake
class Cell {
public:
	Cell();
	void setPositionX(float x);
	void setPositionY(float y);

private:
	float _positionX;
	float _positionY;
	sf::Sprite _sprite;
};