#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

#include "include/define.h"

int main()
{
    sf::Image windowIcon;
    windowIcon.loadFromFile("img/pink_snake_tongue_pixel.png");
   
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT), "Snake");
    window.setIcon(windowIcon.getSize().x, windowIcon.getSize().y, windowIcon.getPixelsPtr());

    // background
    sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("img/background.png"))
        return 1;

    sf::Sprite backgroundSprite(backgroundTexture);

    backgroundSprite.setPosition(0, 0);

    // snake test
    sf::Texture snakeTest;
    snakeTest.loadFromFile("img/pink_snake_tongue_pixel.png");
    sf::Sprite snakeTestSprite(snakeTest);
    snakeTestSprite.setPosition(8 * BLOCK_SIZE, 7 * BLOCK_SIZE);

    // apple test
    sf::Texture appleTest;
    appleTest.loadFromFile("img/apple.png");
    sf::Sprite appleTestSprite(appleTest);
    appleTestSprite.setPosition(10 * BLOCK_SIZE, 4 * BLOCK_SIZE);

    sf::Keyboard::Key direction;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Keyboard handler ////////////////////////////////////////////////////
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction != sf::Keyboard::Right)
        {
            direction = sf::Keyboard::Left;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction != sf::Keyboard::Left)
        {
            direction = sf::Keyboard::Right;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction != sf::Keyboard::Down)
        {
            direction = sf::Keyboard::Up;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction != sf::Keyboard::Up)
        {
            direction = sf::Keyboard::Down;
        }

        std::cout << direction << std::endl;



        window.clear();

        window.draw(backgroundSprite);
        window.draw(snakeTestSprite);
        window.draw(appleTestSprite);
        
        window.display();
    }

    return 0;
}