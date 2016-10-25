#include "Souris.h"
#include <iostream>


int new_state1;
int old_state1=0;

 control::Souris::Souris (){
     Update=new int;
     mouseX=new int;
     mouseY=new int;
     left=new int;
     frontDesc=new int;
     
 }
 control::Souris::~Souris (){
     
 }
 void control::Souris::gestion_souris (sf::RenderWindow& window){
     if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
     {new_state1=1;
     delete mouseX;
     mouseX=new int;
     *(mouseX)=sf::Mouse::getPosition(window).x;
     delete mouseY;
     mouseY=new int;
     *(mouseY)=sf::Mouse::getPosition(window).y;
     delete left;
     left=new int;
     *(left)=1;
     delete Update;
         Update=new int;
         *(Update)=1;}
    else
    {new_state1=0;
    delete left;
     left=new int;
     *(left)=0;
     delete Update;
         Update=new int;
         *(Update)=1;
    }
       
       if((old_state1==0)&&(new_state1==1))
       {//for(int i=0;i<list.getSize();i++){
          // if(list.getlist()[i].getType()==button_ok_type)
           //std::cout << "Mouse.x" << *(mouseX) << "Mouse.y" << *(mouseY) << std::endl;
        
         old_state1=1;
         delete Update;
         Update=new int;
         *(Update)=1;
       }
       if((old_state1==1)&&(new_state1==0)){
          delete frontDesc;
         frontDesc=new int;
         *(frontDesc)=1;
        old_state1=0;
        
        delete Update;
         Update=new int;
         *(Update)=1;
         
       }else{delete frontDesc;
         frontDesc=new int;
         *(frontDesc)=0;}
          
 }
