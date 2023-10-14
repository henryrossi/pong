#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable, public sf::Transformable
{
private:
    sf::RectangleShape ball;
    sf::Vector2f velocity;
    // int hitCounter;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = NULL;
        target.draw(ball, states);
    }

    void returnBall(sf::FloatRect barBoundingBox, sf::FloatRect ballBoundingBox);

public:
    Ball();
    void moveBall(sf::FloatRect leftBoundingBox, sf::FloatRect rightBoundingBox);
    sf::Vector2f getPosition() { return ball.getPosition(); }
    void reset() { ball.setPosition(400, 265); }
};