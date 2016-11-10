#include "Player.h"
#include "Element.h"

state::Player::Player() {
    view_posX = new int;
    view_posY = new int;
    *view_posY=0;
    *view_posX=0;
    compteur = new int;
    tour_cliked = new state::Element;
    state::Element tour(0, 0, 0, 0);
    *tour_cliked = tour;
    chiffre_pris = new int;
    *chiffre_pris = 0;

}

state::Player::~Player() {

}

void state::Player::Update() {

}

void state::Player::setCompteur(int compteur) {
    if ((compteur < 100)&&(compteur >= 0)) {
        delete this->compteur;
        this->compteur = new int;
        *(this->compteur) = compteur;
    }
}

int state::Player::getCompteur() {
    return *compteur;
}

int state::Player::get_chiffre_pris() {
    return *chiffre_pris;
}

void state::Player::set_chiffre_pris(int chiffre_pris) {
    delete this->chiffre_pris;
    this->chiffre_pris = new int;
    *this->chiffre_pris = chiffre_pris;
}