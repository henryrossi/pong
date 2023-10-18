#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Score.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(858, 525), "pong");
    window.setFramerateLimit(60);

    Paddle leftBar(1);
    Paddle rightBar(2);

    Ball ball;
    sf::VertexArray centerLine(sf::Quads, 120);
    // needs to be readjusted
    for (int i = 0; i < 30; i++)
    {
        centerLine[i * 4].position = sf::Vector2f(425, 10 * 2 * i + 5);
        centerLine[(i * 4) + 1].position = sf::Vector2f(431, 10 * 2 * i + 5);
        centerLine[(i * 4) + 2].position = sf::Vector2f(431, 10 * (2 * i + 1) + 5);
        centerLine[(i * 4) + 3].position = sf::Vector2f(425, 10 * (2 * i + 1) + 5);
    }

    sf::Font font;
    if (!font.loadFromFile("./src/bit5x3.ttf"))
        return 1;
    Score leftScore(font, 1);
    Score rightScore(font, 2);

    // Game Loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            leftBar.moveUp();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            leftBar.moveDown();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            rightBar.moveUp();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            rightBar.moveDown();

        ball.moveBall(leftBar.getGlobalBounds(), rightBar.getGlobalBounds());

        sf::Vector2f ballPosiiton = ball.getPosition();
        if (ballPosiiton.x < 0)
        {
            rightScore.increaseScore();
            ball.reset();
        }
        if (ballPosiiton.x > 848)
        {
            leftScore.increaseScore();
            ball.reset();
        }

        window.clear();
        window.draw(leftBar);
        window.draw(rightBar);
        window.draw(ball);
        window.draw(leftScore);
        window.draw(rightScore);
        window.draw(centerLine);
        window.display();
    }

    return 0;
}