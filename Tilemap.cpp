#include "Tilemap.h"
#include "iostream";

    bool Tilemap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
    {
        // load the tileset texture
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // resize the vertex array to fit the level size
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // populate the vertex array, with one quad per tile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // get the current tile number
                int tileNumber = tiles[i + j * width];

                // find its position in the tileset texture
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // get a pointer to the current tile's quad
                sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                // define its 4 corners
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }

    
  void  Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

  


  


 
      bool Tilemap::checkCollision(const sf::Rect<float>&object,int lifeindex) const
      {
          //firstly, if mario is alive he must collide
          if (lifeindex != 0) {
              for (unsigned int i = 0; i < m_vertices.getVertexCount(); i += 4)
              {
                  //since 0 indexed tile is air/nothing we don't collide it with mario
                  if (m_vertices[i].texCoords.x == 0 && m_vertices[i].texCoords.y == 0)
                      continue;
                  sf::FloatRect tileBounds(m_vertices[i].position.x, m_vertices[i].position.y,
                      m_tileset.getSize().x / 6, m_tileset.getSize().y / 6);
                  //following simple AABB collision
                  if (object.left + object.width <= tileBounds.left || object.left >= tileBounds.left + tileBounds.width)
                      continue;
                  if (object.top + object.height <= tileBounds.top || object.top >= tileBounds.top + tileBounds.height)
                      continue;
                  return true;
              }
          }
          return false;
      }

     // side checks
      bool Tilemap::rightcheck(sf::RectangleShape object)
      {
          for (unsigned int i = 0; i < m_vertices.getVertexCount(); i += 4)
          {
              if (m_vertices[i].texCoords.x != 0 && m_vertices[i].texCoords.y != 0)

              {
                  sf::FloatRect tileBounds(m_vertices[i].position.x, m_vertices[i].position.y,
                      m_tileset.getSize().x / 6, m_tileset.getSize().y / 6);
                      if (object.getGlobalBounds().left + object.getGlobalBounds().width <= tileBounds.left)
                          continue;
                      if (object.getGlobalBounds().top + object.getGlobalBounds().height <= tileBounds.top || object.getGlobalBounds().top >= tileBounds.top + tileBounds.height)
                          continue;
                      return true;
              }
          }
          return false;
      }

      bool Tilemap::leftcheck(sf::RectangleShape object)
      {
          for (unsigned int i = 0; i < m_vertices.getVertexCount(); i += 4)
          {
              if (m_vertices[i].texCoords.x != 0 && m_vertices[i].texCoords.y != 0)

              {
                  sf::FloatRect tileBounds(m_vertices[i].position.x, m_vertices[i].position.y,
                      m_tileset.getSize().x / 6, m_tileset.getSize().y / 6);
                  if (object.getGlobalBounds().left >= tileBounds.left + tileBounds.width || object.getGlobalBounds().left + object.getGlobalBounds().width <= tileBounds.left)
                      continue;
                  if (object.getGlobalBounds().top + object.getGlobalBounds().height <= tileBounds.top || object.getGlobalBounds().top >= tileBounds.top + tileBounds.height)
                      continue;
                  return true;;
              }
          }
          return false;
      }

      