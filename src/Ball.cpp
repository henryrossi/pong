#include <SFML/Graphics.hpp>
#include "Ball.hpp"
#include <iostream>
#include <math.h>

Ball::Ball() : ball(sf::Vector2f(10.f, 10.f)), velocity(5.f, 5.f)
{
    ball.setPosition(400, 265);
}

void Ball::moveBall(sf::FloatRect leftBoundingBox, sf::FloatRect rightBoundingBox)
{
    ball.move(velocity);
    sf::Vector2f position = ball.getPosition();
    if (position.y < 0)
    {
        ball.setPosition(position.x, 0);
        velocity.y *= -1;
    }
    if (position.y > 515)
    {
        ball.setPosition(position.x, 515);
        velocity.y *= -1;
    }

    // Does this need to be before the move?
    // Or does the ball's position need to be adjusted like when it's slightly off the screen?
    sf::FloatRect ballBoundingBox = ball.getGlobalBounds();
    // funky if ball hits top/bottom of bar or bar moves onto ball's position
    // also need to implement variable return angles

    // if ball is more on top of bar than hitting the side of it, don't return the ball
    if (ballBoundingBox.intersects(leftBoundingBox))
    {
        // Maybe this return statement should be reworked
        if (ballBoundingBox.left < leftBoundingBox.left + (leftBoundingBox.width) / 2)
        {
            return;
        }
        returnBall(leftBoundingBox, ballBoundingBox, 1);
    }
    if (ballBoundingBox.intersects(rightBoundingBox))
    {
        if (ballBoundingBox.left + ballBoundingBox.width > rightBoundingBox.left + (rightBoundingBox.width) / 2)
        {
            return;
        }
        returnBall(rightBoundingBox, ballBoundingBox, -1);
    }
}

void Ball::returnBall(sf::FloatRect barBoundingBox, sf::FloatRect ballBoundingBox, int xDirection)
{
    float barMidpoint = barBoundingBox.top + barBoundingBox.height / 2;
    float ballMidpoint = ballBoundingBox.top + ballBoundingBox.height / 2;
    float normalizedContactPosition = (barMidpoint - ballMidpoint) / (barBoundingBox.height / 2 + ballBoundingBox.height);
    float maxBounceAngle = 5 * M_PI / 12; // 75 degrees
    float bounceAngle = normalizedContactPosition * maxBounceAngle;
    float ballSpeed = 5;
    velocity.x = ballSpeed * xDirection * cos(bounceAngle);
    velocity.y = ballSpeed * -sin(bounceAngle);
}