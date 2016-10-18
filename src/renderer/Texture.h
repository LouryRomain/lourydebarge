// Generated by dia2code
#ifndef RENDERER__TEXTURE__H
#define RENDERER__TEXTURE__H

#include <SFML/Graphics.hpp>
#include <string>

namespace renderer {
  class Render;
}

#include "Render.h"

namespace renderer {

  /// class Texture - 
  class Texture : public renderer::Render {
    // Attributes
  public:
    sf::Sprite sprite;
    sf::Texture texture;
  private:
    sf::Vector2u size;
    // Operations
  public:
    Texture ();
    ~Texture ();
    sf::Sprite load_texture (std::string path, sf::Vector2f pos);
    sf::Vector2u getSize ();
    void setSize (sf::Vector2u size);
  };

};

#endif
