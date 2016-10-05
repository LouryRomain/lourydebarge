// Generated by dia2code
#ifndef STATE__GRAPH__H
#define STATE__GRAPH__H

#include <vector>

namespace state {
  class Territory;
  class Adjacent;
}

#include "Adjacent.h"
#include "Territory.h"

namespace state {

  /// class Graph - 
  class Graph {
    // Associations
    // Attributes
  private:
    std::vector<Territory*> list_summit;
    std::vector<Adjacent*> list_adjacent;
    // Operations
  public:
    Graph ();
    ~Graph ();
    Graph* const clone ();
    void add_summit (Territory* summit);
    void delete_summit (int ID);
    void delete_adjacent (int ID_1, int ID_2);
    void add_adjacent (Adjacent* adjacent);
  };

};

#endif
