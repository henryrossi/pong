#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable, public sf::Transformable
{
private:
    sf::RectangleShape ball;
    sf::Vector2f velocity;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = NULL;
        target.draw(ball, states);
    }

public:
    Ball();

    void changeVelocity() { velocity.x *= -1; }
    sf::Vector2f getPosition() { return ball.getPosition(); }
    void moveBall(sf::FloatRect leftBoundingBox, sf::FloatRect rightBoundingBox);
    void reset() { ball.setPosition(400, 265); }

    // sf::FloatRect getGlobalBounds() { return ball.getGlobalBounds(); }
};