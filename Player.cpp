#include "Player.h"
#include "Tilemap.h"


void Player::load()
{
	//loading texture
	if (!texture.loadFromFile("images/mario.png"))
	{
		std::cout << "could not load\n";
	}

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 17, 24));
	sprite.setPosition(sf::Vector2f(100.0f, 100.0f));
	sprite.setOrigin(sf::Vector2f(8, 24));
	sprite.setScale(1, 1);
	wallbound.setSize(sf::Vector2f(20, 12));
	wallbound.setOrigin(9, 24);
	sizeX = 17;
	sizeY = 24;
	animIndex = 17;
	jumpSound.openFromFile("sound/jump.wav");
}

void Player::update()
{
	//change mario to big mario when he reaches half level
	if (sprite.getPosition().x > 1000)
	{
		lifeIndex = 2;
	}

	//the rectangle next to mario that checks for collision with walls, isn't perfect But I will improveo on this
	wallbound.setPosition(sprite.getPosition().x, sprite.getPosition().y);
	moving = false;
	//This class takes into account both small and big mario, no fire mario yet sorry :(
	//The lifeIndexes are used for 3 values. 0 - dead, 1 - small , 2 - big
	if (lifeIndex == 1)
	{
		sizeX = 17;
		sizeY = 24;
		animIndex = 17;
		Ycord = 0;

		if (clock[0].getElapsedTime().asSeconds() > 0.3) {

			sprite.setTextureRect(sf::IntRect(0, 0, sizeX, sizeY));
			clock[0].restart();
		}
		
	}
	else if (lifeIndex == 2)
	{
		sizeX = 17;
		sizeY = 30;
		animIndex = 34;
		Ycord = 54;

		if (clock[0].getElapsedTime().asSeconds() > 0.3) {

			sprite.setTextureRect(sf::IntRect(0, 53, sizeX, sizeY));
			clock[0].restart();
		}
	}



	
	//move right
	if (right)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			moving = true;
			sprite.setScale(1, 1);
			if (movespeed < maxspeed)
			{
				movespeed += 0.01;
				sprite.move(movespeed, 0);
			}
			else
			{
				sprite.move(maxspeed, 0);
			}
			//This is how I did animations
			if (this->clock[1].getElapsedTime().asSeconds() > 0.2)
			{

				if (this->index == animIndex)
				{
					this->index = 0;
					sprite.setTextureRect(sf::IntRect(index, Ycord, sizeX, sizeY));
				}
				else
				{
					this->index += 17;
					sprite.setTextureRect(sf::IntRect(index, Ycord, sizeX, sizeY));
				}
				clock[1].restart();
			}
		}
	}

	//move left
	if (sprite.getPosition().x > 0) {
		if (left)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				moving = true;
				sprite.setScale(-1, 1);
				if (movespeed < maxspeed)
				{
					movespeed += 0.01;
					sprite.move(-movespeed, 0);
				}
				else
				{
					sprite.move(-maxspeed, 0);
				}

				if (this->clock[1].getElapsedTime().asSeconds() > 0.2)
				{

					if (this->index == animIndex)
					{
						this->index = 0;
						sprite.setTextureRect(sf::IntRect(index, Ycord, sizeX, sizeY));
					}
					else
					{
						this->index += 17;
						sprite.setTextureRect(sf::IntRect(index, Ycord, sizeX, sizeY));
					}
					clock[1].restart();
				}
			}

		}}

	
		//jump
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && !jumping)
		{
			if (!isGrounded)
			{
				jumpSound.play();
			}
			moving = true;
			velocity.y = -jumpForce;
			if (lifeIndex == 1)
			{
				sprite.setTextureRect(sf::IntRect(102, 0, sizeX, sizeY));
			}
			else if (lifeIndex == 2)
			{
				sprite.setTextureRect(sf::IntRect(142, 53, sizeX, sizeY));
			}

			sprite.move(0, -jumpForce);
			jumping = true;
			jumpForce -= 0.5;
			if(jumpForce<3)
				if (lifeIndex == 1)
				{
			sprite.setTextureRect(sf::IntRect(119, 0, sizeX, sizeY));
					
				}
				else if (lifeIndex == 2)
				{
					sprite.setTextureRect(sf::IntRect(164, 53, sizeX, sizeY));
				}

		if (isGrounded)
		{
			jumpForce = 15;
		}
	jumping = false;
		}
	

	
}



void Player::gravity(float pull, bool state)
{
	if (state)
	{
		sprite.move(0, pull);
	}
	
}


void Player::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Player::die()
{
	//death fucntion that makes mario fall to the bottom when he is touched by a goomba
	if (lifeIndex == 0) {

		moving = false;
		sprite.setTextureRect(sf::IntRect(399, 0, 17, 24));
		deathGravity += 0.5;
		sprite.move(0, deathGravity);
	}
	else if(lifeIndex == 2) 
	{

		lifeIndex--;

	}
	

}




