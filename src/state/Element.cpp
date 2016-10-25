/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <state/Element.h>
#include <iostream>

state::Element::Element (){
    
}

state::Element::Element (std::string path,sf::Vector2f pos,sf::Vector2f scale){
    this->path=path;
    this->pos=pos;
    this->scale=scale;
}
state::Element::Element (std::string path, sf::Vector2f pos, sf::Vector2f scale,sf::Vector2i anim,sf::Vector2i dim,int type){
    this->path=path;
    this->pos=pos;
    this->scale=scale;
    this->dim=dim;
    this->anim=new sf::Vector2i;
    *(this->anim)=anim;
    this->type=type;
}

state::Element::~Element (){
    
}

void state::Element::init(){
    
    sprite=texture.load_texture(path,pos,scale);
}
    
 sf::Vector2i state::Element::getAnim (){
     return *anim;
 }
 
 void state::Element::setAnim (sf::Vector2i anim){
     delete this->anim;
     this->anim=new sf::Vector2i;
     *(this->anim)=anim;}
     
     
void state::Element::setDim(sf::Vector2i dim){
    this->dim=dim;
}
sf::Vector2i state::Element::getDim(){
    return dim;
}
int state::Element::getType (){
    return type;
}

void state::Element::setType (int type){
    this->type=type;
}
    
 