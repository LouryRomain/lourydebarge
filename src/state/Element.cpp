/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <state/Element.h>

state::Element::Element (){
    
}

state::Element::Element (std::string path,sf::Vector2f pos,sf::Vector2f scale){
    this->path=path;
    this->pos=pos;
    this->scale=scale;
}
state::Element::~Element (){
    
}
void state::Element::init(){
    sprite=texture.load_texture(path,pos,scale);
}
    
