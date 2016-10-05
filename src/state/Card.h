// Generated by dia2code
#ifndef STATE__CARD__H
#define STATE__CARD__H


namespace state {
  class Gang;
}

#include "Gang.h"

namespace state {

  /// class Card - 
  class Card {
    // Associations
    // Attributes
  private:
    char type;
    int nb_card_owned;
    int effect;
    // Operations
  public:
    Card ();
    ~Card ();
    char get_type ();
    void set_type (char type);
    int get_nb_card_owned ();
    void set_nb_card_owned (int nb_card_owned);
    void set_effect (int effect);
    int get_effect ();
  };

};

#endif