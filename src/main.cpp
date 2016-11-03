#ifdef SFML_STATIC 
#endif 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <state.h>
#include <renderer/Textures.h>

#include "renderer/Tile.h"

#include "renderer/View.h"
#include "renderer/Render.h"
#include "control/Clavier.h"
#include "control/Souris.h"



state::State state_game;
control::Clavier clavier;
control::Souris souris;






int main()
{   
    
     
     
    state_game.init();
    renderer::Render render;
     render.init(state_game);
     std::cout<<state_game.list_territory.size()<<" est le nombre de territoire"<<std::endl;
     
     for(int i=0;i<state_game.getListListElement().size();i++)
         if(state_game.getListListElement()[i].getIdView()==4)
             for(int j=0;j<state_game.getListListElement()[i].getlist().size();j++)
         std::cout<<state_game.getListListElement()[i].getlist()[j].territory<<"   "<<i<<std::endl;
     std::cout<<state_game.getListListElement().size()<<" est le nombre de liste d'element"<<std::endl;
     for(int i=0;i<state_game.getListListElement().size();i++)
     std::cout<<state_game.getListListElement()[i].getSize()<<" est le nombre d'element dans la liste "<< i <<std::endl;
    
     
    while (render.window.isOpen())
    {   
        
        souris.Update(render.window);
        sf::Event event;
    
    clavier.gestion_clavier(state_game);
    for (int i=0;i<state_game.getListListElement().size();i++){
        state_game.getListListElement()[i]=souris.gestion_souris(state_game.getListListElement()[i],state_game.player,state_game.getState());}
        
  
    
        while (render.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                render.window.close();
           
            
        }
    state_game.upDate();
    render.upDate(state_game);
       render.draw(state_game); 
    }

    return 0;
}

