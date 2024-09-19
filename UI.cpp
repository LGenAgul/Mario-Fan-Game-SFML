#include "UI.h"


void UI::load()
{
	texture.loadFromFile("images/coins.png");
	coin.setTexture(texture);
	coin.setTextureRect(sf::IntRect(0, 0, 16, 16));
	

	//coin counting
	font.loadFromFile("Mario-Kart-DS.ttf");
	text.setFont(font);
	text.setPosition(100, 50);
	text.setScale(0.5, 0.5);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(3);
}

void UI::update(sf::View view)
{
	//I needed to create an int counter for coins, and convert it to string so I could visually display it on the screen
	coin.setPosition(view.getCenter().x - 100, view.getCenter().y - 100);
	text.setPosition(view.getCenter().x-80, view.getCenter().y-103);
	std::stringstream ss;
	ss << coinCount;
	std::string str = ss.str();
	text.setString(str);
}

void UI::draw(sf::RenderWindow& window)
{
	window.draw(coin);
	window.draw(text);
}
