#include "IA.h"
#include "engine/Move_unit.h"
#include "state/State.h"
#include <iostream>
#include <cstdlib>
#define RAND_MAX 30

  ia::IA::IA (){
      
  }
  ia::IA::~IA (){
      
  }
  void ia::IA::play (state::State& state){
      engine::Move_unit action;
      int terr_to=std::rand()%30;
      int terr_from=std::rand()%30;
      
      int nb_unit=std::rand()%state.list_territory[terr_from].get_nb_unit();
      
      std::cout<<"le territoire "<<terr_to<<" a été attaqué par le territoire "<<terr_from<<" avec "<<nb_unit<<" unités "<<std::endl;
      action.id_terr_from=terr_to;
     
      action.id_terr_to=terr_from;
      action.nb_unit=nb_unit;
      action.make(state);
      
  }

