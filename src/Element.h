// Generated by dia2code
#ifndef ELEMENT__H
#define ELEMENT__H

/// class Element - 
class Element {
  // Attributes
public:
  sf::Vector2f pos;
  sf::Sprite sprite;
  std::string path;
  renderer::Texture texture;
  sf::Vector2f scale;
private:
  sf::Vector2i* anim;
  sf::Vector2i dim;
  int type;
  // Operations
public:
  Element ();
  Element (std::string path, sf::Vector2f pos, sf::Vector2f scale);
  ~Element ();
  Element (std::string path, sf::Vector2f pos, sf::Vector2f scale, sf::Vector2i anim, sf::Vector2i dim, int type);
  void init ();
  sf::Vector2i getAnim ();
  void setAnim (sf::Vector2i anim);
  void setDim (sf::Vector2i dim);
  sf::Vector2i getDim ();
  int getType ();
  void setType (int type);
};

#endif
