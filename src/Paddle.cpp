#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.hpp"

Paddle::Paddle(int playerNumber) : paddle(sf::Vector2f(10.f, 50.f))
{
    setAsPlayer(playerNumber);
}

void Paddle::setAsPlayer(int playerNumber)
{
    switch (playerNumber)
    {
    case 1:
        paddle.setPosition(50, 260);
        break;
    case 2:
        paddle.setPosition(808, 260);
        break;
    default:
        // Throw error
        std::cout << "Error: Invalid player number: " << playerNumber << std::endl;
        std::cout << "vaild player numbers are 1 or 2" << std::endl;
    }
}

void Paddle::moveUp() {
    if (paddle.getPosition().y <= 25) {
        return;
    }
    paddle.move(0, -10);
}

void Paddle::moveDown() {
    if (paddle.getPosition().y >= 450) {
        return;
    }
    paddle.move(0, 10);
}