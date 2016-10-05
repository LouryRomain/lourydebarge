// Generated by dia2code
#ifndef STATE__GANG__H
#define STATE__GANG__H

#include <string>

namespace state {

  /// class Gang - 
  class Gang {
    // Attributes
  private:
    int money;
    int unit;
    int nb_card_all;
    bool alive;
    std::string name;
    // Operations
  public:
    Gang ();
    ~Gang ();
    void set_nb_card_gang (int nb_card_gang);
    int get_nb_card_gang ();
    void set_money (int money);
    int get_money ();
    void set_alive (bool alive);
    bool get_alive ();
    void set_nb_unit (int nb_unit);
    int get_unit ();
    std::string get_name ();
    void set_name (std::string name);
  };

};

#endif
