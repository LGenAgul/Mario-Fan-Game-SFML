#include "decors.h"


decors::decors(int x, int y,int type)
{

    texture.loadFromFile("images/decors.png");
    sprite.setTexture(texture);
    if(type==0)
    {
        sprite.setTextureRect(sf::IntRect(14, 6, 77, 106));
    }
    else  if (type == 1)
    {
        sprite.setTextureRect(sf::IntRect(107, 94, 46, 18));
    }
    sprite.setPosition(x, y);
}

void decors::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void decors::load()
{
    texture.loadFromFile("images/decors.png");
    sprite.setTexture(texture);
    
}
