#include <SFML/Graphics.hpp>
#include <iostream>
#include "PlayerBar.hpp"

PlayerBar::PlayerBar() : bar(sf::Vector2f(10.f, 50.f))
{
}

void PlayerBar::setAsPlayer(int playerNumber)
{
    switch (playerNumber)
    {
    case 1:
        bar.setPosition(50, 260);
        break;
    case 2:
        bar.setPosition(808, 260);
        break;
    default:
        // Throw error
        std::cout << "Error: Invalid player number: " << playerNumber << std::endl;
        std::cout << "vaild player numbers are 1 or 2" << std::endl;
    }
}