#include <SFML/Graphics.hpp>

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

    void setAsPlayer(int playerNumber);

    sf::FloatRect getBounds() { return bar.getGlobalBounds(); }

    void moveUp() { bar.move(0, -10); }
    void moveDown() { bar.move(0, 10); }
};