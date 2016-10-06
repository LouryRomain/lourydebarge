/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "State.h"

namespace state {

    State::State (){
    }
    
    State::~State (){
    }
    
    int State::get_nb_territory (){
       return nb_territory; 
    }
    void State::set_nb_territory (int nb_territory){
        this->nb_territory = nb_territory;
        
    }
    int State::get_nb_gang (){
        return nb_gang;
    }
    
    void State::set_nb_gang (int nb_gang){
        this->nb_gang = nb_gang;
    }
  };
