#include <SFML/Graphics.hpp>
#include "Ball.hpp"

Ball::Ball() : ball(sf::Vector2f(10.f, 10.f))
{
    velocity = -1.f;
    ball.setPosition(400, 265);
}