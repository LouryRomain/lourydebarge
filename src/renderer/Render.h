// Generated by dia2code
#ifndef RENDERER__RENDER__H
#define RENDERER__RENDER__H

#include <SFML/Graphics.hpp>
#include <vector>

namespace renderer {
  class View;
};
namespace state {
  class State;
};
namespace ihm {
  class Player;
}

#include "View.h"
#include "state/State.h"
#include "ihm/Player.h"

namespace renderer {

  /// class Render - 
  class Render {
    // Associations
    // Attributes
  public:
    sf::RenderWindow window;
    std::vector<renderer::View> list_view;
    // Operations
  public:
    ~Render ();
    void init (const state::State state_game);
    void draw (ihm::Player player);
    Render ();
    void upDate (const state::State state_game, ihm::Player player);
  };

};

#endif
