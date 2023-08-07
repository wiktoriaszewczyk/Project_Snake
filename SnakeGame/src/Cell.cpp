#include "../include/Cell.h"

Cell::Cell()
	: _positionX(0), _positionY(0)
{
	_texture.create(BLOCK_SIZE, BLOCK_SIZE);	// empty texture
	_sprite.setTexture(_texture);
	_sprite.setPosition(_positionX, _positionY);
}

void Cell::setPosition(float x, float y)
{
	_positionX = x;
	_positionY = y;
	_sprite.setPosition(_positionX, _positionY);
}

void Cell::setImage(sf::Texture texture)
{
	_texture = texture;
	_sprite.setTexture(_texture);
	_sprite.setPosition(_positionX, _positionY);
}

float Cell::getPositionX() const
{
	return _positionX;
}

float Cell::getPositionY() const
{
	return _positionY;
}

sf::Sprite& Cell::getSprite()
{
	return _sprite;
}
