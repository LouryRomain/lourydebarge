// Generated by dia2code
#ifndef STATE__TERRITORY__H
#define STATE__TERRITORY__H

#include <vector>
#include <state/Element.h>

namespace state {
  class Territory;
}


namespace state {

  /// class Territory - 
  class Territory {
    // Attributes
  public:
    std::vector<int> old_gang;
  private:
    int* nb_unit;
    int* gang;
    int ID;
    bool QG;
    std::vector<int> Adjacent;
    // Operations
  public:
    Territory ();
    ~Territory ();
    int get_nb_unit () const;
    void set_nb_unit (int nb_unit);
    int get_gang () const;
    void set_gang (int gang);
    int get_ID () const;
    void set_ID (int ID);
    bool get_QG () const;
    void set_QG (bool boolean_QG);
    std::vector<int> getAdajcent () const;
    void addAdjacent (int adjacent);
    Territory (int nb_unit, int Id, bool QG, int owner);
    state::Territory clone () const;
    int get_old_gang () const;
    void set_old_gang (int gang);
  };

};

#endif
