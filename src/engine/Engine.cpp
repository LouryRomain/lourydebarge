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

void engine::Engine::Update(state::State& state) {
    clock_ok++;
    clock_compteur++;
   
    for (int i = 0; i < state.getListListElement().size(); i++) {
        for (int j = 0; j < state.getListListElement()[i].getlist().size(); j++) {
            int mem;
            mem = state.player.getCompteur();
            int money;


            money = state.player.gang.get_money();
            if ((state.getListListElement()[i].getlist()[j].isClickable())&&(state.getListListElement()[i].getlist()[j].getStatut() == 1)) {

                if (state.getListListElement()[i].getlist()[j].getType() == 14) {
                    if (clock_ok > 10) {
                        if(state.getState()==1)
                            if(((mem+1)*10<=state.player.gang.get_money()))
                        state.player.setCompteur(mem + 1);
                        if(state.getState()==2)
                            if((mem+1<state.list_territory[state.player.tour_cliked->territory].get_nb_unit()&&(state.player.get_chiffre_pris()==0)))
                                 state.player.setCompteur(mem + 1);   
                        clock_ok = 0;
                    }
                }
                if (state.getListListElement()[i].getlist()[j].getType() == 15) {
                    if (clock_ok > 10) {
                        state.player.setCompteur(mem - 1);
                        clock_ok = 0;
                    }
                }
                if (state.getListListElement()[i].getlist()[j].getType() == 13) {
                    if (clock_compteur > 20) {
                        if (state.getState() == 1){
                            
                            for (int u=0;u<state.list_territory.size();u++)
                            {
                                
                                if((state.list_territory[u].get_QG()==1)&&(state.list_territory[u].get_gang()==state.player.gang.ID)){
                                    state.player.gang.set_money(money - state.player.getCompteur()*10);
                                    state.setState(0);
                                    delete state.player.view_posX;
                                    delete state.player.view_posY;
                                    state.player.view_posX=new int;
                                    state.player.view_posY=new int;
                                    *state.player.view_posX=0;
                                    *state.player.view_posY=0;
                                    
                                    state.list_territory[u].set_nb_unit( state.list_territory[u].get_nb_unit()+state.player.getCompteur());
                                }}
                        }
                        if (state.getState() == 2) {
                            if (state.player.get_chiffre_pris() == 0) {
                                if (state.list_territory[state.player.tour_cliked->territory].get_nb_unit() - state.player.getCompteur() >= 0) {

                                    delete state.player.tour_unit_pris;
                                    state.player.tour_unit_pris = new int;
                                    *(state.player.tour_unit_pris) = state.player.tour_cliked->territory;


                                    state.player.set_chiffre_pris(state.player.getCompteur());
                                }
                            } else {
                                action.nb_unit = state.player.get_chiffre_pris();
                                action.id_terr_to = state.player.tour_cliked->territory;
                                action.id_terr_from = *state.player.tour_unit_pris;
                                 
                                
                                action.make(state);


                                state.getListGang()[0].setAction_done(state.getListGang()[0].getAction_done() + 1);

                                state.player.set_chiffre_pris(0);
                            }


                        }
                        state.player.setCompteur(0);

                        clock_compteur = 0;
                    }

                }
                if (state.getListListElement()[i].getlist()[j].getType() == 22) {
                    if (clock_compteur > 20) {
                        state.player.gang.set_money(money - 100);
                        clock_compteur = 0;
                    }

                }
                if (state.getListListElement()[i].getlist()[j].getType() == 23) {
                    if (clock_compteur > 20) {
                        state.player.gang.set_money(money - 300);
                        clock_compteur = 0;
                    }

                }
                if (state.getListListElement()[i].getlist()[j].getType() == 24) {
                    if (clock_compteur > 20) {
                        state.player.gang.set_money(money - 700);
                        clock_compteur = 0;
                    }

                }



            }

            if (state.getListListElement()[i].getlist()[j].getType() == 16)
                if (state.getListListElement()[i].getlist()[j].getStatut() == 1) {
                    if (state.player.get_chiffre_pris() == 0) {
                        //std::cout<<state.player.tour_cliked->territory<<std::endl;
                        //std::cout<<(state.list_territory[state.getListListElement()[i].getlist()[j].territory].get_gang() == state.player.gang.ID)<<std::endl;
                        if (state.list_territory[state.getListListElement()[i].getlist()[j].territory].get_gang() == state.player.gang.ID)
                            if (state.getListListElement()[i].getlist()[j].getPosX() != state.player.tour_cliked->getPosX()) {

                                delete state.player.tour_cliked;
                                state.player.tour_cliked = new state::Element;
                                *(state.player.tour_cliked) = state.getListListElement()[i].getlist()[j];
                                //std::cout<<state.player.tour_cliked->territory<<std::endl;

                                state.player.setCompteur(0);
                            }
                    } else {
                        for (int v = 0; v < state.list_territory[*(state.player.tour_unit_pris)].getAdajcent().size(); v++) {
                            // std::cout<<*(state.player.tour_unit_pris)<<std::endl;
                            if (state.list_territory[*(state.player.tour_unit_pris)].getAdajcent()[v] == state.getListListElement()[i].getlist()[j].territory) {

                                delete state.player.tour_cliked;
                                state.player.tour_cliked = new state::Element;
                                *(state.player.tour_cliked) = state.getListListElement()[i].getlist()[j];

                                state.player.setCompteur(0);
                            }
                        }


                    }
                }



        }
    }
    if (state.getState() != 1)
        if (state.player.tour_cliked->getStatut() == 1) {

            if (state.getState() != 2)
                state.player.setCompteur(0);
            state.setState(2);
        } else

            state.setState(0);

    for (int i = 0; i < state.list_territory.size(); i++) {
        if (state.list_territory[i].get_nb_unit() == 0)
            state.list_territory[i].set_gang(-1);

    }

    if (pause == 1)
        count++;

    //gestion des tours de jeu
    if (state.getListGang()[round % state.getListGang().size()].getAction_done() == 3) {
        state.getListGang()[round % state.getListGang().size()].setTurn(0);
        state.getListGang()[round % state.getListGang().size()].setAction_done(0);
        round++;
        pause = 1;
        state.setState(0);
    }


    if (count > 30) {
        state.getListGang()[round % state.getListGang().size()].set_money(state.getListGang()[round % state.getListGang().size()].get_money()+state.getlistterritorygang(state.getListGang()[round % state.getListGang().size()].ID).size()*15);
        std::cout<<state.getListGang()[round % state.getListGang().size()].get_money()<<std::endl;
        state.getListGang()[round % state.getListGang().size()].setTurn(1);
        count = 0;
        pause = 0;  
    }
    //std::cout<<round%state.getListGang().size()<<std::endl;

    //std::cout<<*(state.player.tour_unit_pris)<<std::endl;




}

