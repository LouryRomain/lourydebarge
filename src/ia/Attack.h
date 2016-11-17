// Generated by dia2code
#ifndef IA__ATTACK__H
#define IA__ATTACK__H

#include <vector>
#include <state/Element.h>

namespace engine {
  class Move_unit;
};
namespace state {
  class State;
}

#include "engine/Move_unit.h"

namespace ia {

  /// class Attack - 
  class Attack {
    // Attributes
  public:
    std::vector<engine::Move_unit> list_attack;
    std::vector<int> list_score;
    // Operations
  public:
    void score_attack (state::State& state);
    Attack ();
    ~Attack ();
    void init (state::State& state, int gang);
  };

};

#endif