// Generated by dia2code
#ifndef IA__IA__H
#define IA__IA__H

#include <vector>
#include <state/Element.h>

namespace engine {
  class Move_unit;
};
namespace state {
  class State;
};
namespace ia {
  class Defence;
  class Attack;
}

#include "engine/Move_unit.h"
#include "Defence.h"
#include "Attack.h"

namespace ia {

  /// class IA - 
  class IA {
    // Associations
    // Attributes
  public:
    engine::Move_unit action;
  private:
    int gang;
    std::vector<int> list_territory;
    // Operations
  public:
    IA (int gang);
    ~IA ();
    void play (state::State& state);
    int get_gang ();
    void set_gang ( int gang);
    std::vector<int> get_List ();
    void  add_List (int territory);
    void remote_list ();
    void Update (state::State& state);
  };

};

#endif
