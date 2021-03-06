// Generated by dia2code
#ifndef STATE__STATE__H
#define STATE__STATE__H

#include <state/Element.h>
#include <vector>

namespace state {
  class ListElement;
  class Gang;
  class Territory;
  class State;
}

#include "ListElement.h"
#include "Gang.h"
#include "Territory.h"
#include "STATE.h"

namespace state {

  /// class State - 
  class State {
    // Associations
    // Attributes
  private:
    std::vector<state::ListElement> list_ListElement;
    std::vector<Gang> list_gang;
    std::vector<state::Territory> list_territory;
    // Operations
  public:
    State ();
    ~State ();
    std::vector<ListElement> getListListElement () const;
    void add_ListElement (state::ListElement ListElement);
    std::vector<Gang> getListGang () const;
    void add_Gang (state::Gang& Gang);
    void upDate ();
    void init ();
    void notifier ();
    std::vector<state::Territory> getlistterritorygang (int gang) const;
    std::vector<state::Territory> get_list_territory () const;
    void add_territory (state::Territory territory);
    state::State clone () const;
    void set_list_gang (std::vector<state::Gang> list_gang);
    void set_list_element (std::vector<state::ListElement> list_element);
    void set_list_territory (std::vector<state::Territory> list_territory);
  };

};

#endif
