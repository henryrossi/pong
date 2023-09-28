#include <SFML/Graphics.hpp>
#include <iostream>

class PlayerBar : public sf::Drawable, public sf::Transformable
{
private:
    sf::RectangleShape bar;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = NULL;
        target.draw(bar, states);
    }

public:
    PlayerBar();

    void setAsPlayer(int playerNumber)
    {
        switch (playerNumber)
        {
        case 1:
            bar.setPosition(50, 260);
            break;
        case 2:
            bar.setPosition(1230, 260);
            break;
        default:
            std::cout << "Error: Invalid player number: " << playerNumber << std::endl;
            std::cout << "vaild player numbers are 1 or 2" << std::endl;
        }
    }

    void moveUp() { bar.move(0, -10); }
    void moveDown() { bar.move(0, 10); }
};