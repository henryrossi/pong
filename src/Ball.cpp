#include <SFML/Graphics.hpp>
#include "Ball.hpp"

Ball::Ball() : ball(sf::Vector2f(10.f, 10.f)), velocity(1.f, 1.f)
{
    ball.setPosition(400, 265);
}

void Ball::moveBall()
{
    ball.move(velocity);
    sf::Vector2f position = ball.getPosition();
    if (position.y < 0) {
        ball.setPosition(position.x, 0);
        velocity.y *= -1;
    }
    if (position.y > 515) {
        ball.setPosition(position.x, 515);
        velocity.y *= -1;
    }
}