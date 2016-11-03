#include "Render.h"
#include "Tile.h"
#include "View.h"
#include "Textures.h"
#include <iostream>


sf::RenderWindow window;
int window_width=1200;
int window_heigth=700;
sf::Vector2i pos_window(0,0);
int frame_fps_limit=60;
std::string window_title="Gang War";
renderer::View view_boutique(1);
  renderer::View view_plage_menu(3);
  renderer::View view_plage_commune(5);
  renderer::View view_minimap(2);
  renderer::View  view_map(4);





 renderer::Render::Render (){

  
 }

 renderer::Render::~Render (){
     
 }
 void renderer::Render::init (state::State state_game){
  
  window.create(sf::VideoMode(window_width,window_heigth),window_title);
  window.setPosition(pos_window);
  window.setFramerateLimit(frame_fps_limit);
  
  this->list_view.push_back(view_map);
  this->list_view.push_back(view_boutique);
  this->list_view.push_back(view_plage_menu);
  this->list_view.push_back(view_plage_commune);
  this->list_view.push_back(view_minimap);
 
   
  
  for(int i=0;i<list_view.size();i++)
      list_view[i].View_init(state_game);

  std::cout<<state_game.getState()<<" est le statut "<<std::endl;
  //for(int i=0;i<list_view.size();i++)
  //std::cout<<view_boutique.list_sprite.size()<<std::endl;
 }
 
 void renderer::Render::draw(state::State state_game){
   for(int i=0;i<list_view.size();i++){
       
    list_view[i].draw(window,state_game.getState());}
     
     window.display();
     window.clear();
 }
 
 void renderer::Render::upDate (state::State state_game){
     for(int i=0;i<list_view.size();i++){
       
    list_view[i].View_upDate(state_game);}
 }