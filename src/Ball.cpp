#include <SFML/Graphics.hpp>
#include "Ball.hpp"

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
    // funky if ball hits top/bottom of bar or bar moves onto ball's position
    // also need to implement variable return angles
    if (ballBoundingBox.intersects(leftBoundingBox)){
        velocity.x *= -1;
    }
    if (ballBoundingBox.intersects(rightBoundingBox)){
        velocity.x *= -1;
    }
}