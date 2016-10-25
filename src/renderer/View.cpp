/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <renderer/View.h>

#include "state/State.h"





sf::FloatRect view_plage_commune_set(0.804f,0,1,0.18f);
sf::FloatRect view_menu_set(0,0,0.33f,1);
int window_width=1200;
int window_heigth=700;
sf::Vector2f plage_commune_dim1(235,128);
sf::Vector2f position(window_width/2,window_heigth/2);
int thickness_rectangle=3;
sf::Vector2f minimap_scale(0.25f,0.25f);



#pragma endregion variables

    renderer::View::View (){
        
    }
    renderer::View::~View (){
        
    }
    void renderer::View::View_init (state::State state){
      sf::RectangleShape rectangle1(sf::Vector2f(window_width*0.25,window_heigth*0.25f));
      rectangle=rectangle1;
        rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(thickness_rectangle);
        view_boutique.reset(sf::FloatRect(0,0,window_width,window_heigth));
            view_boutique.setViewport(sf::FloatRect(0,0,1,1));
            
            view_plage_commune.reset(sf::FloatRect(window_width-plage_commune_dim1.x,0,window_width,plage_commune_dim1.y));
            view_plage_commune.setViewport(view_plage_commune_set);
            
            view_map.reset(sf::FloatRect(window_width,0,window_width,window_heigth));
           
            
            view_menu.reset(sf::FloatRect(0,0,window_width/3,window_heigth));
            view_menu.setViewport(view_menu_set);
            
            
            
            view_minimap.reset(sf::FloatRect(0,0,85*28,85*28));
            view_minimap.setViewport(sf::FloatRect(0.75f,0.75f,1,1));
             
    }
    
    void renderer::View::View_UpDate(state::State state){
        position.x=state.getPlayer().getPos().x ;//- window_width/2;
            position.y=state.getPlayer().getPos().y; //- window_heigth/2;
            rectangle.setPosition((position.x)*minimap_scale.x,(position.y)*minimap_scale.y);
            view_map.reset(sf::FloatRect(position.x,position.y,window_width,window_heigth));
             view_map.setViewport(sf::FloatRect(0.28f,0,1,1));
    }