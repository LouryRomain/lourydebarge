#include "Souris.h"
#include "state/Player.h"
#include <iostream>



int new_state1;
int old_state1=0;

 control::Souris::Souris (){
     posY=new int;
     posX=new int;
    
     
 }
 control::Souris::~Souris (){
     
 }
 
 void control::Souris::Update(sf::RenderWindow& window){
     sf::Vector2i pixelPos=sf::Mouse::getPosition(window);
    
     //sf::Vector2f worldPos =window.mapPixelToCoords(pixelPos,view);
     delete posX;
     delete posY;
     posX=new int;
     posY=new int;
     *posX=pixelPos.x;
     *posY=pixelPos.y;
     
     }
 state::ListElement control::Souris::gestion_souris (state::ListElement list_element,state::Player player,int mode){
     
     if(mode==0)
         if (list_element.getIdView()==4)
         for(int i=0;i<list_element.getSize();i++)
             if((list_element.getlist()[i].isChiffre())&&(list_element.getlist()[i].getStatut()==3)){
                 list_element.getlist()[i].setPosX(*posX+*player.view_posX,*posY+*player.view_posY);
                 
                 
         }
             
             
     if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
     {new_state1=1;
     
     }
    else
    {new_state1=0;
    if((mode==1)||(mode==2))
    for(int i=0;i<list_element.getSize();i++){
        if(list_element.getlist()[i].isClickable()){
    
               list_element.getlist()[i].setStatut(0);}}
    
    }
       for(int i=0;i<list_element.getSize();i++){
       if((old_state1==0)&&(new_state1==1))
       {int dimX;
               int dimY;
               float scale;
               if((mode==1)||(mode==2))
           if(list_element.getlist()[i].isClickable()){
               
               if((list_element.getlist()[i].getType()==13)||(list_element.getlist()[i].getType()==22)||(list_element.getlist()[i].getType()==23)||(list_element.getlist()[i].getType()==24)){
                   dimX=64;
                   dimY=22;
                   scale=1.5f;
               }
               if((list_element.getlist()[i].getType()==14)||(list_element.getlist()[i].getType()==15)){
                   dimX=25;
                   dimY=25;
                   scale=2;
                    
               }
               
               
              
               
               if((*posX>list_element.getlist()[i].getPosX()) && (*posX<list_element.getlist()[i].getPosX()+scale*dimX) && (*posY>list_element.getlist()[i].getPosY()) && (*posY<list_element.getlist()[i].getPosY()+scale*dimY)){
                list_element.getlist()[i].setStatut(1);
                
               
               }else {
               list_element.getlist()[i].setStatut(0);}
               
           }
               if((mode==0)||(mode==2))
                if(list_element.getlist()[i].getType()==16)
               {
                   dimX=68;
                   dimY=68;
                   scale=2;
                   
                   
                   
               if((*posX>list_element.getlist()[i].getPosX()-*(player.view_posX)) && (*posX<list_element.getlist()[i].getPosX()+scale*dimX-*(player.view_posX)) && (*posY>list_element.getlist()[i].getPosY()-*(player.view_posY)) && (*posY<list_element.getlist()[i].getPosY()+scale*dimY-*(player.view_posY))){
                   if(mode==2)
                       if(*posX<300){
                           
                       }else
                   list_element.getlist()[i].setStatut(1);
                   else list_element.getlist()[i].setStatut(1);
               }
               else {
                   if(mode==2)
                       if(*posX<350){
                           
                       }else
                   list_element.getlist()[i].setStatut(0);
                   else list_element.getlist()[i].setStatut(0);
                   
               
               }}
         
       }
       if((old_state1==1)&&(new_state1==0)){
           
          
        old_state1=0;
       }
       
         
       }
        return list_element;  
 }
 
