#include <SFML/Graphics.hpp>
#include <engine/Clavier.h>

#include <iostream>
#include <state/State.h>


int new_state;
int old_state = 0;
int speed = 40;
int posX;
int posY;

engine::Clavier::Clavier() {

}

engine::Clavier::~Clavier() {

}

void engine::Clavier::gestion_clavier(state::State& state,sf::Keyboard::Key key) {



    if (sf::Keyboard::B==key){
 
        if (state.getState() == 1)
            state.setState(0);
        else state.setState(1);
        state.player.setCompteur(0);}
   
    

    else if (sf::Keyboard::Up==key) {
        posY = *(state.player.view_posY);
        delete state.player.view_posY;
        state.player.view_posY = new int;
        *(state.player.view_posY) = posY - speed;
    }
    else if ((sf::Keyboard::Down)==key) {
        posY = *(state.player.view_posY);
        delete state.player.view_posY;
        state.player.view_posY = new int;
        *(state.player.view_posY) = posY + speed;
    }
    else if (sf::Keyboard::Left==key) {
        posX = *(state.player.view_posX);
        delete state.player.view_posX;
        state.player.view_posX = new int;
        *(state.player.view_posX) = posX - speed;
    }
    else if (sf::Keyboard::Right==key) {
        posX = *(state.player.view_posX);
        delete state.player.view_posX;
        state.player.view_posX = new int;
        *(state.player.view_posX) = posX + speed;
    }
}

