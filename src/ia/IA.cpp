#include "IA.h"
#include "engine/Move_unit.h"
#include "state/State.h"
#include "Attack.h"
#include "Defence.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

ia::IA::IA(int gang) {
    this->gang = gang;

}

ia::IA::~IA() {

}

void ia::IA::play(state::State& state) {

    std::srand(std::time(0));

    ia::Attack attack;
    attack.init(state, gang);
    std::cout << attack.list_attack.size() << std::endl;
    ia::Defence defence;
    defence.init(state, gang);


    if (attack.list_attack.size() != 0) {
        int nb_attack=std::rand() % attack.list_attack.size();
        action.id_terr_to = attack.list_attack[nb_attack].id_terr_to;

        action.id_terr_from = attack.list_attack[nb_attack].id_terr_from;
        action.nb_unit = attack.list_attack[nb_attack].nb_unit;
    } else {
        int nb_defence=std::rand() % defence.list_defence.size();
        action.id_terr_to = defence.list_defence[nb_defence].id_terr_to;

        action.id_terr_from = defence.list_defence[nb_defence].id_terr_from;
        action.nb_unit = defence.list_defence[nb_defence].nb_unit;
    }



}

int ia::IA::get_gang() {
    return gang;
}

void ia::IA::set_gang(int gang) {
    this->gang = gang;
}

std::vector<int> ia::IA::get_List() {
    return list_territory;
}

void ia::IA::add_List(int territory) {
    list_territory.push_back(territory);
}

void ia::IA::remote_list() {
    list_territory.clear();
}

void ia::IA::Update(state::State& state) {
    
    //udsate des teritoire occupé par l'IA
    this->remote_list();
    int index_QG=-1;
    for (int i = 0; i < state.list_territory.size(); i++)
        if (state.list_territory[i].get_gang() == gang){
            this->add_List(state.list_territory[i].get_ID());
            if (state.list_territory[i].get_QG()==1)
                index_QG=i;
        }
    
    //Achat des unités
    if(index_QG!=-1)
    for (int t=0;t<state.getListGang().size();t++)
    if(state.getListGang()[t].ID==gang){
        
        if(state.getListGang()[t].get_money()>10){
            state.list_territory[index_QG].set_nb_unit(state.list_territory[index_QG].get_nb_unit()+static_cast<int>(state.getListGang()[t].get_money()/10));
            state.getListGang()[t].set_money(state.getListGang()[t].get_money()-static_cast<int>(state.getListGang()[t].get_money()/10)*10);
        }
        
    }
    
    
}