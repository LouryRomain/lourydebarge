// Generated by dia2code
#ifndef CONTROL__OBSERVABLE__H
#define CONTROL__OBSERVABLE__H

#include <state/Element.h>

namespace state {
  class IObservateur;
}

#include "state/IObservateur.h"

namespace control {

  /// class Observable - 
  class Observable {
    // Operations
  public:
    void ajouterObserver (state::IObservateur IObservateur);
    void notifierObservateur ();
  };

};

#endif
