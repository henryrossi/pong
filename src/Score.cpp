#include <SFML/Graphics.hpp>
#include "Score.hpp"
#include <iostream>

Score::Score(sf::Font &font, int playerNumber) : score(std::to_string(0), font, 100)
{
    count = 0;
    switch (playerNumber)
    {
    case 1:
        score.setPosition(339, 0);
        break;
    case 2:
        score.setPosition(479, 0);
        break;
    default:
        std::cout << "Error: Invalid player number: " << playerNumber << std::endl;
        std::cout << "vaild player numbers are 1 or 2" << std::endl;
    }
}

void Score::increaseScore()
{
    count++;
    score.setString(std::to_string(count));
    // Move left once it hits double digits to keep alignment
    if (count >= 10 && score.getPosition().x == 339)
        score.setPosition(279, 0);
}