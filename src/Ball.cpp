#include <SFML/Graphics.hpp>
#include "Ball.hpp"
#include <math.h>
#include <random>
#include <chrono>
#include <functional>

#define defaultSpeed 5.f

Ball::Ball() : ball(sf::Vector2f(10.f, 10.f)),velocity(defaultSpeed, defaultSpeed)
{

    ball.setPosition(400, 265);
    ballSpeed = defaultSpeed;
}

void Ball::reset()
{
    // sleep a few seconds, maybe do this in the game loop?
    ballSpeed = defaultSpeed;
    int xDirection;
    if (velocity.x > 0)
        xDirection = 1;
    else
        xDirection = -1;
    std::default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> heightDistribution(25, 500);
    std::uniform_int_distribution<int> angleDistribution(-4, 4); // 1/12 of a radian
    int yPosition = heightDistribution(engine);
    float angle = angleDistribution(engine) * M_PI / 12;
    ball.setPosition(410, yPosition);
    velocity.x = ballSpeed * xDirection * cos(angle);
    velocity.y = ballSpeed * -sin(angle);
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
    if (ballBoundingBox.intersects(leftBoundingBox))
    {
        if (ballBoundingBox.left < leftBoundingBox.left)
            return;
        returnBall(leftBoundingBox, ballBoundingBox);
        return;
    }
    if (ballBoundingBox.intersects(rightBoundingBox))
    {
        if (ballBoundingBox.left > rightBoundingBox.left)
            return;
        returnBall(rightBoundingBox, ballBoundingBox);
        return;
    }
}

void Ball::returnBall(sf::FloatRect paddleBoundingBox, sf::FloatRect ballBoundingBox)
{
    int xDirection;
    if (velocity.x > 0)
        xDirection = -1;
    else
        xDirection = 1;
    float paddleMidpoint = paddleBoundingBox.top + paddleBoundingBox.height / 2;
    float ballMidpoint = ballBoundingBox.top + ballBoundingBox.height / 2;
    float normalizedContactPosition = (paddleMidpoint - ballMidpoint) / (paddleBoundingBox.height / 2 + ballBoundingBox.height);
    float maxBounceAngle = 4 * M_PI / 12; // 75 degrees
    float bounceAngle = normalizedContactPosition * maxBounceAngle;
    // move the ball to the front of the paddle to avoid double collision
    if (velocity.x > 0)
        ball.setPosition(paddleBoundingBox.left - ballBoundingBox.width, ball.getPosition().y);
    else
        ball.setPosition(paddleBoundingBox.left + ballBoundingBox.width, ball.getPosition().y);
    velocity.x = ballSpeed * xDirection * cos(bounceAngle);
    velocity.y = ballSpeed * -sin(bounceAngle);
    ballSpeed *= 1.1;
}