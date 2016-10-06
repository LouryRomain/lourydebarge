/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Adjacent.h"
#include "Territory.h"

namespace state{


Adjacent::Adjacent (Territory* territory_1, Territory* territory_2):territory_1(territory_1),territory_2(territory_2){
    
}
Adjacent::~Adjacent (){
    if (territory_1) delete territory_1;
     if (territory_2) delete territory_2;
    
}


Territory* Adjacent::get_territory_1 (){
    return territory_1;
}

Territory* Adjacent::get_territory_2 (){
    return territory_2;
}

void Adjacent::set_territory_1 (Territory* territory_1){
  this->territory_1=territory_1;
}

void Adjacent::set_territory_2 (Territory* territory_2){
    this->territory_2=territory_2;
}
};