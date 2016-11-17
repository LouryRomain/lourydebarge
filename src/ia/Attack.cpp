#include "Attack.h"
#include "state/State.h"
#include "engine/Engine.h"
#include <iostream>

ia::Attack::Attack() {

}

ia::Attack::~Attack() {

}

void ia::Attack::score_attack(state::State& state) {
    

                
        }        
    

void ia::Attack::init(state::State& state, int gang){
    list_attack.clear();

    list_score.clear();
    engine::Move_unit attack;
    int init=0;
    std::vector<state::Territory> list_territory=state.getlistterritorygang(gang);
    for(int i=0;i<list_territory.size();i++)
    for ( int j=0;j<list_territory[i].getAdajcent().size();j++){
        if(state.list_territory[list_territory[i].getAdajcent()[j]].get_gang()!=gang)
           if(list_territory[i].get_nb_unit()>1)
           if(list_territory[i].get_nb_unit()>state.list_territory[list_territory[i].getAdajcent()[j]].get_nb_unit()){
       attack=engine::Move_unit(list_territory[i].getAdajcent()[j],list_territory[i].get_ID(),state.list_territory[list_territory[i].getAdajcent()[j]].get_nb_unit()+1);
        
        
        
        list_attack.push_back(attack);
        list_score.push_back(init);}
       
    }
    
}