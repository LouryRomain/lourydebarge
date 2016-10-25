/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<renderer/Tile.h>
#include <iostream>

#include "state/Element.h"
#include "state/Territory.h"

enum type{rien,button_ok_type,plage_menu_type,carte_verso_type,soldat_type,plage_commune_type,button_add_type,button_minus_type,chiffre_unite_type,chiffre_dizaine_type,prix_unite_type,prix_dizaine_type,prix_centaine_type,plage_carte_A_type,plage_carte_B_type,plage_carte_C_type,tour_type};


renderer::Tile::Tile(){
    
};

renderer::Tile::~Tile(){
    
};
void renderer::Tile::convert(std::string path){
    sf::Image image1;
    
   image1.loadFromFile(path);
   this->image=image1;
    sf::Vector2u image_dima(image.getSize());
    
    this->image_dim=image_dima;
        int* tab=new int[(image_dim.x)*(image_dim.y)];
        for(unsigned j=0;j<image_dim.y;j++)
        for(unsigned i=0;i<image_dim.x;i++)
        {
        if(!static_cast<int>(image.getPixel(i,j).r)==0)
        tab[i+j*(image_dim.y)]=4;
        
        else
        if((i>0)&&(i<image_dim.x-1)&&(j>0)&&(j<image_dim.y-1)){
           if(static_cast<int>(image.getPixel(i,j).r)==0){
        
               
               if((static_cast<int>(image.getPixel(i+1,j).r)==0)&&(static_cast<int>(image.getPixel(i-1,j).r)==0)&&(static_cast<int>(image.getPixel(i,j+1).r)==0)&&(!static_cast<int>(image.getPixel(i,j-1).r)==0))
        tab[i+j*image_dim.y]=7;
        if((static_cast<int>(image.getPixel(i+1,j).r)==0)&&(static_cast<int>(image.getPixel(i-1,j).r)==0)&&(static_cast<int>(image.getPixel(i,j-1).r)==0)&&(!static_cast<int>(image.getPixel(i,j+1).r)==0))
        tab[i+j*image_dim.y]=1;
        if((static_cast<int>(image.getPixel(i,j+1).r)==0)&&(static_cast<int>(image.getPixel(i,j-1).r)==0)&&(static_cast<int>(image.getPixel(i+1,j).r)==0)&&(!static_cast<int>(image.getPixel(i-1,j).r)==0))
        tab[i+j*image_dim.y]=5;
        if((static_cast<int>(image.getPixel(i,j+1).r)==0)&&(static_cast<int>(image.getPixel(i,j-1).r)==0)&&(static_cast<int>(image.getPixel(i-1,j).r)==0)&&(!static_cast<int>(image.getPixel(i+1,j).r)==0))
        tab[i+j*image_dim.y]=3;
        
        
        
               if((static_cast<int>(image.getPixel(i+1,j).r)==0)&&(static_cast<int>(image.getPixel(i,j+1).r)==0)&&(!static_cast<int>(image.getPixel(i-1,j).r)==0)&&(!static_cast<int>(image.getPixel(i,j-1).r)==0))
        tab[i+j*image_dim.y]=8;
        if((static_cast<int>(image.getPixel(i-1,j).r)==0)&&(static_cast<int>(image.getPixel(i,j+1).r)==0)&&(!static_cast<int>(image.getPixel(i+1,j).r)==0)&&(!static_cast<int>(image.getPixel(i,j-1).r)==0))
        tab[i+j*image_dim.y]=6;
        if((static_cast<int>(image.getPixel(i+1,j).r)==0)&&(static_cast<int>(image.getPixel(i,j-1).r)==0)&&(!static_cast<int>(image.getPixel(i-1,j).r)==0)&&(!static_cast<int>(image.getPixel(i,j+1).r)==0))
        tab[i+j*image_dim.y]=2;
        if((static_cast<int>(image.getPixel(i-1,j).r)==0)&&(static_cast<int>(image.getPixel(i,j-1).r)==0)&&(!static_cast<int>(image.getPixel(i+1,j).r)==0)&&(!static_cast<int>(image.getPixel(i,j+1).r)==0))
        tab[i+j*image_dim.y]=0;
           
        
               
               if((static_cast<int>(image.getPixel(i+1,j).r)==0)&&(static_cast<int>(image.getPixel(i,j+1).r)==0)&&(static_cast<int>(image.getPixel(i-1,j).r)==0)&&(static_cast<int>(image.getPixel(i,j-1).r)==0)){
                   if(!static_cast<int>(image.getPixel(i+1,j+1).r)==0)
                           tab[i+j*image_dim.y]=0;
                   
                   if(!static_cast<int>(image.getPixel(i+1,j-1).r)==0)
                           tab[i+j*image_dim.y]=6;
                   
                   if(!static_cast<int>(image.getPixel(i-1,j+1).r)==0)
                           tab[i+j*image_dim.y]=2;
                   
                   if(!static_cast<int>(image.getPixel(i-1,j-1).r)==0)
                           tab[i+j*image_dim.y]=8;
               }
        
                   
        
           
           }
        }else tab[i+j*image_dim.y]=4;
        
        if(static_cast<int>(image.getPixel(i,j).r)==150){
            state::Element tour("/home/utilisateur/Documents/PLT/res/tours/tours.png",sf::Vector2f(i*28,j*28),sf::Vector2f(2,2),sf::Vector2i(0,0),sf::Vector2i(68,68),tour_type);
            
        size++;
        
        pos_tour.push_back(sf::Vector2f(i*28,j*28));
        }
        }
       
        
        
        tiles=tab;
}
