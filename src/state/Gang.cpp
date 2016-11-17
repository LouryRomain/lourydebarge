

#include "Gang.h"

state::Gang::Gang() {
    money=new int;
    *money =0;
    action_done=new int;
    *action_done=0;
    turn=new int;
    *turn=0;

}

state::Gang::~Gang() {

}

void state::Gang::set_nb_card_gang(int nb_card_gang) {
    this->nb_card_gang = nb_card_gang;
}

int state::Gang::get_nb_card_gang() {
    return nb_card_gang;
}

void state::Gang::set_money(int money) {
    if (money >= 0)
        delete this->money;
    this->money=new int;
    *this->money=money;
}

int state::Gang::get_money() {
    return *money;
}

void state::Gang::set_alive(bool alive) {
    this->alive = alive;
}

bool state::Gang::get_alive() {
    return alive;
}

std::string state::Gang::get_name() {
    return name;
}

void state::Gang::set_name(std::string name) {
    this->name = name;
}

void state::Gang::setListTerritory(std::vector<int> list_territory) {
    this->list_territory = list_territory;
}

std::vector<int> state::Gang::getListTerritory() {
    return list_territory;
}

void state::Gang::setAction_done(int nb){
    delete this->action_done;
    this->action_done=new int;
    *action_done=nb;
}

void state::Gang::setTurn(int turn){
    delete this->turn;
    this->turn=new int;
    *this->turn=turn;
}


int state::Gang::getAction_done(){
    return *action_done;
}

int state::Gang::getTurn(){
    return *turn;
}