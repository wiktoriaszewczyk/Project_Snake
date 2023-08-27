#include "../include/Snake.h"

Snake::Snake()
{
	if (!_snakeTexture.loadFromFile("img/snake.png"))
    {
        std::cout << "Failed to load image" << std::endl;
    }
	restartSnake();
}

Snake::~Snake()
{
	clear();
}

void Snake::clear()
{
	for (unsigned i = 0; i < _body.size(); i++) {
		delete _body[i];
	}
	_body.clear();
}

void Snake::restartSnake()
{
	clear();
	Cell* head = new Cell();
	Cell* body1 = new Cell();
	Cell* body2 = new Cell();
	Cell* tail = new Cell();

	head->setImage(_snakeTexture);
	body1->setImage(_snakeTexture);
	body2->setImage(_snakeTexture);
	tail->setImage(_snakeTexture);

	head->setPosition(4 * BLOCK_SIZE, 7 * BLOCK_SIZE);
	body1->setPosition(3 * BLOCK_SIZE, 7 * BLOCK_SIZE);
	body2->setPosition(2 * BLOCK_SIZE, 7 * BLOCK_SIZE);
	tail->setPosition(1 * BLOCK_SIZE, 7 * BLOCK_SIZE);

    _body.push_back(tail);
	_body.push_back(body2);
	_body.push_back(body1);
	_body.push_back(head);
}

sf::Sprite& Snake::getSprite(unsigned i)
{
	return _body[i]->getSprite();
}

unsigned Snake::size()
{
	return _body.size();
}

void Snake::move(sf::Keyboard::Key direction)
{
	float x = 0, y = 0;
	if (direction == sf::Keyboard::Left)
	{
		x = -BLOCK_SIZE;
		y = 0;
	}
	else if (direction == sf::Keyboard::Right)
	{
		x = BLOCK_SIZE;
		y = 0;
	}
	else if (direction == sf::Keyboard::Up)
	{
		x = 0;
		y = -BLOCK_SIZE;
	}
	else if (direction == sf::Keyboard::Down)
	{
		x = 0;
		y = BLOCK_SIZE;
	}

	Cell* tmp = nullptr;
	tmp = _body[0];
	_body.pop_front();
	tmp->setPosition(_body[size() - 1]->getPositionX() + x, _body[size() - 1]->getPositionY() + y);
	_body.push_back(tmp);
}
