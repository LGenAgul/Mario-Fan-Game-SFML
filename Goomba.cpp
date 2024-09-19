#include "Goomba.h"


Goomba::Goomba(float x, float y)
{
    //constructor to place many goombas
    head.setSize(sf::Vector2f(18, 6));
	index = 0;
	sprite.setPosition(x, y);
}
void Goomba::update()
{
    //animating and moving the goombas
    head.setPosition(sprite.getPosition().x-1, sprite.getPosition().y-6);
    sprite.move(-1, 0);
    texture.loadFromFile("images/goomba.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 20, 16));;
    if (clock.getElapsedTime().asMilliseconds() > 100)
    {
        sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));;
        if (index == 20)
        {
            index = 0;
            sprite.setTextureRect(sf::IntRect(index, 0, 16, 16));
        }
        else
        {
            index += 20;
            sprite.setTextureRect(sf::IntRect(index, 0, 16, 16));
        }
        clock.restart();
    }
}

void Goomba::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
   // window.draw(head);
}
//since mario reacts differently to colliision from sides and top, I created 2 different functions
bool Goomba::collide(sf::Sprite player)
{
    if (lifeIndex == 1) {
        if (sprite.getGlobalBounds().intersects(player.getGlobalBounds()))
        {
            return true;
        }
    }
	return false;
}

bool Goomba::headCollide(sf::Sprite player)
{
    if (head.getGlobalBounds().intersects(player.getGlobalBounds()))
    {
        return true;
        player.move(0, -5);
    }
    return false;
}


sf::Vector2f Goomba::getPosition()
{
	return sf::Vector2f();
}


void Goomba::gravity(float pull)
{
    sprite.move(0, pull);
    

}

void Goomba::die()
{
    sprite.setScale(1, -1);
    deathGravity += 0.5;
    sprite.move(0, deathGravity);
}
