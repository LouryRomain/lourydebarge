/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <renderer/Render.h>

renderer::Render::Render(){
    
};

renderer::Render::~Render(){
    
}



void renderer::Render::add_element(sf::Sprite& element,std::vector<sf::Sprite> list){
   list.push_back(element); 
};

void renderer::Render::remove_element(std::vector<sf::Sprite> list){
   list.clear();
    };
