#include <SFML/Graphics.hpp>
#include "Score.hpp"
#include <iostream>

Score::Score(sf::Font &font, int playerNumber) : score(std::to_string(0), font, 100)
{
    count = 0;
    switch (playerNumber)
    {
    case 1:
        score.setPosition(328, 0);
        break;
    case 2:
        score.setPosition(528, 0);
        break;
    default:
        // Throw error
        std::cout << "Error: Invalid player number: " << playerNumber << std::endl;
        std::cout << "vaild player numbers are 1 or 2" << std::endl;
    }
}

void Score::increaseScore()
{
    count++;
    score.setString(std::to_string(count));
}