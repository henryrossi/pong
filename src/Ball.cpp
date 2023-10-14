#include <SFML/Graphics.hpp>
#include "Ball.hpp"
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

    sf::FloatRect ballBoundingBox = ball.getGlobalBounds();

    // if ball is more on top of bar than hitting the side of it, don't return the ball
    if (ballBoundingBox.intersects(leftBoundingBox))
    {
        if (ballBoundingBox.left < leftBoundingBox.left)
        {
            return;
        }
        returnBall(leftBoundingBox, ballBoundingBox);
        return;
    }
    if (ballBoundingBox.intersects(rightBoundingBox))
    {
        if (ballBoundingBox.left > rightBoundingBox.left)
        {
            return;
        }
        returnBall(rightBoundingBox, ballBoundingBox);
        return;
    }
}

void Ball::returnBall(sf::FloatRect barBoundingBox, sf::FloatRect ballBoundingBox)
{
    int xDirection;
    if (velocity.x > 0)
        xDirection = -1;
    else
        xDirection = 1;
    float barMidpoint = barBoundingBox.top + barBoundingBox.height / 2;
    float ballMidpoint = ballBoundingBox.top + ballBoundingBox.height / 2;
    float normalizedContactPosition = (barMidpoint - ballMidpoint) / (barBoundingBox.height / 2 + ballBoundingBox.height);
    float maxBounceAngle = 5 * M_PI / 12; // 75 degrees
    float bounceAngle = normalizedContactPosition * maxBounceAngle;
    float ballSpeed = 5;
    velocity.x = ballSpeed * xDirection * cos(bounceAngle);
    velocity.y = ballSpeed * -sin(bounceAngle);
}