#include <SFML/Graphics.hpp>

class Paddle : public sf::Drawable, public sf::Transformable
{
private:
    sf::RectangleShape paddle;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = NULL;
        target.draw(paddle, states);
    }

public:
    Paddle(int playerNumber);
    void setAsPlayer(int playerNumber);
    void moveUp();
    void moveDown();
    sf::FloatRect getGlobalBounds() { return paddle.getGlobalBounds(); }
};