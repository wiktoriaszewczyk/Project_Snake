#include "../include/Game.h"
#include <iostream>
Game::Game(sf::RenderWindow& window)
:_window(window)
{
 
    // Loading font and textures from the files
    if (!_font.loadFromFile("img/Minecraft.ttf") ||
        !_backgroundStartScreenTexture.loadFromFile("img/backgroundStartScreen.png") ||
        !_backgroundTexture.loadFromFile("img/background.png") ||
        !_appleTexture.loadFromFile("img/apple.png"))
    {
        _gameOver = true;
        std::cout << "Failed to load image" << std::endl;
    }

    // Setting start screen graphic 
    _backgroundStartScreenSprite.setTexture(_backgroundStartScreenTexture);
    _backgroundStartScreenSprite.setPosition(0, 0);

    _currentScoreText.setFont(_font);
    _currentScoreText.setFillColor(sf::Color(90, 90, 90));
    _currentScoreText.setString("          SCORE:    " + std::to_string(_currentScore));
    _currentScoreText.setPosition(5 * BLOCK_SIZE + 5, 5 * BLOCK_SIZE);

    _bestScoreText.setFont(_font);
    _bestScoreText.setFillColor(sf::Color(90, 90, 90));
    _bestScoreText.setString("BEST SCORE:    " + std::to_string(_bestScore));
    _bestScoreText.setPosition(5 * BLOCK_SIZE + 5, 7 * BLOCK_SIZE);

    _pressEnterText.setFont(_font);
    _pressEnterText.setFillColor(sf::Color(90, 90, 90));
    _pressEnterText.setString("PRESS ENTER TO PLAY");
    _pressEnterText.setPosition(4 * BLOCK_SIZE + 5, 9 * BLOCK_SIZE);

    // Setting game graphic
    _backgroundSprite.setTexture(_backgroundTexture);
    _backgroundSprite.setPosition(0, 0);

    _apple.setImage(_appleTexture);
    _apple.setPosition(11 * BLOCK_SIZE, 7 * BLOCK_SIZE);


}

bool Game::isGameOver()
{
    return _gameOver;
}

void Game::startGame()
{
    _gameOver = false;
}

void Game::drawStartScreen()
{
    _window.draw(_backgroundStartScreenSprite);
    _window.draw(_pressEnterText);
    _window.draw(_currentScoreText);
    _window.draw(_bestScoreText);
}

void Game::drawGame()
{
    _window.draw(_backgroundSprite);
    _window.draw(_apple.getSprite());
    for (unsigned i = 0; i < _snake.size(); i++)
        _window.draw(_snake.getSprite(i));

}

void Game::setDirection(sf::Keyboard::Key direction)
{
    _direction = direction;
}

sf::Keyboard::Key Game::getDirection()
{
    return _direction;
}

void Game::update() {
    _snake.move(_direction);
}
