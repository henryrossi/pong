#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable, public sf::Transformable
{
private:
    sf::RectangleShape ball;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = NULL;
        target.draw(ball, states);
    }

public:
    Ball();

    sf::FloatRect getBounds() { return ball.getGlobalBounds(); }
};