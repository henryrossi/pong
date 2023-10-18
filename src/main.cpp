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
    sf::VertexArray centerLine(sf::Quads, 26 * 4);
    for (int i = 0; i < 26; i++)
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
    sf::Text Winner("", font, 40);

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
        // Update Section
        if (leftScore.getScore() < 11 && rightScore.getScore() < 11)
        {
            // Handle user input for paddle movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                leftBar.moveUp();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                leftBar.moveDown();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                rightBar.moveUp();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                rightBar.moveDown();

            // Move ball and check for collisions with paddles
            ball.moveBall(leftBar.getGlobalBounds(), rightBar.getGlobalBounds());

            // Check for a goal
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
        }

        // Check for a Winner
        if (leftScore.getScore() >= 11){
            Winner.setString("Player 1 is the winner!");
            Winner.setPosition(200, 200);
        }
        if (rightScore.getScore() >= 11){
            Winner.setString("Player 2 is the winner!");
            Winner.setPosition(200, 200);
        }

        // Draw game
        window.clear();
        window.draw(leftBar);
        window.draw(rightBar);
        window.draw(ball);
        window.draw(leftScore);
        window.draw(rightScore);
        window.draw(centerLine);
        window.draw(Winner);
        window.display();
    }

    return 0;
}