#include <SFML/Graphics.hpp>

class Score : public sf::Drawable, public sf::Transformable
{
private:
    sf::Text score;
    int count;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = NULL;
        target.draw(score, states);
    }

public:
    Score(sf::Font &font, int playerNumber);
    void increaseScore();
    int getScore() { return count; }
};