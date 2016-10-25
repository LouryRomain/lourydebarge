/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <control/Clavier.h>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "renderer/Level.h"

int new_state;
int old_state=0;
int speed=25;

 control::Clavier::Clavier (){
     
 }
    control::Clavier::~Clavier (){
        
    }
   void control::Clavier::gestion_clavier (state::State state){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        { state.getPlayer().setPos(sf::Vector2f(state.getPlayer().getPos().x,state.getPlayer().getPos().y-speed));
            
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {   
            state.getPlayer().setPos(sf::Vector2f(state.getPlayer().getPos().x,state.getPlayer().getPos().y+speed));
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            
            state.getPlayer().setPos(sf::Vector2f(state.getPlayer().getPos().x-speed,state.getPlayer().getPos().y));
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
          
            state.getPlayer().setPos(sf::Vector2f(state.getPlayer().getPos().x+speed,state.getPlayer().getPos().y));
        }
       
       
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        new_state=1;
    else
        new_state=0;
       
       if((old_state==0)&&(new_state==1))
       {
           if(*(state.Mode)==1)
           state.setMode(0);
           else state.setMode(1);
           
           old_state=1;
       }
       if((old_state==1)&&(new_state==0)){
            
        old_state=0;
        }

   }
        
    