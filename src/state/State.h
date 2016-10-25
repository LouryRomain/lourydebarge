// Generated by dia2code
#ifndef STATE__STATE__H
#define STATE__STATE__H

#include <SFML/Graphics.hpp>
#include <vector>

namespace state {
  class Player;
  class Territory;
  class ListElement;
  class Gang;
}

#include "Player.h"
#include "Territory.h"
#include "ListElement.h"
#include "Gang.h"

namespace state {

  /// class State - 
  class State {
    // Associations
    // Attributes
  public:
    int* Mode;
    int nb_territory;
    int nb_gang;
    sf::Image image;
    state::Player player;
    std::vector<state::Territory> list_territory;
    // Operations
  public:
    State ();
    ~State ();
    int get_nb_territory ();
    void set_nb_territory (int nb_territory);
    int get_nb_gang ();
    void set_nb_gang (int nb_gang);
    void setMode (int mode);
    state::Player getPlayer ();
  };

};

#endif
