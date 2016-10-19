/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<renderer/Tile.h>
#include <iostream>

renderer::Tile::Tile(){
    
};

renderer::Tile::~Tile(){
    
};
void renderer::Tile::convert(std::string path){
    sf::Image image1;
    std::cout<<path;
   image1.loadFromFile(path);
   this->image=image1;
    sf::Vector2u image_dima(image.getSize());
    std::cout<<image_dima.x;
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
        }
       
        
        
        tiles=tab;
}
