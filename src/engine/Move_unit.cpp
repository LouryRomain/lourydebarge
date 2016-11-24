#include <cmath>

#include "Move_unit.h"
#include "state/State.h"
#include <iostream>

engine::Move_unit::Move_unit(int id_terr_to, int id_terr_from, int nb_unit) {
    this->id_terr_to = id_terr_to;
    this->id_terr_from = id_terr_from;
    this->nb_unit = nb_unit;
}

engine::Move_unit::Move_unit() {

}

engine::Move_unit::~Move_unit() {

}

void engine::Move_unit::make(state::State& state,std::vector<engine::Move_unit>& list_action) {


    if (state.get_list_territory()[id_terr_from].get_nb_unit() - nb_unit > 0) {
        state.get_list_territory()[id_terr_from].set_nb_unit(state.get_list_territory()[id_terr_from].get_nb_unit() - nb_unit);
    
        if (state.get_list_territory()[id_terr_from].get_gang() == state.get_list_territory()[id_terr_to].get_gang()){
                if(state.get_list_territory()[id_terr_to].get_nb_unit() + nb_unit < 100)
            state.get_list_territory()[id_terr_to].set_nb_unit(state.get_list_territory()[id_terr_to].get_nb_unit() + nb_unit);
                else  state.get_list_territory()[id_terr_to].set_nb_unit(99);
        }else {
            if (state.get_list_territory()[id_terr_to].get_nb_unit() - nb_unit > 0) {
                state.get_list_territory()[id_terr_to].set_nb_unit(state.get_list_territory()[id_terr_to].get_nb_unit() - nb_unit);
            } else {
                state.get_list_territory()[id_terr_to].set_nb_unit(-state.get_list_territory()[id_terr_to].get_nb_unit() + nb_unit);
                state.get_list_territory()[id_terr_to].set_gang(state.get_list_territory()[id_terr_from].get_gang());
               
            }
        }

    }
    
    list_action.push_back(*this);
  
}

void engine::Move_unit::demake(state::State& state,std::vector<engine::Move_unit>& list_action) {
    

    
    state.get_list_territory()[id_terr_from].set_nb_unit(state.get_list_territory()[id_terr_from].get_nb_unit() + nb_unit);
      
       if(state.get_list_territory()[id_terr_to].get_nb_unit() - nb_unit>0){
          
    state.get_list_territory()[id_terr_to].set_nb_unit(state.get_list_territory()[id_terr_to].get_nb_unit() - nb_unit);
        
       }
    else
    {
    state.get_list_territory()[id_terr_to].set_nb_unit(-state.get_list_territory()[id_terr_to].get_nb_unit() + nb_unit);
        state.get_list_territory()[id_terr_to].set_gang(state.get_list_territory()[id_terr_to].get_old_gang());
        state.get_list_territory()[id_terr_to].old_gang.pop_back();
        state.get_list_territory()[id_terr_to].old_gang.pop_back();
    }
    
    list_action.pop_back();
    
    
    }