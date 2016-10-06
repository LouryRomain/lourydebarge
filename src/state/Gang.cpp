/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Gang.h"

namespace state {

    Gang::Gang (){
    }
    
   
    Gang::~Gang (){
    }
    
    
    void Gang::set_nb_card_gang (int nb_card_gang){
        this->nb_card_gang = nb_card_gang;
    }
    
    
    int Gang::get_nb_card_gang (){
        return nb_card_gang;
    }
    
    
    
    void Gang::set_money (int money){
        this->money = money;
    }
    
    
    int Gang::get_money (){
        return money;
    }
    
    
    void Gang::set_alive (bool alive){
        this->alive = alive;
    }
    
    bool Gang::get_alive (){
        return alive;
    }
    
    
    void Gang::set_nb_unit (int nb_unit){
        this->nb_unit = nb_unit;
    }
    
    
    int Gang::get_nb_unit (){
        return nb_unit;
    }
    
    std::string Gang::get_name (){
        return name;
    }
    
    void Gang::set_name (std::string name){
        this->name = name;
    }
    
  };




