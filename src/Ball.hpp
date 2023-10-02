#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable, public sf::Transformable
{
private:
    sf::RectangleShape ball;
    float velocity;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = NULL;
        target.draw(ball, states);
    }

public:
    Ball();

    void changeVelocity() { velocity *= -1; }
    void moveBall() { ball.move(velocity, 0); }

    sf::FloatRect getBounds() { return ball.getGlobalBounds(); }
};