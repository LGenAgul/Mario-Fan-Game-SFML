#include <SFML/Graphics.hpp>

#pragma once
class decors
{
public:
	void draw(sf::RenderWindow& window);
	void load();

	decors(int x, int y,int type);
	sf::Sprite sprite;
	sf::Texture texture;


};

