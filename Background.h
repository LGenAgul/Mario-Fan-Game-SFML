#include <SFML/Graphics.hpp>

#pragma once
class Background
{
public:
	sf::Sprite bg[3];
	sf::Texture tx[3];

	void load(sf::View view);
	void update(sf::View view, bool moving);
	void draw(sf::RenderWindow& window);

};

