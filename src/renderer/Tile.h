// Generated by dia2code
#ifndef RENDERER__TILE__H
#define RENDERER__TILE__H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

namespace renderer {

  /// class Tile - 
  class Tile {
    // Attributes
  public:
    const int* tiles;
    int size;
    std::vector<sf::Vector2i> pos_tour;
    const int* tiles_territory;
    sf::Image image;
    sf::Vector2u image_dim;
    std::vector<sf::Vector2i> pos_chiffre;
    // Operations
  public:
    void convert (std::string path);
    ~Tile ();
    Tile ();
  };

};

#endif
