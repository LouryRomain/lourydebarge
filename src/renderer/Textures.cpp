/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <renderer/Textures.h>
#include <iostream>

renderer::Textures::Textures() {

};

renderer::Textures::~Textures() {

};

void renderer::Textures::load_texture(const state::Element element) {


    std::string path;
    sf::Vector2f scale(1, 1);
    sf::Vector2i dim(0, 0);
    sf::Vector2i selection(0, 0);




    if (element.getType() == 1) {
        path = "res/autres/plage_menu.png";
        dim = sf::Vector2i(358, 700);
        selection.x = 1;


    }
    if (element.getType() == 2) {
        path = "res/autres/carte_verso.png";
        scale = sf::Vector2f(0.75f, 0.75f);
        dim = sf::Vector2i(261, 406);

    }
    if (element.getType() == 3) {
        path = "res/mechants/homme.png";
        scale = sf::Vector2f(1.5f, 1.5f);
        dim = sf::Vector2i(80, 80);

    }
    if (element.getType() == 4) {
        path = "res/autres/plage_commune.png";
        dim = sf::Vector2i(235, 128);

    }
    if ((element.getType() == 5) ||
            (element.getType() == 6) ||
            (element.getType() == 7) ||
            (element.getType() == 8) ||
            (element.getType() == 19) ||
            (element.getType() == 20) ||
            (element.getType() == 21)) {
        path = "res/lettres/alphabet.png";
        dim = sf::Vector2i(17, 17);
        selection = sf::Vector2i(10, 72);
        if ((element.getType() == 5) ||
                (element.getType() == 6) ||
                (element.getType() == 7) ||
                (element.getType() == 8))
            scale = sf::Vector2f(2, 2);
        if ((element.getType() == 19) ||
                (element.getType() == 20) ||
                (element.getType() == 21))
            scale = sf::Vector2f(1.5f, 1.5f);


    }
    if ((element.getType() == 9) ||
            (element.getType() == 10) ||
            (element.getType() == 11)) {
        path = "res/autres/plage_carte.png";
        dim = sf::Vector2i(228, 76);


        if (element.getType() == 10) {
            selection.y = 1;

        }
        if (element.getType() == 11) {
            selection.y = 2;

        }

    }
    if (element.getType() == 12) {
        path = "res/surfaces/background.png";

    }
    if ((element.getType() == 13) || (element.getType() == 22) || (element.getType() == 23) || (element.getType() == 24)) {
        path = "res/autres/boutton_ok.png";
        scale = sf::Vector2f(1.5f, 1.5f);
        dim = sf::Vector2i(64, 22);

    }
    if ((element.getType() == 14) ||
            (element.getType() == 15)) {
        path = "res/autres/boutton_add.png";
        scale = sf::Vector2f(2, 2);
        dim = sf::Vector2i(25, 25);
        if (element.getType() == 14)
            selection.x = 1;


    }
    if (element.getType() == 16) {
        path = "res/tours/tours.png";
        scale = sf::Vector2f(2, 2);
        dim = sf::Vector2i(68, 68);

    }
    if (element.getType() == 17) {
        path = "res/autres/money.png";
        scale = sf::Vector2f(0.75f, 0.75f);
    }
    if (element.getType() == 18) {
        path = "res/autres/logo.png";

    }



    if (!texture.loadFromFile(path)) {
        std::cout << "Erreuroo" << path << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(element.getPosX(), element.getPosY());
    sprite.setScale(scale);
    if (dim.x != 0)
        if (path != "res/lettres/alphabet.png")
            sprite.setTextureRect(sf::IntRect(selection.x * dim.x, selection.y * dim.y, dim.x, dim.y));
        else {
            sprite.setTextureRect(sf::IntRect(selection.x * dim.x + 2, selection.y, dim.x, dim.y));
            if ((element.getType() == 19) ||
                    (element.getType() == 20) ||
                    (element.getType() == 21))
                sprite.setColor(sf::Color::Green);
        }


}









