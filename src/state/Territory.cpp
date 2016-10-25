/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Territory.h"

namespace state {

  
    Territory::Territory (){
        cliked=0;
    }
    
    Territory::~Territory (){
        
    }
    
    int Territory::get_nb_unit (){
        return nb_unit;
        
    }
    
    void Territory::set_nb_unit (int nb_unit){
        this->nb_unit = nb_unit;
    }
    
    std::string Territory::get_gang (){
        return gang;
    }
    
    void Territory::set_gang (std::string gang){
        this->gang = gang;
    }
    int Territory::get_ID (){
        return ID;
    }
    
    void Territory::set_ID (int ID){
        this->ID = ID;
    }
    bool Territory::get_QG (){
        return QG;
    }
    
    void Territory::set_QG (bool boolean_QG){
        this->QG = QG;
    }
    
  };