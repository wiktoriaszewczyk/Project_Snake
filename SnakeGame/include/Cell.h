#pragma once
#include <SFML/Graphics.hpp>
#include "define.h"

// Representation of an apple or part of a snake
// 40px x 40px 
class Cell {
public:
	Cell();

	void setPosition(float x, float y);
	void setImage(sf::Texture texture);

	float getPositionX() const;
	float getPositionY() const;
	sf::Sprite& getSprite();

private:
	float _positionX = 0;
	float _positionY = 0;
	sf::Texture _texture;
	sf::Sprite _sprite;
};