#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

class Tilemap : public sf::Drawable, public sf::Transformable
{
public:
   
    int offset = 0;
    int mapWidth;
    int mapHeight;
    int tileSize;
    std::vector<std::vector<int>> mapArray;
    sf::Texture tileSheet;
    sf::VertexArray vertices;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    sf::Vector2u m_tileSize;

  
    bool checkCollision(const sf::Rect<float>& object,int lifeindex) const;
    bool rightcheck(sf::RectangleShape object);
    bool leftcheck(sf::RectangleShape object);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
};
