// Generated by dia2code
#ifndef STATE__PLAYER__H
#define STATE__PLAYER__H


namespace state {
  class Gang;
  class Element;
}

#include "Gang.h"

namespace state {

  /// class Player - 
  class Player {
    // Associations
    // Attributes
  public:
    int* view_posX;
    int* view_posY;
    state::Gang gang;
    state::Element* tour_cliked;
  private:
    int* compteur;
    int* chiffre_pris;
    // Operations
  public:
    Player ();
    ~Player ();
    void Update ();
    int getCompteur ();
    void setCompteur (int compteur);
    int get_chiffre_pris ();
    void set_chiffre_pris (int chiffre_pris);
  };

};

#endif
