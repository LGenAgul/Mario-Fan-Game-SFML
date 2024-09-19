#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
class Coin
{
public:
   // no need for a load function since we load the coin values in the constructor
    void update();
    void draw(sf::RenderWindow& window);
    bool collide(sf::Sprite player);
    Coin(float x, float y);
    std::vector<sf::Sprite> sprites;
    sf::Vector2f getPosition();
    sf::Sprite sprite;
    sf::Texture texture;
   // sf::Music coinSound;
    sf::Clock clock;
    int index;
};
