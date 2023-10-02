#include <SFML/Graphics.hpp>
#include <iostream>
#include "PlayerBar.hpp"
#include "Ball.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(858, 525), "pong");
    window.setFramerateLimit(60);
    sf::Clock clock;

    PlayerBar leftBar;
    PlayerBar rightBar;
    leftBar.setAsPlayer(1);
    rightBar.setAsPlayer(2);
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
    {
        return 1;
    }

    sf::Text leftScore("0", font, 100);
    sf::Text rightScore("0", font, 100);
    leftScore.setPosition(328, 0);
    rightScore.setPosition(528, 0);

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
        {
            leftBar.moveUp();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            leftBar.moveDown();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            rightBar.moveUp();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            rightBar.moveDown();
        }

        ball.moveBall(leftBar.getGlobalBounds(), rightBar.getGlobalBounds());

        sf::Vector2f ballPosiiton = ball.getPosition();
        if (ballPosiiton.x < 0 || ballPosiiton.x > 848) {
            std::cout << "Score!" << std::endl;
            ball.reset();
        }

        // sf::Time elapsed = clock.getElapsedTime();
        // std::cout << elapsed.asSeconds() << std::endl;

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