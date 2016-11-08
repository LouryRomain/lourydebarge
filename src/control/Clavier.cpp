
#include <control/Clavier.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <state/State.h>


int new_state;
int old_state=0;
int speed=25;
int posX;
int posY;

 control::Clavier::Clavier (){
     
 }
    control::Clavier::~Clavier (){
        
    }
   void control::Clavier::gestion_clavier (state::State& state){
        
       
       
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        new_state=1;
    else
        new_state=0;
       
       if((old_state==0)&&(new_state==1))
       {
           if(state.getState()==1)
           state.setState(0);
           else state.setState(1);
           state.player.setCompteur(0);
           old_state=1;
       }
       if((old_state==1)&&(new_state==0)){
            
        old_state=0;
        }

          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        { 
          posY=*(state.player.view_posY);
          delete state.player.view_posY;
          state.player.view_posY=new int;
          *(state.player.view_posY)=posY-speed;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {   
          posY=*(state.player.view_posY);
          delete state.player.view_posY;
          state.player.view_posY=new int;
          *(state.player.view_posY)=posY+speed;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
           posX=*(state.player.view_posX);
          delete state.player.view_posX;
          state.player.view_posX=new int;
          *(state.player.view_posX)=posX-speed;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
          posX=*(state.player.view_posX);
          delete state.player.view_posX;
          state.player.view_posX=new int;
          *(state.player.view_posX)=posX+speed;
        }                                                        
   }
        
    