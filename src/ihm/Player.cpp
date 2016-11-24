#include "Player.h"
#include "state/State.h"


ihm::Player::Player() {
    view_posX = new int;
    view_posY = new int;
    *view_posY=0;
    *view_posX=0;
    compteur = new int;
    *compteur=0;
    tour_cliked = new state::Element;
    state::Element tour(0, 0, 0, 0);
    *tour_cliked = tour;
    chiffre_pris = new int;
    *chiffre_pris = 0;
    tour_unit_pris=new int;
    *tour_unit_pris=-1;
    gang.ID=2;
    gang.setTurn(1);
    state=new int;
    *state=0;
    

}

ihm::Player::~Player() {

    
    
}

void ihm::Player::Update(const state::State& state) {
gang.getListTerritory().clear();
std::vector<int> list;
    int index_QG=-1;
    for (int i = 0; i < state.get_list_territory().size(); i++)
        if (state.get_list_territory()[i].get_gang() == gang.ID){
            list.push_back(state.get_list_territory()[i].get_ID());
            if (state.get_list_territory()[i].get_QG()==1)
                index_QG=i;
        }
     gang.setListTerritory(list);
}

void ihm::Player::setCompteur(int compteur) {
    if ((compteur < 100)&&(compteur >= 0)) {
        delete this->compteur;
        this->compteur = new int;
        *(this->compteur) = compteur;
    }
}

int ihm::Player::getCompteur() {
    return *compteur;
}

int ihm::Player::get_chiffre_pris() {
    return *chiffre_pris;
}

void ihm::Player::set_chiffre_pris(int chiffre_pris) {
    delete this->chiffre_pris;
    this->chiffre_pris = new int;
    *this->chiffre_pris = chiffre_pris;
}

int ihm::Player::get_state() const{
    return *state;
}

void ihm::Player::set_state(int state){
    delete this->state;
    this->state=new int;
    *this->state=state;
}