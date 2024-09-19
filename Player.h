#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#pragma once
class Player
{
public:
	int sizeX;
	int sizeY;
	int Ycord=0;
	int animIndex;
	int lifeIndex = 1;
	float accel = 1.5;
	float grav = 0.5f;
	sf::Vector2f velocity;
	bool isGrounded;
	bool jumping ;
	bool moving;
	bool left = true;
	bool right = true;
	 float jumpForce=50;
	int index = 0;
	sf::Clock clock[10];
	float movespeed = 1, maxspeed = 2;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Music jumpSound;
	void load();
	void update();
	void gravity(float pull,bool state);
	void jump();
	void die();
	float deathGravity = -10.5f;
	sf::RectangleShape wallbound;
	//void animate(int index,int row, float freq);
	void draw(sf::RenderWindow& window);


};