#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tilemap.h"
#include "Camera.h"
#include "Player.h"
#include "Background.h"
#include "Coin.h"
#include "UI.h"
#include "Goomba.h"
#include "decors.h"

//My cs50 final project, Mario Fan Game, Please open the Readme file as aswell <3
//The project is made with the help of the wonderful Simple and fast multimedia library (SFML)

//In my classes I follow a simple structure of three standard functions:
//load - which loads the necessary variables,
//update - which changes the object in someway every frame
//draw - which renders it in the window

int main()
{
    //In the main function I created the necessary classes 

    //Firstly I created a 800x600 window and limited the fps to 60
    sf::RenderWindow window(sf::VideoMode(800, 600), "CS50 Final Project");
    window.setFramerateLimit(60);
    //The UI which in this case is a simple coin counter
    UI hud;
    hud.load();
    //The camera that will follow the player smoothly, just like in typical platformer games
    Camera camera;
    camera.load(2);
    //background class, which has 3 layers
    Background bg;
    bg.load(camera.view);

    //Now we these parameters are for the level itself which is comprised of different tiles, more info in the Tilemap class;
    //in this case the amount of horizontal tiles is 125 and the vertical amount is 10, which makes 1250 16x16 tiles in total
    Tilemap map;
    int width = 125;
    int height = 10;
    int size = 16;
    //as you can see I expressed my level as an array of numbers, each number representing a certain tile in the "Tileset.png"
    const int level[] =
    {                                                                                                                                               
     0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,7 ,7 ,7 ,7,7,7,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0 ,  0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0 ,  0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,7 ,7 ,7 ,7 ,7 ,0 ,0 ,0 ,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0 ,  0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0 ,  0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0 ,  0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0 ,  0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,3 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1,1,1,1,1,1,1,1,1,2 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,21,0,0,0,0,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,
0 ,  0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9,9,9,9,9,9,9,9,9,11,1,1,1,1,1,1,1,1,2,0,0,0,0,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,11,0,0,0,0,0,0,0,8,1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,11,
1 ,  1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,2 ,0 ,0 ,0 ,3 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,11,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9,9,9,9,9,9,9,9,9,9 ,9,9,9,9,9,9,9,9,11,0,0,0,0,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,11,0,0,0,0,0,0,0,8,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,11,
9 ,  9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,11,0 ,0 ,0 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9,9,9,9,9,9,9,9,9,9 ,9,9,9,9,9,9 ,9 ,9,11,0,0,0,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,11,11,0,0,0,0,0,0,0,8,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,11,
    };
   //using the array I used the load function from my Tilemap class that outputs the level based on my chosen parameters
    sf::Texture sheet;
    sheet.loadFromFile("images/tiles.png");
    if(!map.load("images/tileset.png", sf::Vector2u(16, 16), level, width, height))
    {
        return -1;
    }
    //This part is about the sounds and Music that play in the game
    // first we create the music object and then assign the corresponding files

    sf::Music music;
    sf::Music coinSound;
    sf::Music stomp;
    sf::Music death;
    music.openFromFile("sound/music.wav");
    music.play();
    music.setLoop(true);
    coinSound.openFromFile("sound/coin.wav");
    stomp.openFromFile("sound/stomp.wav");
    death.openFromFile("sound/death.wav");

    //The player class
    Player mario;
    mario.load();

    //here I used  vectors which make me able to dynamiclly input as many objects as I want
    std::vector<Coin> coins;
    sf::Texture coinTexture;
    sf::Sprite coinSprite;
    coinTexture.loadFromFile("images/coins.png");
    std::vector<Goomba> goombas;
    std::vector<decors> decorations;
    
        
 
    //manually need to put coins
    for (int i = 0; i < 5;i++)
    {   
        coins.push_back(Coin(600+i*30, -20));
        coins.push_back(Coin(750, -20 + i*20));
        coins.push_back(Coin(770+20*i, 50));
        coins.push_back(Coin(1100 + 20 * i, 50));
        coins.push_back(Coin(1200 + 20 * i, 50));


        //C
        coins.push_back(Coin(1500, i*20));
        coins.push_back(Coin(1520+i*20, 0));
        coins.push_back(Coin(1520 + i * 20, 80));
        //S
        coins.push_back(Coin(1520 + 140 + i*20, 0));
        coins.push_back(Coin(1520 + 140 + i * 20, 40));
        coins.push_back(Coin(1520+140 + i * 20, 80));

      //5
        coins.push_back(Coin(1520 + 280 , i * 20));
        coins.push_back(Coin(1520 + 280 + i * 20, 0));
        coins.push_back(Coin(1520 + 280 + i * 20, 40));
        coins.push_back(Coin(1520 + 280 + i * 20, 80));

        //0
        coins.push_back(Coin(1520 + 400, i * 20));
        coins.push_back(Coin(1520 + 400 + i * 20, 0));
        coins.push_back(Coin(1520 + 400 + i * 20, 80));
        coins.push_back(Coin(1520 + 500, i * 20));

    }
    //S
    coins.push_back(Coin(1520 + 140 , 20));
    coins.push_back(Coin(1520 + 220, 60));
    //cs50 with coins
    //goombas
    for (int i = 0; i < 5; i ++)
    {
        goombas.push_back(Goomba(800+i*40, 0));
    }
    //just the Trees and bushes in the background
    for (int i = 0; i < 3; i++)
    {
        decorations.push_back(decors(50+i*150, 24, 0));
        decorations.push_back(decors(450 + i * 150, -10, 0));
        decorations.push_back(decors(100 + i * 120, 110, 1));
        decorations.push_back(decors(550 + i * 120, 90, 1));
    }

    //Here we have the game loop where the magic happens
    // this is the standard for SFML
    while (window.isOpen())
    {
        //load
        for (decors& decor : decorations)
        {
            decor.load();
           
        }

        //If we click the close button with our mouse the window closes
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }


        //whenever mario is not touching the ground, let gravity affect him as long as he is alive
        if (!map.checkCollision(mario.sprite.getGlobalBounds(),mario.lifeIndex))
        {
            mario.gravity(5, true);
            mario.isGrounded = false;

        }
        else
        {
            mario.isGrounded = true;

        }

        //update mario every frame
        mario.update();

        //updating every goomba
        for (Goomba& goomba : goombas)
        {           
            goomba.update();
            //let's gravity affect goombas as long as they are not on the ground
            if (!map.checkCollision(goomba.sprite.getGlobalBounds(),goomba.lifeIndex))
            {
                goomba.gravity(3);
            }

            //if the goombas collide with mario from left or right he dies
            if (goomba.collide(mario.sprite))
            {
                music.stop();
                death.play();
                mario.lifeIndex = 0;
                mario.die();
            }
            //simulates mario jumping on goombas
            if (goomba.headCollide(mario.sprite))
            {
                stomp.play();
                goomba.lifeIndex = 0;
                goomba.die();
               
            }
           
        }

        //stops movement from the side 
        if (map.rightcheck(mario.wallbound))
        {
            mario.left = true;
            mario.right = false;
        }
        else if (map.leftcheck(mario.wallbound))
        {
            mario.left = false;
            mario.right = true;
        }
        else
        {
            mario.right = true;
            mario.left = true;
        }

        //updates the coin counter
        hud.update(camera.view);


        //moves the background according to the camera position
        bg.update(camera.view, mario.moving);
        //moves the camera based on marios position
        camera.update(mario.sprite, 2, 3);

        //coin animations
        for (Coin& coin : coins)
        {
           coin.update();
           
         }
        //collectin coins//
        for (int i = 0; i < coins.size(); i++)
        {
            if (coins[i].collide(mario.sprite))
            {
                coinSound.play();
                hud.coinCount++;
                coins.erase(coins.begin() + i);
                break;
            }
        }
        

        //closing the program
        if (mario.sprite.getPosition().y > 1100.0f)
        {
            exit(1);
        }

        //rendering the game
        //every draw function renders the object on screen
        window.clear(sf::Color{0x70ADD6});
        bg.draw(window);
        for (decors& decor : decorations)
        {
            decor.draw(window);

        }

          

        camera.draw(window);
        window.draw(map);
        for (Goomba& goomba : goombas)
        {
            goomba.draw(window);
        }
        mario.draw(window);
       
        for (Coin& coin : coins)
        {
            coin.draw(window);
        }

        hud.draw(window);
        window.display();
    }

    return 0;
}
