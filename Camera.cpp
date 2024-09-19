#include "Camera.h"

void Camera::load(float scale)
{
	view.setCenter(sf::Vector2f(100.f, 0.f));
	view.setSize(sf::Vector2f(800.f / scale, 400.f) / scale);
}

void Camera::update(sf::Sprite player, float movespeed, float maxspeed)
{
	//camera to right
	if (player.getPosition().x > view.getCenter().x+offset)
	{
		if (movespeed < maxspeed)
		{
			movespeed += 0.01;
			view.move(movespeed, 0);
		}
		else
		{
			view.move(maxspeed, 0);
		}
	}
	//camera to left

	else if (view.getCenter().x >= 100) {
		if(player.getPosition().x < view.getCenter().x - offset)
	{
		if (movespeed < maxspeed)
		{
			movespeed += 0.01;
			view.move(-movespeed, 0);
		}
		else
		{
			view.move(-maxspeed, 0);
		}
	}
	}
	//vertical
	if (view.getCenter().y < 50) {
		if (player.getPosition().y - 50 > view.getCenter().y + offset)
		{
			if (movespeed < maxspeed)
			{
				movespeed += 0.01;
				view.move(0, movespeed);
			}
			else
			{
				view.move(0, maxspeed);
			}
		}
	}
	else if (player.getPosition().y-50 < view.getCenter().y - offset)
	{
		if (movespeed < maxspeed)
		{
			movespeed += 0.01;
			view.move(0,-movespeed);
		}
		else
		{
			view.move(0,-maxspeed);
		}
	}

}

void Camera::draw(sf::RenderWindow& window)
{
	window.setView(view);
}