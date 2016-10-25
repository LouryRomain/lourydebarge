#include <state/ListTerritory.h>
#include <iostream>

state::ListTerritory::ListTerritory (){
    
}
state::ListTerritory::~ListTerritory (){
    
}
void state::ListTerritory::Update (control::Souris souris,sf::RenderWindow& window,sf::View view){
    sf::Vector2i pixelPos=sf::Mouse::getPosition(window);
    sf::Vector2f worldPos =window.mapPixelToCoords(pixelPos,view);
    float mouseX=worldPos.x;
    float mouseY=worldPos.y;
    for(int i=0;i<list_territory.size();i++){
        if(pixelPos.x>window.getSize().x*0.29f)
    if((mouseX>list_territory[i].tour.pos.x) && (mouseX<list_territory[i].tour.pos.x+list_territory[i].tour.scale.x*list_territory[i].tour.getDim().x) && (mouseY>list_territory[i].tour.pos.y) && (mouseY<list_territory[i].tour.pos.y+list_territory[i].tour.scale.y*list_territory[i].tour.getDim().y))
        { 
        if(list_territory[i].cliked!=1){
            list_territory[i].tour.sprite.setScale(2.2f,2.2f);}
        
        if(*(souris.left)==1)
        {list_territory[i].tour.sprite.setScale(3,3);
        list_territory[i].cliked=true;cliked=i+1;}
    
    }else{
        if(list_territory[i].cliked!=1){
            list_territory[i].tour.sprite.setScale(2,2);}
        else
            if(*(souris.left)==1)
        {list_territory[i].tour.sprite.setScale(2,2);
        list_territory[i].cliked=false;cliked=0;}
    }
        
    }
        
    } 


void state::ListTerritory::draw (sf::RenderWindow& window){
    for(int i=0;i<list_territory.size();i++)
        window.draw(list_territory[i].tour.sprite);
}

void state::ListTerritory::init(){
    for(int i=0;i<list_territory.size();i++){
        list_territory[i].tour.init();
        list_territory[i].tour.sprite.setTextureRect(sf::IntRect(0,0,list_territory[i].tour.getDim().x,list_territory[i].tour.getDim().y));
}
}