#include "Coin.h"

//here I used a constructor and paird it with a vector to put different coins in different positions
Coin::Coin(float x, float y)
{
    index = 0;
   
    sprite.setPosition(x, y);
}





void Coin::update()
{
  //follows the same idea of other classes, just animation
    texture.loadFromFile("images/coins.png");
    sprite.setTexture(texture);
    if (clock.getElapsedTime().asMilliseconds() > 50)
    {
    sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));;
        if (index == 224)
        {
            index = 0;
            sprite.setTextureRect(sf::IntRect(index, 0, 16, 16));
        }
        else
        {
            index += 16;
            sprite.setTextureRect(sf::IntRect(index, 0, 16, 16));
        }
        clock.restart();
    }
}

void Coin::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

bool Coin::collide(sf::Sprite player)
{
    //returns true when Mario collides with the coins
    if (player.getGlobalBounds().intersects(sprite.getGlobalBounds()))
    {
       //coinSound.play();
        return true;
    }
    return false;
}

sf::Vector2f Coin::getPosition()
{
    return sprite.getPosition();
}
