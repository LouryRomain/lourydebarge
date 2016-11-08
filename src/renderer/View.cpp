

#include <renderer/View.h>
#include <iostream>
#include "state/State.h"
#include "Render.h"
#include "Tile.h"
#include "Textures.h"
#include "Animation.h"

class TileMap : public sf::Drawable, public sf::Transformable {
public:

    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height) {
        // on charge la texture du tileset
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // on remplit le tableau de vertex, avec un quad par tuile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j) {
                // on récupère le numéro de tuile courant
                int tileNumber = tiles[i + j * height];

                // on en déduit sa position dans la texture du tileset
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                // on définit ses quatre coins
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // on définit ses quatre coordonnées de texture
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        // on applique la transformation
        states.transform *= getTransform();

        // on applique la texture du tileset
        states.texture = &m_tileset;

        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};

TileMap Background;
renderer::Tile tile;
std::string level_1_path = "res/autres/level1.png";
std::string tile_texture_path = "res/surfaces/gravier_herbe.png";
sf::Vector2u tile_dim(28, 28);
renderer::Animation animation;
sf::RectangleShape rectangle(sf::Vector2f(1200, 700));


int thickness_rectangle = 15;
sf::Vector2f minimap_scale(0.25f, 0.25f);



#pragma endregion variables

renderer::View::View(int type) {
    this->type = type;

}

renderer::View::~View() {

}

void renderer::View::View_init(state::State& state) {
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(thickness_rectangle);
    rectangle.setScale(minimap_scale);

    if (type == 4) {
        tile.convert(level_1_path);
        Background.load(tile_texture_path, tile_dim, tile.tiles, tile.image_dim.x, tile.image_dim.y);
        for (int j = 0; j < state.getListListElement().size(); j++) {
            if (state.getListListElement()[j].getIdView() == type) {
                for (int i = 0; i < tile.pos_tour.size(); i++) {


                    state.getListListElement()[j].getlist()[i].setPosX(tile.pos_tour[i].y, tile.pos_tour[i].x);

                }
            }
            if (state.getListListElement()[j].getIdView() == type) {
                for (int i = 0; i < tile.pos_chiffre.size(); i++) {


                    state.getListListElement()[j].getlist()[i + 31].setPosX(tile.pos_chiffre[i].y, tile.pos_chiffre[i].x);
                    state.getListListElement()[j].getlist()[i + 62].setPosX(tile.pos_chiffre[i].y, tile.pos_chiffre[i].x - 34);

                }

            }
        }
    }


    for (int i = 0; i < state.getListListElement().size(); i++) {
        if (type == state.getListListElement()[i].getIdView()) {

            for (int j = 0; j < state.getListListElement()[i].getSize(); j++) {
                renderer::Textures texture;
                list_texture.push_back(texture);
            }
            for (int j = 0; j < state.getListListElement()[i].getSize(); j++) {
                list_texture[j].load_texture(state.getListListElement()[i].getlist()[j]);

                this->add_Sprite(list_texture[j].sprite);
            }
        }
    }

    if (type == 1) {
        view.reset(sf::FloatRect(0, 0, 1200, 700));
        view.setViewport(sf::FloatRect(0, 0, 1, 1));
    }

    if (type == 2) {
        view.reset(sf::FloatRect(0, 0, 85 * 28, 85 * 28));
        view.setViewport(sf::FloatRect(0.75f, 0.75f, 1, 1));


    }

    if (type == 3) {
        view.reset(sf::FloatRect(0, 0, 1200 / 3, 700));
        view.setViewport(sf::FloatRect(0, 0, 0.33f, 1));
    }



    if (type == 5) {
        view.reset(sf::FloatRect(1200 - 235, 0, 1200, 128));
        view.setViewport(sf::FloatRect(0.804f, 0, 1, 0.18f));
    }



}

void renderer::View::draw(sf::RenderWindow& window, int mode) {
    window.setView(view);
    if ((type == 2)&&(mode!=1)) {
                
                Background.setScale(minimap_scale);
                window.draw(Background);
                window.draw(rectangle);
            } 
    for (int i = 0; i<this->list_sprite.size(); i++) {

        if (mode == 0) {
            
            
            
            if ((type == 4)){
                if(i==0){
                Background.setScale(sf::Vector2f(1, 1));
                window.draw(Background);
                }
                window.draw(list_sprite[i]);
                
            }
            
            
            if ((type == 5))
                window.draw(list_sprite[i]);
            

        }

        if (mode == 2){
             
            
            if ((type == 4)){
                if(i==0){
                   Background.setScale(sf::Vector2f(1, 1));
                window.draw(Background);
                }
                
                window.draw(list_sprite[i]);
            
            }
             
            if ((type == 3) || (type == 5))
                window.draw(list_sprite[i]);
        }
           

        if (mode == 1)
            if ((type == 1) || (type == 5))

                window.draw(list_sprite[i]);



    }

}

void renderer::View::add_Sprite(sf::Sprite sprite) {
    list_sprite.push_back(sprite);
}

void renderer::View::View_upDate(state::State state) {
    for (int i = 0; i < state.getListListElement().size(); i++)
        if (type == state.getListListElement()[i].getIdView())
    if (type == 4)
            list_sprite = animation.Update(list_sprite, state.getListListElement()[i], state.player, state.list_territory);
    //if (type == 4)
      //  view.reset(sf::FloatRect(*(state.player.view_posX), *(state.player.view_posY), 1200, 700));
    //if (type == 2)
       // rectangle.setPosition(*(state.player.view_posX) * minimap_scale.x, *(state.player.view_posY) * minimap_scale.y);
}