

#include <state/Element.h>
#include <iostream>


 state::Element::Element (){
     
 }
 state::Element::~Element (){
     
 }
 state::Element::Element (int posX, int posY, int type){
     this->posX=new int;
     *(this->posX)=posX;
     this->posY=new int;
     *(this->posY)=posY;
     this->type=type;
     this->statut=new int;
     *statut=0;
 }
 int state::Element::getType (){
     return this->type;
 }
 void state::Element::setType (int type){
     this->type=type;
 }
 int state::Element::getPosX (){
     return *posX;
 }
 int state::Element::getPosY (){
     return *posY;
 }
 void state::Element::setPosX (int posX, int posY){
     delete this->posX;
     delete this->posY;
     this->posX=new int;
     *(this->posX)=posX;
     this->posY=new int;
     *(this->posY)=posY;
 }
state::Element::Element(int posX, int posY, int type, int statut){
    this->posX=new int;
     *(this->posX)=posX;
     this->posY=new int;
     *(this->posY)=posY;
     this->type=type;
     this->statut=new int;
     *this->statut=statut;
     territory=0;
    
}

bool state::Element::isClickable(){
    if ((type==13)||(type==14)||(type==15)||(type==22)||(type==23)||(type==24))
        return 1;
    else
        return 0;
}

bool state::Element::isChiffre(){
    if ((type==5)||(type==6)||(type==7)||(type=8)||(type==19)||(type==20)||(type=21))
        return 1;
    else
        return 0;
}

state::Element::Element(int posX, int posY, int type, int statut,int territory){
    this->posX=new int;
     *(this->posX)=posX;
     this->posY=new int;
     *(this->posY)=posY;
     this->type=type;
     this->statut=new int;
     *this->statut=statut;
     this->territory=territory;
    
}

int state::Element::getStatut(){
    return *statut;
}

void state::Element::setStatut(int statut){
   
    delete this->statut;
    this->statut=new int; 
    *(this->statut)=statut;
}