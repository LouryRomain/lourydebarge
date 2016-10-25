#include "ListElement.h"
#include <iostream>

enum type{rien,button_ok_type,plage_menu_type,carte_verso_type,soldat_type,plage_commune_type,button_add_type,button_minus_type,chiffre_unite_type,chiffre_dizaine_type,prix_unite_type,prix_dizaine_type,prix_centaine_type,plage_carte_A_type,plage_carte_B_type,plage_carte_C_type,tour_type};
int ajustement_sprite_chiffre=2;

int timeCompteurUp=80;
int unable=0;

state::ListElement::ListElement (){
    size=0;
    
}
state::ListElement::~ListElement (){
    
}
void state::ListElement::add_element (state::Element element){
    size++;
    list_element.push_back(element);
    
}
state::Element* state::ListElement::getlist (){
    state::Element* list=new state::Element[size];
    for(int i=0;i<size;i++)
    list[i]=list_element[i];
    return list;
}


int state::ListElement::getSize (){
    return size;
}

void state::ListElement::init (){
    for(int i=0;i<size;i++){
        list_element[i].init();
    if((list_element[i].getType()==prix_unite_type)||(list_element[i].getType()==prix_dizaine_type)||(list_element[i].getType()==prix_centaine_type))
        list_element[i].sprite.setColor(sf::Color::Green);
        if((list_element[i].getType()==plage_carte_A_type)||(list_element[i].getType()==plage_menu_type))
    list_element[i].sprite.setTextureRect(sf::IntRect(0,0,list_element[i].getDim().x,list_element[i].getDim().y));
        if(list_element[i].getType()==plage_carte_B_type)
    list_element[i].sprite.setTextureRect(sf::IntRect(0,list_element[i].getDim().y,list_element[i].getDim().x,list_element[i].getDim().y));
        if(list_element[i].getType()==plage_carte_C_type)
    list_element[i].sprite.setTextureRect(sf::IntRect(0,list_element[i].getDim().y*2,list_element[i].getDim().x,list_element[i].getDim().y));
        
    }
    
    
    }
    

void state::ListElement::draw (sf::RenderWindow& window,state::ListTerritory list_territory,state::State state){
    for(int i=0;i<size;i++)
        if(*(state.Mode)==1){
        if(list_territory.cliked==0){
            if(list_element[i].getType()==plage_menu_type)
         window.draw((list_element[i].sprite));}
        else window.draw((list_element[i].sprite));}
             
        else{ window.draw((list_element[i].sprite));}
        }
        

//sf::Clock time_compteur;
void state::ListElement::upDate (control::Souris souris,sf::RenderWindow& window,sf::View view,state::ListTerritory list_territory){
    
   
    sf::Vector2i pixelPos=sf::Mouse::getPosition(window);
    sf::Vector2f worldPos =window.mapPixelToCoords(pixelPos,view);
    float mouseX=worldPos.x;
    float mouseY=worldPos.y;
    
    
    for(int i=0;i<size;i++){
     
        
       if((list_element[i].getType()==button_ok_type)||(list_element[i].getType()==button_add_type)||(list_element[i].getType()==button_minus_type)||(list_element[i].getType()==plage_menu_type))
        list_element[i].sprite.setTextureRect(sf::IntRect(list_element[i].getAnim().x*list_element[i].getDim().x,list_element[i].getAnim().y*list_element[i].getDim().y,list_element[i].getDim().x,list_element[i].getDim().y));
       
       if((list_element[i].getType()==prix_unite_type)||(list_element[i].getType()==prix_dizaine_type)||(list_element[i].getType()==prix_centaine_type)||(list_element[i].getType()==chiffre_unite_type)||(list_element[i].getType()==chiffre_dizaine_type))
           list_element[i].sprite.setTextureRect(sf::IntRect(list_element[i].getAnim().x*list_element[i].getDim().x+ajustement_sprite_chiffre,list_element[i].getAnim().y,list_element[i].getDim().x,list_element[i].getDim().y));
       
       if(list_territory.cliked!=0){
           if(list_element[i].getType()==plage_menu_type)
                list_element[i].sprite.setTextureRect(sf::IntRect(list_element[i].getDim().x,0,list_element[i].getDim().x,list_element[i].getDim().y));
       
           
       }
           
       
       
       if(*(souris.left)==1)
       {
       
           
           
           if(*(souris.frontDesc)==1){
               
               if((list_element[i].getType()==button_add_type)||(list_element[i].getType()==button_minus_type))
               list_element[i].setAnim(sf::Vector2i(list_element[i].getAnim().x,0));
               
               
               
               
               if((list_element[i].getType()==button_add_type)||(list_element[i].getType()==button_minus_type))
           list_element[i].setAnim(sf::Vector2i(0,list_element[i].getAnim().y));
           
           }
       
           if((mouseX>list_element[i].pos.x) && (mouseX<list_element[i].pos.x+list_element[i].scale.x*list_element[i].getDim().x) && (mouseY>list_element[i].pos.y) && (mouseY<list_element[i].pos.y+list_element[i].scale.y*list_element[i].getDim().y))
       {
               
            
               
           if((list_element[i].getType()==button_add_type)||(list_element[i].getType()==button_minus_type))
           list_element[i].setAnim(sf::Vector2i(list_element[i].getAnim().x,1));
           
           if((list_element[i].getType()==button_ok_type))
           list_element[i].setAnim(sf::Vector2i(1,list_element[i].getAnim().y));
           
           
          //if(time_compteur.getElapsedTime().asMilliseconds()>=timeCompteurUp)
          // {
           if((list_element[i].getType()==button_minus_type)){
               std::cout<<(list_element[i].getType()==button_minus_type);
               for(int t=0;t<size;t++){
               if ((list_element[t].getType()==chiffre_dizaine_type))
                   if(list_element[t].getAnim().x==0)
         {for(int v=0;v<size;v++){
             if ((list_element[v].getType()==chiffre_unite_type)){
         
             if(list_element[v].getAnim().x!=0) list_element[v].setAnim(sf::Vector2i(list_element[v].getAnim().x-1,list_element[v].getAnim().y));
             if(list_element[v].getAnim().x==0) list_element[v].setAnim(sf::Vector2i(9,list_element[v].getAnim().y));
             
            
         if(list_element[v].getAnim().x==9)
         {
             list_element[t].setAnim(sf::Vector2i(9,list_element[t].getAnim().y));
             list_element[v].setAnim(sf::Vector2i(list_element[v].getAnim().x-1,list_element[v].getAnim().y));
         }
         
             }}}
         else
         {for(int v=0;v<size;v++){
             if ((list_element[v].getType()==chiffre_unite_type)){
            if (list_element[v].getAnim().x==9)
            {
                list_element[v].setAnim(sf::Vector2i(list_element[v].getAnim().x-1,list_element[v].getAnim().y));
                list_element[t].setAnim(sf::Vector2i(list_element[t].getAnim().x-1,list_element[t].getAnim().y));
            }
            if (list_element[v].getAnim().x==0)
                list_element[v].setAnim(sf::Vector2i(9,list_element[v].getAnim().y));
                        else
                            list_element[v].setAnim(sf::Vector2i(list_element[v].getAnim().x-1,list_element[v].getAnim().y));
            
                
                
            
             }}}}
           
           }
           
           
           if((list_element[i].getType()==button_add_type)){
               for(int t=0;t<size;t++){
               if ((list_element[t].getType()==chiffre_dizaine_type))
                   if(list_element[t].getAnim().x==9)
         {for(int v=0;v<size;v++){
             if ((list_element[v].getType()==chiffre_unite_type)){
         
             if(list_element[v].getAnim().x!=9) list_element[v].setAnim(sf::Vector2i(list_element[v].getAnim().x+1,list_element[v].getAnim().y));
             if(list_element[v].getAnim().x==9) list_element[v].setAnim(sf::Vector2i(0,list_element[v].getAnim().y));
             
            
         if(list_element[v].getAnim().x==8)
         {
             list_element[t].setAnim(sf::Vector2i(0,list_element[t].getAnim().y));
             list_element[v].setAnim(sf::Vector2i(list_element[v].getAnim().x+1,list_element[v].getAnim().y));
         }
         
             }}}
         else
         {for(int v=0;v<size;v++){
             if ((list_element[v].getType()==chiffre_unite_type)){
            if (list_element[v].getAnim().x==8)
            {
                list_element[v].setAnim(sf::Vector2i(list_element[v].getAnim().x+1,list_element[v].getAnim().y));
                list_element[t].setAnim(sf::Vector2i(list_element[t].getAnim().x+1,list_element[t].getAnim().y));
            }
            if (list_element[v].getAnim().x==9)
                list_element[v].setAnim(sf::Vector2i(0,list_element[v].getAnim().y));
                        else
                            list_element[v].setAnim(sf::Vector2i(list_element[v].getAnim().x+1,list_element[v].getAnim().y));
            
                
                
            
             }}}}
           
           }
           //time_compteur->restart();
          // }
           
            
        }
        else 
        {
               
               
           if((list_element[i].getType()==button_add_type)||(list_element[i].getType()==button_minus_type))
           list_element[i].setAnim(sf::Vector2i(list_element[i].getAnim().x,0));
           
           if((list_element[i].getType()==button_ok_type))
           list_element[i].setAnim(sf::Vector2i(0,list_element[i].getAnim().y));
         
         }
       }
        else
        {
           
       if((list_element[i].getType()==button_add_type)||(list_element[i].getType()==button_minus_type))
           list_element[i].setAnim(sf::Vector2i(list_element[i].getAnim().x,0));
       
       if((list_element[i].getType()==button_ok_type))
           list_element[i].setAnim(sf::Vector2i(0,list_element[i].getAnim().y));
       
        }
if (list_element[i].getType()==prix_dizaine_type)
    for(int v=0;v<size;v++)
    {
        if (list_element[v].getType()==chiffre_unite_type)
            list_element[i].setAnim(list_element[v].getAnim());
    }
       if (list_element[i].getType()==prix_centaine_type)
    for(int v=0;v<size;v++)
    {
        if (list_element[v].getType()==chiffre_dizaine_type)
            list_element[i].setAnim(list_element[v].getAnim());
    }
    }
   
}
