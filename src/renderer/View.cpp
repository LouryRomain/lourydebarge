/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <renderer/View.h>





sf::FloatRect view_plage_commune_set(0.804f,0,1,0.18f);
sf::FloatRect view_menu_set(0,0,0.3f,1);
int window_width=1200;
int window_heigth=700;
sf::Vector2f plage_commune_dim1(235,128);



#pragma endregion variables

    renderer::View::View (){
        
    }
    renderer::View::~View (){
        
    }
    void renderer::View::View_init (){
        view_boutique.reset(sf::FloatRect(0,0,window_width,window_heigth));
            view_boutique.setViewport(sf::FloatRect(0,0,1,1));
            
            view_plage_commune.reset(sf::FloatRect(window_width-plage_commune_dim1.x,0,window_width,plage_commune_dim1.y));
            view_plage_commune.setViewport(view_plage_commune_set);
            
            view_map.reset(sf::FloatRect(0,0,window_width,window_heigth));
            
            view_menu.reset(sf::FloatRect(0,0,window_width,window_heigth));
            view_menu.setViewport(view_menu_set);
            
            
            
            view_minimap.reset(sf::FloatRect(0,0,window_width,window_heigth));
            view_minimap.setViewport(sf::FloatRect(0.75f,0.75f,1,1));
             
    }