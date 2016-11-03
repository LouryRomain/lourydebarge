#include "Animation.h"
#include "state/Player.h"

#include <SFML/Graphics.hpp>
#include <iostream>


renderer::Animation::Animation (){
   
  
}
renderer::Animation::~Animation (){
    
}
std::vector<sf::Sprite> renderer::Animation::Update(std::vector<sf::Sprite> list_sprite,state::ListElement list_element,state::Player& player,std::vector<state::Territory> list_territory){

    
    for(int i=0;i<list_element.getSize();i++){
        if(list_element.getlist()[i].isClickable()){
        if ((list_element.getlist()[i].getType()==13)||(list_element.getlist()[i].getType()==22)||(list_element.getlist()[i].getType()==23)||(list_element.getlist()[i].getType()==24))
    { 
        if(list_element.getlist()[i].getStatut()==1)
            list_sprite[i].setTextureRect(sf::IntRect(1*64,0,64,22));
        else list_sprite[i].setTextureRect(sf::IntRect(0,0,64,22));
    }
      if (list_element.getlist()[i].getType()==14)
    { 
        if(list_element.getlist()[i].getStatut()==1)
            list_sprite[i].setTextureRect(sf::IntRect(1*25,25,25,25));
        else list_sprite[i].setTextureRect(sf::IntRect(1*25,0,25,25));
    }  
        if (list_element.getlist()[i].getType()==15)
    { 
        if(list_element.getlist()[i].getStatut()==1)
            list_sprite[i].setTextureRect(sf::IntRect(0,25,25,25));
        else list_sprite[i].setTextureRect(sf::IntRect(0,0,25,25));
        } }
        if (list_element.getlist()[i].getType()==16)
    {  
        if (list_territory[list_element.getlist()[i].territory].get_gang()==0)
           list_sprite[list_element.getlist()[i].territory].setColor(sf::Color::Blue);
        
        if (list_territory[list_element.getlist()[i].territory].get_gang()==1)
           list_sprite[list_element.getlist()[i].territory].setColor(sf::Color(50,50,50));
        
        if (list_territory[list_element.getlist()[i].territory].get_gang()==2)
           list_sprite[list_element.getlist()[i].territory].setColor(sf::Color::Green);
        
        if (list_territory[list_element.getlist()[i].territory].get_gang()==3)
           list_sprite[list_element.getlist()[i].territory].setColor(sf::Color::Magenta);
            
        if (list_territory[list_element.getlist()[i].territory].get_gang()==4)
           list_sprite[list_element.getlist()[i].territory].setColor(sf::Color::Yellow);
        
        if(list_element.getlist()[i].getStatut()==1)
        {list_sprite[i].setScale(3,3);
        
        }
        else {list_sprite[i].setScale(2,2);
        
        }
    } 
        
        
        if(list_element.getlist()[i].isChiffre()){
        if(list_element.getIdView()==5){
            if(list_element.getlist()[i].getType()==5){
                if(list_element.getlist()[i].getStatut()==1)
                    this->affiche_chiffre(player.gang.get_money()%10,list_sprite[i]);
                
                if(list_element.getlist()[i].getStatut()==2)
                    this->affiche_chiffre((player.gang.getListTerritory().size()%10),list_sprite[i]);
                
                
            }
            if(list_element.getlist()[i].getType()==6){
                if(list_element.getlist()[i].getStatut()==1)
                    if(player.gang.get_money()>9)
                {
                        this->affiche_chiffre(static_cast<int>((player.gang.get_money()%100)/10),list_sprite[i]);}
                    else this->affiche_chiffre(-1,list_sprite[i]);
                
                        if(player.gang.getListTerritory().size()>9)
                if(list_element.getlist()[i].getStatut()==2)
                    this->affiche_chiffre(static_cast<int>((player.gang.getListTerritory().size()%100)/10),list_sprite[i]);
            
                        
            }
                        
            if(list_element.getlist()[i].getType()==7)
                if(list_element.getlist()[i].getStatut()==1)
                    if(player.gang.get_money()>99){
                        this->affiche_chiffre(static_cast<int>((player.gang.get_money()%1000)/100),list_sprite[i]);}
                    else this->affiche_chiffre(-1,list_sprite[i]);
            
            if(list_element.getlist()[i].getType()==8)
                if(list_element.getlist()[i].getStatut()==1)
                    if(player.gang.get_money()>999){
                    
                    this->affiche_chiffre(static_cast<int>(player.gang.get_money()/1000),list_sprite[i]);}
               else this->affiche_chiffre(-1,list_sprite[i]);
        }
            
    
        
        if((list_element.getIdView()==1)||(list_element.getIdView()==3)){
            if(list_element.getlist()[i].getType()==5){
                if(list_element.getlist()[i].getStatut()==0)
                    this->affiche_chiffre(player.getCompteur()%10,list_sprite[i]);
                if(list_element.getlist()[i].getStatut()==2)
                        this->affiche_chiffre((player.tour_cliked->territory)%10,list_sprite[i]);
                 if(list_element.getlist()[i].getStatut()==1)
                        this->affiche_chiffre(list_territory[(player.tour_cliked->territory)].get_nb_unit()%10,list_sprite[i]);
                 
            }
                if(list_element.getlist()[i].getType()==19)
                    this->affiche_chiffre((player.getCompteur()*10)%10,list_sprite[i]);
                
            if(list_element.getlist()[i].getType()==6){
        
                    if(list_element.getlist()[i].getStatut()==0)
                        this->affiche_chiffre(static_cast<int>((player.getCompteur()%100)/10),list_sprite[i]);
                    if(list_element.getlist()[i].getStatut()==2)
                        if((player.tour_cliked->territory)>9)
                        this->affiche_chiffre(static_cast<int>((player.tour_cliked->territory)/10),list_sprite[i]);
                    if(list_element.getlist()[i].getStatut()==1)
                        this->affiche_chiffre(static_cast<int>((list_territory[player.tour_cliked->territory].get_nb_unit())/10),list_sprite[i]);
                    
            }
            
            if(list_element.getlist()[i].getType()==20)
                    if(player.getCompteur()!=0)
                {
                    this->affiche_chiffre(static_cast<int>((player.getCompteur()*10%100)/10),list_sprite[i]);}
                    else this->affiche_chiffre(-1,list_sprite[i]);
                    
            if(list_element.getlist()[i].getType()==21)
                if(player.getCompteur()>9)
                        this->affiche_chiffre(static_cast<int>(((player.getCompteur()*10)%1000)/100),list_sprite[i]);
                else this->affiche_chiffre(-1,list_sprite[i]);
           
        }
    
        if(list_element.getIdView()==4){
                
                if(list_element.getlist()[i].getType()==5)
                    if(list_element.getlist()[i].getStatut()!=3)
                    this->affiche_chiffre(list_territory[i-31].get_nb_unit()%10,list_sprite[i]);
                    else
                    {if(player.get_chiffre_pris()!=0){
                    this->affiche_chiffre((player.get_chiffre_pris()%10),list_sprite[i]);
                    
                    list_sprite[i].setPosition(list_element.getlist()[i].getPosY(),list_element.getlist()[i].getPosX()+25);
                    }else  this->affiche_chiffre(-1,list_sprite[i]);
                   
                    }
                 if(list_element.getlist()[i].getType()==6)
                     if(list_element.getlist()[i].getStatut()!=3)
                     {if(list_territory[i-62].get_nb_unit()>9)
                     this->affiche_chiffre(static_cast<int>(list_territory[i-62].get_nb_unit())/10,list_sprite[i]);
                     }else {if(player.get_chiffre_pris()>9){
                      this->affiche_chiffre(static_cast<int>((player.get_chiffre_pris()%100)/10),list_sprite[i]);
               list_sprite[i].setPosition(list_element.getlist()[i].getPosY()-34,list_element.getlist()[i].getPosX()+25);
                
                     }else this->affiche_chiffre(-1,list_sprite[i]);
              
                            
                     }
        }
        }
    
    
    
    
    
    }
    
   
    
     
    return list_sprite;
}

sf::Sprite renderer::Animation::affiche_chiffre(int chiffre,sf::Sprite& sprite){
    
    int dim=17;
    int y=72;
    int x;
    if(chiffre!=0)
    x=chiffre-1%10;
    else x=9;
    if(chiffre<0)
        x=10;
    sprite.setTextureRect(sf::IntRect(x*dim+2,y,dim,dim));    
}