#include "Attack.h"
#include "state/State.h"
#include "engine/Engine.h"
#include <iostream>

ia::Attack::Attack() {

}

ia::Attack::~Attack() {

}

void ia::Attack::create_tab(const state::State& state, int gang) {
   


    for (int i = 0; i < list_attack.size(); i++) {

        for (int j = 0; j < state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent().size(); j++)
            if (state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].get_gang() != gang) {
                if (state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].get_nb_unit() > unit_max_1_to[i])
                    unit_max_1_to[i] = state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].get_nb_unit();



                for (int u = 0; u < state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].getAdajcent().size(); u++)
                    if (state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].getAdajcent()[u]].get_gang() != gang) {
                        if (state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].getAdajcent()[u]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].get_nb_unit() > unit_max_2_to[i])
                            unit_max_2_to[i] = state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].getAdajcent()[u]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].get_nb_unit();

                        if (state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].getAdajcent()[u]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].get_nb_unit() < unit_to_conquer_2[i]) {

                            unit_to_conquer_2[i] = 2 + state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].getAdajcent()[u]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].get_nb_unit();

                        }




                        for (int v = 0; v < state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].getAdajcent()[u]].getAdajcent().size(); v++)
                            if (state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].getAdajcent()[u]].getAdajcent()[v]].get_gang() != gang) {
                                if (state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].getAdajcent()[u]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].getAdajcent()[u]].getAdajcent()[v]].get_nb_unit() > unit_max_3_to[i])
                                    unit_max_3_to[i] = state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].getAdajcent()[u]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].getAdajcent()[u]].getAdajcent()[v]].get_nb_unit();

                                if (state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].getAdajcent()[u]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].getAdajcent()[u]].getAdajcent()[v]].get_nb_unit() < unit_to_conquer_3[i]) {
                                    unit_to_conquer_3[i] = 3 + state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].getAdajcent()[u]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_to].getAdajcent()[j]].getAdajcent()[u]].getAdajcent()[v]].get_nb_unit();

                                }

                            }

                    }
            }









        for (int j = 0; j < state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent().size(); j++)
            if (state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].get_gang() != gang) {
                if (state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].get_nb_unit() > unit_max_1_from[i])
                    unit_max_1_from[i] = state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].get_nb_unit();
                // std::cout<<unit_max_1_from[i];}
                
                for (int u = 0; u < state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].getAdajcent().size(); u++)
                    if (state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].getAdajcent()[u]].get_gang() != gang) {
                        if (state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].getAdajcent()[u]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].get_nb_unit() > unit_max_2_from[i])
                            unit_max_2_from[i] = state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].getAdajcent()[u]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].get_nb_unit();
                       
                        for (int v = 0; v < state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].getAdajcent()[u]].getAdajcent().size(); v++)
                            if (state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].getAdajcent()[u]].getAdajcent()[v]].get_gang() != gang) {
                                if (state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].getAdajcent()[u]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].getAdajcent()[u]].getAdajcent()[v]].get_nb_unit() > unit_max_3_from[i])
                                    unit_max_3_from[i] = state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].getAdajcent()[u]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].get_nb_unit() + state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].getAdajcent()[u]].getAdajcent()[v]].get_nb_unit();
                               
                            }

                    }
                if(state.get_list_territory()[state.get_list_territory()[list_attack[i].id_terr_from].getAdajcent()[j]].get_nb_unit()==state.get_list_territory()[list_attack[i].id_terr_to].get_nb_unit()){
            unit_max_1_from[i] =unit_max_1_from[i]-state.get_list_territory()[list_attack[i].id_terr_to].get_nb_unit();
           unit_max_1_from[i] =unit_max_1_from[i]-state.get_list_territory()[list_attack[i].id_terr_to].get_nb_unit();
           unit_max_1_from[i] =unit_max_1_from[i]-state.get_list_territory()[list_attack[i].id_terr_to].get_nb_unit();}
            }
                 
    }
}

void ia::Attack::init(const state::State& state, int gang) {
    list_attack.clear();
    list_score.clear();
    unit_max_1_to.clear();
    unit_max_1_from.clear();
    unit_max_2_to.clear();
    unit_max_2_from.clear();
    unit_max_3_to.clear();
    unit_max_3_from.clear();
    unit_to_conquer_2.clear();
    unit_to_conquer_3.clear();
    engine::Move_unit attack;
    int init = 1;
    std::vector<state::Territory> list_territory = state.getlistterritorygang(gang);
    for (int i = 0; i < list_territory.size(); i++)
        for (int j = 0; j < list_territory[i].getAdajcent().size(); j++) {
            if (state.get_list_territory()[list_territory[i].getAdajcent()[j]].get_gang() != gang)
                if (list_territory[i].get_nb_unit() > 1)
                    if (list_territory[i].get_nb_unit() > state.get_list_territory()[list_territory[i].getAdajcent()[j]].get_nb_unit()) {
                        attack = engine::Move_unit(list_territory[i].getAdajcent()[j], list_territory[i].get_ID(), (-state.get_list_territory()[list_territory[i].getAdajcent()[j]].get_nb_unit()+list_territory[i].get_nb_unit())/2);

                        list_attack.push_back(attack);
                        unit_max_1_to.push_back(init);
                        unit_max_1_from.push_back(init);
                        unit_max_2_to.push_back(init);
                        unit_max_2_from.push_back(init);
                        unit_max_3_to.push_back(init);
                        unit_max_3_from.push_back(init);
                        unit_to_conquer_2.push_back(1000);
                        unit_to_conquer_3.push_back(1000);
                        
                        if (state.get_list_territory()[list_territory[i].getAdajcent()[j]].get_gang() >= 0)
                            init = 100;
                        list_score.push_back(init);

                        init = 1;
                    }

        }

}

void ia::Attack::score_attack(const state::State& state) {
    for (int i = 0; i < list_attack.size(); i++) {
        if (unit_to_conquer_2[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {
            list_score[i] = list_score[i] + 10;
            list_attack[i].nb_unit = unit_to_conquer_2[i];
            if (unit_max_1_from[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {
                list_attack[i].nb_unit = state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit() - unit_max_1_from[i];
                list_score[i] = list_score[i] + 1;
                if (unit_max_1_to[i] + unit_max_1_from[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {

                    list_score[i] = list_score[i] + 1;
                    if (unit_max_2_from[i] + unit_max_1_to[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {
                        list_attack[i].nb_unit = state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit() - unit_max_2_from[i];
                        list_score[i] = list_score[i] + 1;
                        if (unit_max_2_to[i] + unit_max_2_from[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {

                            list_score[i] = list_score[i] + 1;
                            if (unit_max_3_from[i] + unit_max_2_to[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {
                                list_attack[i].nb_unit = state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit() - 1;
                                list_score[i] = list_score[i] + 1;
                                if (unit_max_3_to[i] + unit_max_3_from[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {
                                    list_attack[i].nb_unit = unit_max_3_to[i];

                                    list_score[i] = list_score[i] + 1;
                                }
                            }
                        }
                    }
                }
            }

            if (unit_to_conquer_3[i] + 3 < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {
               if (unit_max_1_from[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {
                list_attack[i].nb_unit = state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit() - unit_max_1_from[i];
                list_score[i] = list_score[i] + 1;
                if (unit_max_1_to[i] + unit_max_1_from[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {

                    list_score[i] = list_score[i] + 1;
                    if (unit_max_2_from[i] + unit_max_1_to[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {
                        list_attack[i].nb_unit = state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit() - unit_max_2_from[i];
                        list_score[i] = list_score[i] + 1;
                        if (unit_max_2_to[i] + unit_max_2_from[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {

                            list_score[i] = list_score[i] + 1;
                            if (unit_max_3_from[i] + unit_max_2_to[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {
                                list_attack[i].nb_unit = state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit() - 1;
                                list_score[i] = list_score[i] + 1;
                                if (unit_max_3_to[i] + unit_max_3_from[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {
                                    list_attack[i].nb_unit = unit_max_3_to[i];

                                    list_score[i] = list_score[i] + 1;
                                }
                            }
                        }
                    }
                }
            }
            }


        } else {
            if (unit_max_1_from[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {
                list_attack[i].nb_unit = state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit() - unit_max_1_from[i];
                list_score[i] = list_score[i] + 1;
                if (unit_max_1_to[i] + unit_max_1_from[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {

                    list_score[i] = list_score[i] + 1;
                    if (unit_max_2_from[i] + unit_max_1_to[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {
                        list_attack[i].nb_unit = state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit() - unit_max_2_from[i];
                        list_score[i] = list_score[i] + 1;
                        if (unit_max_2_to[i] + unit_max_2_from[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {

                            list_score[i] = list_score[i] + 1;
                            if (unit_max_3_from[i] + unit_max_2_to[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {
                                list_attack[i].nb_unit = state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit() - 1;
                                list_score[i] = list_score[i] + 1;
                                if (unit_max_3_to[i] + unit_max_3_from[i] < state.get_list_territory()[list_attack[i].id_terr_from].get_nb_unit()) {
                                    list_attack[i].nb_unit = unit_max_3_to[i];

                                    list_score[i] = list_score[i] + 1;
                                }
                            }
                        }
                    }
                }
            }



        }
         if (state.get_list_territory()[list_attack[i].id_terr_to].get_nb_unit() > list_attack[i].nb_unit) 
        {
           list_attack[i].nb_unit =state.get_list_territory()[list_attack[i].id_terr_to].get_nb_unit()+1; 
        }             
    }
   
}