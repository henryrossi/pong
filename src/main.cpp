#include <SFML/Graphics.hpp>
#include <iostream>
#include "PlayerBar.hpp"
#include "Ball.hpp"

// We also need center divider and scoreboard

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 640), "pong");
    window.setFramerateLimit(60);
    sf::Clock clock;

    PlayerBar leftBar;
    PlayerBar rightBar;
    leftBar.setAsPlayer(1);
    rightBar.setAsPlayer(2);
    Ball ball;
    sf::VertexArray centerLine(sf::Quads, 144);
    for (int i = 0; i < 32; i++)
    {
        centerLine[i * 4].position = sf::Vector2f(635, 10 * 2 * i + 5);
        centerLine[(i * 4) + 1].position = sf::Vector2f(645, 10 * 2 * i + 5);
        centerLine[(i * 4) + 2].position = sf::Vector2f(645, 10 * (2 * i + 1) + 5);
        centerLine[(i * 4) + 3].position = sf::Vector2f(635, 10 * (2 * i + 1) + 5);
    }

    sf::Font font;
    if (!font.loadFromFile("./src/bit5x3.ttf"))
    {
        return 1;
    }

    sf::Text leftScore("0", font, 100);
    sf::Text rightScore("0", font, 100);
    leftScore.setPosition(500, 0);
    rightScore.setPosition(740, 0);

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
            case sf::Event::KeyPressed:
                if (event.key.scancode == sf::Keyboard::Scan::W)
                {
                    leftBar.moveUp();
                }
                if (event.key.scancode == sf::Keyboard::Scan::S)
                {
                    leftBar.moveDown();
                }
                if (event.key.scancode == sf::Keyboard::Scan::Up)
                {
                    rightBar.moveUp();
                }
                if (event.key.scancode == sf::Keyboard::Scan::Down)
                {
                    rightBar.moveDown();
                }
                break;
            default:
                break;
            }
        }

        sf::FloatRect ballBoundingBox = ball.getBounds();
        sf::FloatRect leftBarBoundingBox = leftBar.getBounds();
        // collision ins't detected
        if (ballBoundingBox.intersects(leftBarBoundingBox))
        {
            ball.setPosition(640, 320);
        }

        ball.move(-10, 0);

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