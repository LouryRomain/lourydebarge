// Generated by dia2code
#ifndef ENGINE__MOVE_UNIT__H
#define ENGINE__MOVE_UNIT__H

#include <state/Element.h>

namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "Command.h"

namespace engine {

  /// class Move_unit - 
  class Move_unit : public engine::Command {
    // Attributes
  public:
    int id_terr_to;
    int id_terr_from;
    int nb_unit;
    // Operations
  public:
    Move_unit (int id_terr_to, int id_terr_from, int nb_unit);
    ~Move_unit ();
    void make (state::State& state);
    Move_unit ();
    void demake (state::State& state);
  };

};

#endif
