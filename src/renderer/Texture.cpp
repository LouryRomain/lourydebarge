/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <renderer/Texture.h>
#include <iostream>

 renderer::Texture::Texture(){
     
 };
 renderer::Texture::~Texture(){
     
 };

sf::Sprite renderer::Texture::load_texture (std::string path,sf::Vector2f pos){
    
    if (!texture.loadFromFile(path))
    {
        std::cout<<"Erreur"<< std::endl;
    }
    
    this->sprite.setTexture(texture);
    this->sprite.setPosition(pos);
 
    this->size=texture.getSize();
    
    return this->sprite;
    
};

sf::Vector2u renderer::Texture::getSize (){
    return size;
};
    void renderer::Texture::setSize(sf::Vector2u size){
        this->size=size;
    };
