#ifdef SFML_STATIC 
#endif 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <state.h>
#include <renderer/Textures.h>

#include "renderer/Tile.h"

#include "renderer/View.h"
#include "renderer/Render.h"
#include "engine/Clavier.h"
#include "engine/Souris.h"
#include "engine/Move_unit.h"
#include "engine/Engine.h"
#include "ia/IA.h"


state::State state_game;
engine::Clavier clavier;
engine::Souris souris;
engine::Move_unit action(2,0,10);
engine::Engine game;

int main() {



    state_game.init();
    renderer::Render render;
    render.init(state_game);
    ia::IA bot(1);
    std::cout << state_game.list_territory.size() << " est le nombre de territoire" << std::endl;


    std::cout << state_game.getListListElement().size() << " est le nombre de liste d'element" << std::endl;
    for (int i = 0; i < state_game.getListListElement().size(); i++)
        std::cout << state_game.getListListElement()[i].getSize() << " est le nombre d'element dans la liste " << i << std::endl;

    int pause=0;
        int count_pause=0;
    while (render.window.isOpen()) {
        
        souris.Update(render.window);
        sf::Event event;
        
        if(pause==1)
            count_pause++;
        
      
   
        for (int i = 0; i < state_game.getListListElement().size(); i++) {
            state_game.getListListElement()[i] = souris.gestion_souris(state_game.getListListElement()[i], state_game.player, state_game.getState());
        }



        while (render.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                render.window.close();
            else if((event.type==sf::Event::KeyPressed))
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
                    clavier.gestion_clavier(state_game,sf::Keyboard::B);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    clavier.gestion_clavier(state_game,sf::Keyboard::Up);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    clavier.gestion_clavier(state_game,sf::Keyboard::Down);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    clavier.gestion_clavier(state_game,sf::Keyboard::Left);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    clavier.gestion_clavier(state_game,sf::Keyboard::Right);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    bot.play(state_game);
                    
                    for (int i=0;i<state_game.getListListElement().size();i++)
    if(state_game.getListListElement()[i].getIdView()==4){
        delete state_game.player.view_posX;
        state_game.player.view_posX=new int;
         delete state_game.player.view_posY;
        state_game.player.view_posY=new int;       
        if(state_game.getListListElement()[i].getlist()[bot.action.id_terr_to].getPosY()>state_game.getListListElement()[i].getlist()[bot.action.id_terr_from].getPosY())
        *state_game.player.view_posY=state_game.getListListElement()[i].getlist()[bot.action.id_terr_to].getPosY()-300-static_cast<int>(std::abs(state_game.getListListElement()[i].getlist()[bot.action.id_terr_to].getPosY()-state_game.getListListElement()[i].getlist()[bot.action.id_terr_from].getPosY())/2);
        else
            *state_game.player.view_posY=state_game.getListListElement()[i].getlist()[bot.action.id_terr_from].getPosY()-300-static_cast<int>(std::abs(state_game.getListListElement()[i].getlist()[bot.action.id_terr_to].getPosY()-state_game.getListListElement()[i].getlist()[bot.action.id_terr_from].getPosY())/2);
       
          if(state_game.getListListElement()[i].getlist()[bot.action.id_terr_to].getPosX()>state_game.getListListElement()[i].getlist()[bot.action.id_terr_from].getPosX())  
        *state_game.player.view_posX=state_game.getListListElement()[i].getlist()[bot.action.id_terr_to].getPosX()-500-static_cast<int>(std::abs(state_game.getListListElement()[i].getlist()[bot.action.id_terr_to].getPosX()-state_game.getListListElement()[i].getlist()[bot.action.id_terr_from].getPosX())/2);
          else 
            *state_game.player.view_posX=state_game.getListListElement()[i].getlist()[bot.action.id_terr_from].getPosX()-500-static_cast<int>(std::abs(state_game.getListListElement()[i].getlist()[bot.action.id_terr_to].getPosX()-state_game.getListListElement()[i].getlist()[bot.action.id_terr_from].getPosX())/2);  
    }
                    pause=1;}
                   
                
        }
         if(count_pause>30){
                        pause=0;
                        count_pause=0;
                    bot.action.make(state_game);
                    }
        game.Update(state_game);
        state_game.upDate();
        bot.Update(state_game);
      
        render.upDate(state_game);
        render.draw(state_game);
    }

    return 0;
}

