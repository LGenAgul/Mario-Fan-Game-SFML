#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#pragma once
class UI
{
public:
    sf::Font font;
    sf::Text text;
    sf::Sprite coin;
    sf::Texture texture;
    int coinCount=0;
    void load();
    void update(sf::View view);
    void draw(sf::RenderWindow& window);
};

