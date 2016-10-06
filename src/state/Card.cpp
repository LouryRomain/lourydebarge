/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Card.h"

namespace state {

    Card::Card (){
    }
    
    Card::~Card (){
    }
    
    char Card::get_type (){
        return type;
    }
    
    void Card::set_type (char type){
        this->type = type;
    }
    
    int Card::get_nb_card_owned (){
        return nb_card_owned;
    }
    
    
    void Card::set_nb_card_owned (int nb_card_owned){
        this->nb_card_owned = nb_card_owned;
    }
    
    void Card::set_effect (int effect){
        this->effect = effect;
    }
    
    int Card::get_effect (){
        return effect;
    }
  };


