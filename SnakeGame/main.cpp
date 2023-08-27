#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "include/define.h"
#include "include/Game.h"

int main()
{
    // Window Icon //////////////////////////////////////////////////////////////////////
    sf::Image windowIcon;
    windowIcon.loadFromFile("img/pink_snake_tongue_pixel.png");
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT), "Snake");
    window.setIcon(windowIcon.getSize().x, windowIcon.getSize().y, windowIcon.getPixelsPtr());

    Game game(window);


    /*
    // Snake movement  //////////////////////////////////////////////////////////////////
    sf::Clock clock; // starts the clock   

    float speed = 0.25;
    sf::Keyboard::Key direction = sf::Keyboard::Key::Right;
    direction = sf::Keyboard::Key::Right;
    float snakeHeadPositionX = START_POSITION_X, snakeHeadPositionY = START_POSITION_Y;

    // snake test
    sf::Texture snakeTest;
    snakeTest.loadFromFile("img/pink_snake_tongue_pixel.png");
    sf::Sprite snakeTestSprite(snakeTest);
    snakeTestSprite.setPosition(snakeHeadPositionX, snakeHeadPositionY);

    */
    
    window.setFramerateLimit(10);

    while (window.isOpen())
    {
        window.clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (game.isGameOver()) {
            game.drawStartScreen();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                game.startGame();
                game.setDirection(sf::Keyboard::Right);
            }
        }
        else {
            // Keyboard handler ////////////////////////////////////////////////////
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && game.getDirection() != sf::Keyboard::Right)
            {
                game.setDirection(sf::Keyboard::Left);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && game.getDirection() != sf::Keyboard::Left)
            {
                game.setDirection(sf::Keyboard::Right);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && game.getDirection() != sf::Keyboard::Down)
            {
                game.setDirection(sf::Keyboard::Up);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && game.getDirection() != sf::Keyboard::Up)
            {
                game.setDirection(sf::Keyboard::Down);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }

            game.update();
            game.drawGame();
        }

        window.display();
    }

    return 0;
}