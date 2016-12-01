#ifdef SFML_STATIC 
#endif 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <state.h>
#include <renderer/Textures.h>

#include "renderer/Tile.h"

#include "renderer/View.h"
#include "renderer/Render.h"
#include "ihm/Clavier.h"
#include "ihm/Souris.h"
#include "engine/Move_unit.h"
#include "engine/Engine.h"
#include "ia/IA.h"
#include "state/State.h"
#include "engine/Fifo.h"
#include <thread>
#include <mutex>




/*int thread_1(engine::Engine& game, state::State& state) {

    while (1) {
        std::lock_guard<std::mutex> lock(mtx);
        game.run(state_game);
            std::cout<<"j'update l'etat du joueur"<<std::endl;
    }
    return 0;
}
*/
int main() {
state::State state_game;
ihm::Clavier clavier;
ihm::Souris souris;
engine::Engine game;
engine::Fifo fifo;


   std::thread th1(&engine::Fifo::read,&fifo,std::ref(state_game));
    engine::Command* commande;
    state_game.init();
    renderer::Render render;
    render.init(state_game);
    ia::IA bot(1);
    state::Gang bot1;
    bot1.ID = 1;
    engine::Command* command;


    ihm::Player player;
    state_game.add_Gang(player.gang);

    state_game.add_Gang(bot1);

    int pause = 0;
    int count_pause = 0;
    int count_pause2 = 0;
    int transi = 0;
    while (render.window.isOpen()) {

        player.Update(state_game);
        if (player.gang.getTurn() == 1)
            souris.Update(render.window);
        sf::Event event;

        if (pause == 1)
            count_pause++;
        if (transi == 1) {
            count_pause2++;

        }


        for (int i = 0; i < state_game.getListListElement().size(); i++) {
            state_game.getListListElement()[i] = souris.gestion_souris(state_game.getListListElement()[i], player, player.get_state());
        }



        while (render.window.pollEvent(event)) {


            if (event.type == sf::Event::Closed)
                render.window.close();
            else if ((event.type == sf::Event::KeyPressed)) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)&&(player.gang.getTurn() == 1))
                    clavier.gestion_clavier(state_game, sf::Keyboard::B, player);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&(player.gang.getTurn() == 1))
                    clavier.gestion_clavier(state_game, sf::Keyboard::Up, player);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&(player.gang.getTurn() == 1))
                    clavier.gestion_clavier(state_game, sf::Keyboard::Down, player);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&(player.gang.getTurn() == 1))
                    clavier.gestion_clavier(state_game, sf::Keyboard::Left, player);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&(player.gang.getTurn() == 1))
                    clavier.gestion_clavier(state_game, sf::Keyboard::Right, player);

            }
        }


        if (bot1.getTurn() == 1) {
            bot1.setTurn(0);
            bot.play(state_game);

            for (int i = 0; i < state_game.getListListElement().size(); i++)
                if (state_game.getListListElement()[i].getIdView() == 4) {
                    delete player.view_posX;
                    player.view_posX = new int;
                    delete player.view_posY;
                    player.view_posY = new int;
                    if (state_game.getListListElement()[i].getlist()[bot.action.id_terr_to].getPosY() > state_game.getListListElement()[i].getlist()[bot.action.id_terr_from].getPosY())
                        *player.view_posY = state_game.getListListElement()[i].getlist()[bot.action.id_terr_to].getPosY() - 300 - static_cast<int> (std::abs(state_game.getListListElement()[i].getlist()[bot.action.id_terr_to].getPosY() - state_game.getListListElement()[i].getlist()[bot.action.id_terr_from].getPosY()) / 2);
                    else
                        *player.view_posY = state_game.getListListElement()[i].getlist()[bot.action.id_terr_from].getPosY() - 300 - static_cast<int> (std::abs(state_game.getListListElement()[i].getlist()[bot.action.id_terr_to].getPosY() - state_game.getListListElement()[i].getlist()[bot.action.id_terr_from].getPosY()) / 2);

                    if (state_game.getListListElement()[i].getlist()[bot.action.id_terr_to].getPosX() > state_game.getListListElement()[i].getlist()[bot.action.id_terr_from].getPosX())
                        *player.view_posX = state_game.getListListElement()[i].getlist()[bot.action.id_terr_to].getPosX() - 500 - static_cast<int> (std::abs(state_game.getListListElement()[i].getlist()[bot.action.id_terr_to].getPosX() - state_game.getListListElement()[i].getlist()[bot.action.id_terr_from].getPosX()) / 2);
                    else
                        *player.view_posX = state_game.getListListElement()[i].getlist()[bot.action.id_terr_from].getPosX() - 500 - static_cast<int> (std::abs(state_game.getListListElement()[i].getlist()[bot.action.id_terr_to].getPosX() - state_game.getListListElement()[i].getlist()[bot.action.id_terr_from].getPosX()) / 2);
                }
            pause = 1;
        }
        if (count_pause > 30) {
            pause = 0;
            count_pause = 0;
            fifo.mutex.lock();
            commande=new engine::Move_unit(bot.action.id_terr_to,bot.action.id_terr_from,bot.action.nb_unit);
            fifo.write(state_game,commande);
            fifo.mutex.unlock();
            

            transi = 1;
        }
        if (count_pause2 > 30) {
            transi = 0;
            count_pause2 = 0;
            bot1.setAction_done(bot1.getAction_done() + 1);
            bot1.setTurn(1);
        }
        game.Update(state_game, player,fifo);
        
        render.upDate(state_game, player);
        render.draw(player);
   
        bot.Update(state_game);
    }

    return 0;
}

