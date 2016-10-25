#include "Player.h"

state::Player::Player (){
    pos=new sf::Vector2f;
    *(pos)=sf::Vector2f(0,0);
}
state::Player::~Player (){
        
    }
sf::Vector2f state::Player::getPos (){
    return *(pos);
}
void state::Player::setPos (sf::Vector2f pos){
    delete this->pos;
    this->pos=new sf::Vector2f;
    *(this->pos)=pos;
}
