#include "SFML/Graphics.hpp"

#pragma once
class Camera
{
public:
	sf::View view;
	float offset = 5.0f;

	void load(float scale);
	void update(sf::Sprite player, float movespeed, float maxspeed);
	void draw(sf::RenderWindow& window);
};