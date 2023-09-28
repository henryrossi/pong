#include <SFML/Graphics.hpp>
#include "Ball.hpp"

Ball::Ball() : ball(sf::Vector2f(10.f, 10.f))
{
    ball.setPosition(640, 320);
}