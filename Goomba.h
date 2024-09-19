#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
class Goomba
{
public:
    // no need for a load function since we load the coin values in the constructor
    void update();
    void draw(sf::RenderWindow& window);
    bool collide(sf::Sprite player);
    bool headCollide(sf::Sprite player);
    void gravity(float pull);
    void die();
    Goomba(float x, float y);
    std::vector<sf::Sprite> sprites;
    sf::Vector2f getPosition();
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    int index;
    int lifeIndex=1;
    float deathGravity = 10.5f;
    sf::RectangleShape head;
};

