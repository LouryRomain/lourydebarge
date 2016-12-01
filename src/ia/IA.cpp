#include "IA.h"
#include "engine/Move_unit.h"
#include "state/State.h"
#include "Attack.h"
#include "Defence.h"
#include "MinMax.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

ia::IA::IA(int gang) {
    this->gang = gang;
    
    
    
    

}

ia::IA::~IA() {

 
}

void ia::IA::play(const state::State& state) {
    
  
    
     
    
    //std::srand(std::time(0));

    ia::Attack attack;
    attack.init(state, gang);
    //attack.create_tab(state,gang);
    //attack.score_attack(state);

    ia::Defence defence;
    defence.init(state, gang);
    std::vector<engine::Move_unit> list_action;
    for (int k = 0; k < defence.list_defence.size(); k++)
            list_action.push_back(defence.list_defence[k]);
    for (int k = 0; k < attack.list_attack.size(); k++)
            list_action.push_back(attack.list_attack[k]);
    
    
        
        

    ia::MinMax minmax;
    minmax.create_tree(state,gang,3);
    int nb_attack=minmax.solve(state,gang,minmax.tree);
 
       action.id_terr_to = list_action[nb_attack].id_terr_to;
        action.id_terr_from = list_action[nb_attack].id_terr_from;
        action.nb_unit = list_action[nb_attack].nb_unit;//}
   // } else {
       /* int nb_defence=std::rand() % defence.list_defence.size();
        action.id_terr_to = defence.list_defence[nb_defence].id_terr_to;

        action.id_terr_from = defence.list_defence[nb_defence].id_terr_from;
        action.nb_unit = defence.list_defence[nb_defence].nb_unit;*/
   // }
       

  
}

int ia::IA::get_gang() const {
    return gang;
}

void ia::IA::set_gang(int gang) {
    this->gang = gang;
}

std::vector<int> ia::IA::get_List() const {
    return list_territory;
}

void ia::IA::add_List(int territory) {
    list_territory.push_back(territory);
}

void ia::IA::remote_list() {
    list_territory.clear();
}

void ia::IA::Update(const state::State& state) {
    
    //udsate des teritoire occupé par l'IA
    this->remote_list();
    int index_QG=-1;
    for (int i = 0; i < state.get_list_territory().size(); i++)
        if (state.get_list_territory()[i].get_gang() == gang){
            this->add_List(state.get_list_territory()[i].get_ID());
            if (state.get_list_territory()[i].get_QG()==1)
                index_QG=i;
        }
    
    
    
    
}