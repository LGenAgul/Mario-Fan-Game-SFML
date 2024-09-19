#include "Background.h"

void Background::load(sf::View view)
{
	//loading images
	tx[0].loadFromFile("images/BG1.png");
	tx[1].loadFromFile("images/BG2.png");
	tx[2].loadFromFile("images/BG3.png");

	for (int i = 0; i < 3; i++)
	{
		tx[i].setRepeated(true);
		bg[i].setTextureRect(sf::IntRect(0, 0,320*10,320));
		bg[i].setTexture(tx[i]);
		bg[i].setScale(1, 1);
		bg[i].setPosition(-view.getCenter().x / 30 * i + 1, -40);
		//these images must be repeated
	}
}

void Background::update(sf::View view,bool moving)
{
	//move the background according to camera
	bg[0].setPosition(-view.getCenter().x / 30, -100);
	for (int i = 1; i < 3; i++)
	{
		if (moving)
		{
			bg[i].setPosition( -view.getCenter().x/ 30 * i + 1  , -40);
		}
	}
}

void Background::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(bg[i]);
	}
}
