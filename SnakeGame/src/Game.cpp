#include "../include/Game.h"
#include <iostream>
Game::Game()
: _gameOver(false), _direction(sf::Keyboard::Key::Enter)
{
    // Loading textures from the files
    if (!_backgroundTexture.loadFromFile("img/background.png") ||
        !_appleTexture.loadFromFile("img/apple.png"))
    {
        _gameOver = true;
        std::cout << "Failed to load image" << std::endl;
    }

    // Setting background
    _backgroundSprite.setTexture(_backgroundTexture);
    _backgroundSprite.setPosition(0, 0);

    // Setting apple
    _apple.setImage(_appleTexture);
    _apple.setPosition(11 * BLOCK_SIZE, 7 * BLOCK_SIZE);

    // Seting snake


}

void Game::draw(sf::RenderWindow& window)
{
    window.draw(_backgroundSprite);
    window.draw(_apple.getSprite());
    for (unsigned i = 0; i < snake.size(); i++)
        window.draw(snake.getSprite(i));

}

void Game::setDirection(sf::Keyboard::Key direction)
{
    _direction = direction;
}

sf::Keyboard::Key Game::getDirection()
{
    return _direction;
}

