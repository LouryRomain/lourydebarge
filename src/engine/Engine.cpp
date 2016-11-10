#include "Engine.h"
#include "state/State.h"
#include "Move_unit.h"
#include <iostream>

int clock_compteur;
int clock_ok;


engine::Engine::Engine (){
     
 }
engine::Engine::~Engine (){
    
}
void engine::Engine::Update (state::State& state){
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
                        if (state.getState() == 1)
                            state.player.gang.set_money(money - state.player.getCompteur()*10);
                        if (state.getState() == 2) {
                            if (state.player.get_chiffre_pris() == 0) {
                                if (state.list_territory[state.player.tour_cliked->territory].get_nb_unit() - state.player.getCompteur() >= 0) {
                      
                                    action.id_terr_from=state.list_territory[state.player.tour_cliked->territory].get_ID();
                                    
                                   
                                    state.player.set_chiffre_pris(state.player.getCompteur());
                                }
                            } else {action.nb_unit=state.player.get_chiffre_pris();
                                action.id_terr_to=state.list_territory[state.player.tour_cliked->territory].get_ID();
                           
                            action.make(state);
                              
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
                   // if(state.player.get_chiffre_pris()==0){
                    //if(state.list_territory[state.getListListElement()[i].getlist()[j].territory].get_gang()==2)
                    if (state.getListListElement()[i].getlist()[j].getPosX() != state.player.tour_cliked->getPosX()) {
                        delete state.player.tour_cliked;
                        state.player.tour_cliked = new state::Element;
                        *(state.player.tour_cliked) = state.getListListElement()[i].getlist()[j];
                        state.player.setCompteur(0);
                    }}
                    else {/*for(int v=0;v<state.list_territory[state.getListListElement()[i].getlist()[j].territory].getAdajcent().size();v++)
                        if (state.list_territory[state.getListListElement()[i].getlist()[j].territory].getAdajcent()[v]==state.getListListElement()[i].getlist()[j].territory){
                            
                            delete state.player.tour_cliked;
                        state.player.tour_cliked = new state::Element;
                        *(state.player.tour_cliked) = state.getListListElement()[i].getlist()[j];
                        state.player.setCompteur(0);}
                        
                    }*/
                    
                    }



        }
    }
    if (state.getState() != 1)
        if (state.player.tour_cliked->getStatut() == 1) {

            if (state.getState()!= 2)
                state.player.setCompteur(0);
            state.setState(2);
        } else

            state.setState(0);
}
