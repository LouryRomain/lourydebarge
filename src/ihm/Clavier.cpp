#include <SFML/Graphics.hpp>
#include <ihm/Clavier.h>

#include <iostream>
#include <state/State.h>


int new_state;
int old_state = 0;
int speed = 40;
int posX;
int posY;

ihm::Clavier::Clavier() {

}

ihm::Clavier::~Clavier() {

}

void ihm::Clavier::gestion_clavier(const state::State& state,sf::Keyboard::Key key,ihm::Player player) {



    if (sf::Keyboard::B==key){
 
        if (player.get_state() == 1)
            player.set_state(0);
        else player.set_state(1);
        player.setCompteur(0);}
   
    

    else if (sf::Keyboard::Up==key) {
        posY = *(player.view_posY);
        delete player.view_posY;
        player.view_posY = new int;
        *(player.view_posY) = posY - speed;
    }
    else if ((sf::Keyboard::Down)==key) {
        posY = *(player.view_posY);
        delete player.view_posY;
        player.view_posY = new int;
        *(player.view_posY) = posY + speed;
    }
    else if (sf::Keyboard::Left==key) {
        posX = *(player.view_posX);
        delete player.view_posX;
        player.view_posX = new int;
        *(player.view_posX) = posX - speed;
    }
    else if (sf::Keyboard::Right==key) {
        posX = *(player.view_posX);
        delete player.view_posX;
        player.view_posX = new int;
        *(player.view_posX) = posX + speed;
    }
}

