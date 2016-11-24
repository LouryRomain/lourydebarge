#include "Engine.h"
#include "state/State.h"
#include "Move_unit.h"
#include <iostream>

int clock_compteur;
int clock_ok;
int pause = 0;
int count = 0;

engine::Engine::Engine() {

}

engine::Engine::~Engine() {

}

void engine::Engine::Update(state::State& state,ihm::Player player) {
    clock_ok++;
    clock_compteur++;
    engine::Move_unit action;
   
    for (int i = 0; i < state.getListListElement().size(); i++) {
        for (int j = 0; j < state.getListListElement()[i].getlist().size(); j++) {
            int mem;
            mem = player.getCompteur();
            int money;


            money = player.gang.get_money();
            if ((state.getListListElement()[i].getlist()[j].isClickable())&&(state.getListListElement()[i].getlist()[j].getStatut() == 1)) {

                if (state.getListListElement()[i].getlist()[j].getType() == 14) {
                    if (clock_ok > 10) {
                        if(player.get_state()==1)
                            if(((mem+1)*10<=player.gang.get_money()))
                        player.setCompteur(mem + 1);
                        if(player.get_state()==2)
                            if((mem+1<state.get_list_territory()[player.tour_cliked->territory].get_nb_unit()&&(player.get_chiffre_pris()==0)))
                                 player.setCompteur(mem + 1);   
                        clock_ok = 0;
                    }
                }
                if (state.getListListElement()[i].getlist()[j].getType() == 15) {
                    if (clock_ok > 10) {
                        player.setCompteur(mem - 1);
                        clock_ok = 0;
                    }
                }
                if (state.getListListElement()[i].getlist()[j].getType() == 13) {
                    if (clock_compteur > 20) {
                        if (player.get_state() == 1){
                            
                            for (int u=0;u<state.get_list_territory().size();u++)
                            {
                                
                                if((state.get_list_territory()[u].get_QG()==1)&&(state.get_list_territory()[u].get_gang()==player.gang.ID)){
                                    player.gang.set_money(money - player.getCompteur()*10);
                                    player.set_state(0);
                                    delete player.view_posX;
                                    delete player.view_posY;
                                    player.view_posX=new int;
                                    player.view_posY=new int;
                                    *player.view_posX=0;
                                    *player.view_posY=0;
                                    
                                    state.get_list_territory()[u].set_nb_unit( state.get_list_territory()[u].get_nb_unit()+player.getCompteur());
                                }}
                        }
                        if (player.get_state() == 2) {
                            if (player.get_chiffre_pris() == 0) {
                                if (state.get_list_territory()[player.tour_cliked->territory].get_nb_unit() - player.getCompteur() >= 0) {

                                    delete player.tour_unit_pris;
                                    player.tour_unit_pris = new int;
                                    *(player.tour_unit_pris) = player.tour_cliked->territory;


                                    player.set_chiffre_pris(player.getCompteur());
                                }
                            } else {
                                action.nb_unit = player.get_chiffre_pris();
                                action.id_terr_to = player.tour_cliked->territory;
                                action.id_terr_from = *player.tour_unit_pris;
                                 
                                
                                action.make(state,list_action);
                                //std::cout<<"avant "<<state.get_list_territory()[action.id_terr_from].get_nb_unit()<<std::endl;
                                //action.demake(state);
                                //std::cout<<"apres "<<state.get_list_territory()[action.id_terr_from].get_nb_unit()<<std::endl;
                                state.getListGang()[0].setAction_done(state.getListGang()[0].getAction_done() + 1);

                                player.set_chiffre_pris(0);
                            }


                        }
                        player.setCompteur(0);

                        clock_compteur = 0;
                    }

                }
                if (state.getListListElement()[i].getlist()[j].getType() == 22) {
                    if (clock_compteur > 20) {
                        player.gang.set_money(money - 100);
                        clock_compteur = 0;
                    }

                }
                if (state.getListListElement()[i].getlist()[j].getType() == 23) {
                    if (clock_compteur > 20) {
                        player.gang.set_money(money - 300);
                        clock_compteur = 0;
                    }

                }
                if (state.getListListElement()[i].getlist()[j].getType() == 24) {
                    if (clock_compteur > 20) {
                        player.gang.set_money(money - 700);
                        clock_compteur = 0;
                    }

                }



            }

            if (state.getListListElement()[i].getlist()[j].getType() == 16)
                if (state.getListListElement()[i].getlist()[j].getStatut() == 1) {
                    if (player.get_chiffre_pris() == 0) {
                        //std::cout<<state.player.tour_cliked->territory<<std::endl;
                        //std::cout<<(state.get_list_territory()[state.getListListElement()[i].getlist()[j].territory].get_gang() == state.player.gang.ID)<<std::endl;
                        if (state.get_list_territory()[state.getListListElement()[i].getlist()[j].territory].get_gang() == player.gang.ID)
                            if (state.getListListElement()[i].getlist()[j].getPosX() != player.tour_cliked->getPosX()) {

                                delete player.tour_cliked;
                                player.tour_cliked = new state::Element;
                                *(player.tour_cliked) = state.getListListElement()[i].getlist()[j];
                                //std::cout<<state.player.tour_cliked->territory<<std::endl;

                                player.setCompteur(0);
                            }
                    } else {
                        for (int v = 0; v < state.get_list_territory()[*(player.tour_unit_pris)].getAdajcent().size(); v++) {
                            // std::cout<<*(state.player.tour_unit_pris)<<std::endl;
                            if (state.get_list_territory()[*(player.tour_unit_pris)].getAdajcent()[v] == state.getListListElement()[i].getlist()[j].territory) {

                                delete player.tour_cliked;
                                player.tour_cliked = new state::Element;
                                *(player.tour_cliked) = state.getListListElement()[i].getlist()[j];

                                player.setCompteur(0);
                            }
                        }


                    }
                }



        }
    }
    if (player.get_state() != 1)
        if (player.tour_cliked->getStatut() == 1) {

            if (player.get_state() != 2)
                player.setCompteur(0);
            player.set_state(2);
        } else

            player.set_state(0);

    for (int i = 0; i < state.get_list_territory().size(); i++) {
        if (state.get_list_territory()[i].get_nb_unit() == 0)
            state.get_list_territory()[i].set_gang(-1);

    }

    if (pause == 1)
        count++;

    //gestion des tours de jeu
    if (state.getListGang()[round % state.getListGang().size()].getAction_done() == 3) {
        state.getListGang()[round % state.getListGang().size()].setTurn(0);
        state.getListGang()[round % state.getListGang().size()].setAction_done(0);
        round++;
        pause = 1;
        player.set_state(0);
    }
    
/*//Achat des unités
    if(index_QG!=-1)
    for (int t=0;t<state.getListGang().size();t++)
    if(state.getListGang()[t].ID==gang){
        
        if(state.getListGang()[t].get_money()>10){
            state.get_list_territory()[index_QG].set_nb_unit(state.get_list_territory()[index_QG].get_nb_unit()+static_cast<int>(state.getListGang()[t].get_money()/10));
            state.getListGang()[t].set_money(state.getListGang()[t].get_money()-static_cast<int>(state.getListGang()[t].get_money()/10)*10);
        }
        
    }*/
if(state.getListGang()[1].get_money()>10){
            state.get_list_territory()[22].set_nb_unit(state.get_list_territory()[22].get_nb_unit()+static_cast<int>(state.getListGang()[1].get_money()/10));
            state.getListGang()[1].set_money(state.getListGang()[1].get_money()-static_cast<int>(state.getListGang()[1].get_money()/10)*10);
        }
    if (count > 30) {
        state.getListGang()[round % state.getListGang().size()].set_money(state.getListGang()[round % state.getListGang().size()].get_money()+state.getlistterritorygang(state.getListGang()[round % state.getListGang().size()].ID).size()*15);
        std::cout<<state.getListGang()[round % state.getListGang().size()].get_money()<<std::endl;
        state.getListGang()[round % state.getListGang().size()].setTurn(1);
        count = 0;
        pause = 0;  
    }


  


}

