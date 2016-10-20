#include <renderer/Level.h>

#include <renderer/Texture.h>
#include <renderer/View.h>
#include<iostream>

#include "View.h"
#include "Tile.h"


/////initialisation
////All the time 
//plage commune
int plage_commune_width=235;
float plage_commune_pos_Y=0;
sf::Vector2f plage_commune_dim(235,128);

//bouton add
sf::Vector2i anim_button_add(1,0);
sf::Vector2i anim_button_minus(0,0);
sf::Vector2f button_dim(25,25);
sf::Vector2f offset_button_origin(8,10);
sf::Vector2f offset_button_exte(8,5);

//bouton ok
sf::Vector2i anim_button_ok_A(0,0);
sf::Vector2i anim_button_ok_B(0,0);
sf::Vector2i anim_button_ok_C(0,0);
sf::Vector2i anim_button_ok_compteur(0,0);
sf::Vector2f button_ok_dim(64,22);
float decalage_carte_ok=5;
float decalage_nombre_ok=15;

//carte verso
sf::Vector2f carte_A_pos(30,350);
sf::Vector2f carte_B_pos(490,350);
sf::Vector2f carte_C_pos(930,350);
std::string carte_verso_path="/home/utilisateur/Documents/PLT/res/autres/carte_verso.png";
sf::Vector2f carte_verso_scale(0.75f,0.75f);
sf::Vector2f carte_verso_dim(261,406);

//chiffre
sf::Vector2i anim_chiffre_unite(9,72);
sf::Vector2i anim_chiffre_dizaine(9,72);
sf::Vector2i anim_prix_unite(9,72);
sf::Vector2f chiffre_dim(17,17);
sf::Vector2f chiffre_scale(2,2);
sf::Vector2f prix_scale(1.6f,1.6f);
sf::Vector2f chiffre_nb_soldat_unite_pos(590,160);
sf::Vector2f prix_nb_soldat_unite_pos(590,110);
int ajustement_sprite_chiffre=2;

//dragon
int speed=25;
renderer::Texture perso;
sf::Sprite sprite_perso;
enum Dir{Down,Left,Right,Up};
sf::Vector2i anim_dragon(0,Down);
bool Update_dragon=false;
sf::Vector2f perso_pos(600,350);

//plage carte
sf::Vector2f  select_plage_carte_A(0,0);
sf::Vector2f  select_plage_carte_B(0,1);
sf::Vector2f  select_plage_carte_C(0,2);
sf::Vector2f plage_carte_dim(228,76);

//soldat
sf::Vector2i anim_soldat(0,0);
sf::Vector2f soldat_dim(80,80);

//view
sf::View view_boutique;

////Mode 1
//minimap
sf::Vector2f minimap_scale(0.25f,0.25f);

//plage menu
sf::Vector2i anim_plage_menu(1,0);
sf::Vector2i plage_menu_dim(358,700);

//tour 
sf::Vector2i tour_dim(68,68);

//All the time
//plage commune
sf::Vector2f plage_commune_pos(1200-plage_commune_width,plage_commune_pos_Y);
sf::Vector2f pos_default(0,0);
sf::Vector2f scale_default(1,1);
sf::Vector2f button_ok_scale(1.5f,1.5f);

state::Element background("/home/utilisateur/Documents/PLT/res/surfaces/background.png",pos_default,scale_default);
state::Element plage_menu("/home/utilisateur/Documents/PLT/res/autres/plage_menu.png",pos_default,sf::Vector2f(3.3f,1));
state::Element carte_verso_A("/home/utilisateur/Documents/PLT/res/autres/carte_verso.png",sf::Vector2f(30,350),sf::Vector2f(0.75f,0.75f));
state::Element carte_verso_B("/home/utilisateur/Documents/PLT/res/autres/carte_verso.png",sf::Vector2f(490,350),sf::Vector2f(0.75f,0.75f));
state::Element carte_verso_C("/home/utilisateur/Documents/PLT/res/autres/carte_verso.png",sf::Vector2f(930,350),sf::Vector2f(0.75f,0.75f));
state::Element soldat("/home/utilisateur/Documents/PLT/res/mechants/homme.png",sf::Vector2f(700,110),sf::Vector2f(1.5f,1.5f));
state::Element plage_commune("/home/utilisateur/Documents/PLT/res/autres/plage_commune.png",sf::Vector2f(1200-plage_commune_width,0),scale_default);
state::Element button_add("/home/utilisateur/Documents/PLT/res/autres/boutton_add.png",sf::Vector2f(625,150),sf::Vector2f(2,2));
state::Element button_minus("/home/utilisateur/Documents/PLT/res/autres/boutton_add.png",sf::Vector2f(505,150),sf::Vector2f(2,2));
state::Element button_ok_A("/home/utilisateur/Documents/PLT/res/autres/boutton_ok.png",sf::Vector2f(carte_A_pos.x+carte_verso_dim.x/2*carte_verso_scale.x-button_ok_dim.x*button_ok_scale.x/2,carte_A_pos.y+carte_verso_dim.y*carte_verso_scale.y+decalage_carte_ok),sf::Vector2f(1.5f,1.5f));
state::Element button_ok_B("/home/utilisateur/Documents/PLT/res/autres/boutton_ok.png",sf::Vector2f(carte_B_pos.x+carte_verso_dim.x/2*carte_verso_scale.x-button_ok_dim.x*button_ok_scale.x/2,carte_B_pos.y+carte_verso_dim.y*carte_verso_scale.y+decalage_carte_ok),sf::Vector2f(1.5f,1.5f));
state::Element button_ok_C("/home/utilisateur/Documents/PLT/res/autres/boutton_ok.png",sf::Vector2f(carte_C_pos.x+carte_verso_dim.x/2*carte_verso_scale.x-button_ok_dim.x*button_ok_scale.x/2,carte_C_pos.y+carte_verso_dim.y*carte_verso_scale.y+decalage_carte_ok),sf::Vector2f(1.5f,1.5f));
state::Element button_ok_compteur("/home/utilisateur/Documents/PLT/res/autres/boutton_ok.png",sf::Vector2f(chiffre_nb_soldat_unite_pos.x-button_ok_dim.x*button_ok_scale.x/2,chiffre_nb_soldat_unite_pos.y+chiffre_dim.y*chiffre_scale.y+decalage_nombre_ok),sf::Vector2f(1.5f,1.5f));
state::Element chiffre_unite("/home/utilisateur/Documents/PLT/res/lettres/alphabet.png",sf::Vector2f(590,160),sf::Vector2f(2,2));
state::Element chiffre_dizaine("/home/utilisateur/Documents/PLT/res/lettres/alphabet.png",sf::Vector2f(chiffre_nb_soldat_unite_pos.x-chiffre_dim.x*chiffre_scale.x,chiffre_nb_soldat_unite_pos.y),sf::Vector2f(2,2));
state::Element prix_unite("/home/utilisateur/Documents/PLT/res/lettres/alphabet.png",sf::Vector2f(590,110),sf::Vector2f(1.6f,1.6f));
state::Element prix_dizaine("/home/utilisateur/Documents/PLT/res/lettres/alphabet.png",sf::Vector2f(prix_nb_soldat_unite_pos.x-chiffre_dim.x*prix_scale.x,prix_nb_soldat_unite_pos.y),sf::Vector2f(1.6f,1.6f));
state::Element prix_centaine("/home/utilisateur/Documents/PLT/res/lettres/alphabet.png",sf::Vector2f(prix_nb_soldat_unite_pos.x-chiffre_dim.x*prix_scale.x*2,prix_nb_soldat_unite_pos.y),sf::Vector2f(1.6f,1.6f));
state::Element logo_boutique("/home/utilisateur/Documents/PLT/res/autres/logo.png",pos_default,scale_default);
state::Element money("/home/utilisateur/Documents/PLT/res/autres/money.png",sf::Vector2f(630,100),sf::Vector2f(0.75f,0.75f));
state::Element plage_carte_A("/home/utilisateur/Documents/PLT/res/autres/plage_carte.png",sf::Vector2f(carte_A_pos.x+carte_verso_dim.x/2*carte_verso_scale.x-plage_carte_dim.x/2,carte_A_pos.y-plage_carte_dim.y),scale_default);
state::Element plage_carte_B("/home/utilisateur/Documents/PLT/res/autres/plage_carte.png",sf::Vector2f(carte_B_pos.x+carte_verso_dim.x/2*carte_verso_scale.x-plage_carte_dim.x/2,carte_B_pos.y-plage_carte_dim.y),scale_default);
state::Element plage_carte_C("/home/utilisateur/Documents/PLT/res/autres/plage_carte.png",sf::Vector2f(carte_C_pos.x+carte_verso_dim.x/2*carte_verso_scale.x-plage_carte_dim.x/2,carte_C_pos.y-plage_carte_dim.y),scale_default);
state::Element tour("/home/utilisateur/Documents/PLT/res/tours/tours.png",pos_default,sf::Vector2f(2,2));

renderer::View view;

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    
    

    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
    {
        // on charge la texture du tileset
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // on remplit le tableau de vertex, avec un quad par tuile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
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

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
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
std::string level_1_path="/home/utilisateur/Documents/PLT/res/autres/level1.png";
std::string tile_texture_path="/home/utilisateur/Documents/PLT/res/surfaces/cailloux_gravier.png";
sf::Vector2u tile_dim(28,28);

 renderer::Level::Level (){
     
 }
 renderer::Level::~Level (){
     
 }
 
 void renderer::Level::level_init(){
     
     window.Window_init();
     view.View_init();
     plage_commune.init();
    /////////////////////////////////Mode 0 ///////////////////////////////////////////
     
    background.init();
    money.init();
    plage_carte_A.init();
    plage_carte_B.init();
    plage_carte_C.init(); 
    logo_boutique.init();
    carte_verso_A.init();
    carte_verso_B.init();
    carte_verso_C.init();
    button_add.init();
    button_minus.init();
    button_ok_A.init();
    button_ok_B.init();
    button_ok_C.init();
    button_ok_compteur.init();
    soldat.init();
    chiffre_unite.init();
    chiffre_dizaine.init();
    prix_unite.init();
    prix_dizaine.init();
    prix_centaine.init();
   
    plage_carte_A.sprite.setTextureRect(sf::IntRect(plage_carte_dim.x*select_plage_carte_A.x,plage_carte_dim.y*select_plage_carte_A.y,plage_carte_dim.x,plage_carte_dim.y));
    plage_carte_B.sprite.setTextureRect(sf::IntRect(plage_carte_dim.x*select_plage_carte_B.x,select_plage_carte_B.y*plage_carte_dim.y,plage_carte_dim.x,plage_carte_dim.y));
    plage_carte_C.sprite.setTextureRect(sf::IntRect(plage_carte_dim.x*select_plage_carte_C.x,select_plage_carte_C.y*plage_carte_dim.y,plage_carte_dim.x,plage_carte_dim.y));
    prix_unite.sprite.setColor(sf::Color::Green);
    prix_dizaine.sprite.setColor(sf::Color::Green);
    prix_centaine.sprite.setColor(sf::Color::Green);
    
    /////////////////////Mode 1//////////////////////////////
    plage_menu.init();
    tour.init();

    button_add.sprite.setTextureRect(sf::IntRect(anim_button_add.x*button_dim.x,anim_button_add.y*button_dim.y,button_dim.x,button_dim.y));
    button_minus.sprite.setTextureRect(sf::IntRect(anim_button_minus.x*button_dim.x,anim_button_minus.y*button_dim.y,button_dim.x,button_dim.y));
    button_ok_A.sprite.setTextureRect(sf::IntRect(anim_button_ok_A.x*button_ok_dim.x,anim_button_ok_A.y*button_ok_dim.y,button_ok_dim.x,button_ok_dim.y));
    button_ok_B.sprite.setTextureRect(sf::IntRect(anim_button_ok_B.x*button_ok_dim.x,anim_button_ok_B.y*button_ok_dim.y,button_ok_dim.x,button_ok_dim.y));
    button_ok_C.sprite.setTextureRect(sf::IntRect(anim_button_ok_C.x*button_ok_dim.x,anim_button_ok_C.y*button_ok_dim.y,button_ok_dim.x,button_ok_dim.y));
    button_ok_compteur.sprite.setTextureRect(sf::IntRect(anim_button_ok_compteur.x*button_ok_dim.x,anim_button_ok_compteur.y*button_ok_dim.y,button_ok_dim.x,button_ok_dim.y));
    soldat.sprite.setTextureRect(sf::IntRect(anim_soldat.x*soldat_dim.x,anim_soldat.y*soldat_dim.y,soldat_dim.x,soldat_dim.y));
    chiffre_unite.sprite.setTextureRect(sf::IntRect(anim_chiffre_unite.x*chiffre_dim.x+ajustement_sprite_chiffre,anim_chiffre_unite.y,chiffre_dim.x,chiffre_dim.y));
    chiffre_dizaine.sprite.setTextureRect(sf::IntRect(anim_chiffre_dizaine.x*chiffre_dim.x+ajustement_sprite_chiffre,anim_chiffre_dizaine.y,chiffre_dim.x,chiffre_dim.y));
    prix_unite.sprite.setTextureRect(sf::IntRect(anim_prix_unite.x*chiffre_dim.x+ajustement_sprite_chiffre,anim_prix_unite.y,chiffre_dim.x,chiffre_dim.y));
    prix_dizaine.sprite.setTextureRect(sf::IntRect(anim_chiffre_unite.x*chiffre_dim.x+ajustement_sprite_chiffre,anim_chiffre_unite.y,chiffre_dim.x,chiffre_dim.y));
    prix_centaine.sprite.setTextureRect(sf::IntRect(anim_chiffre_dizaine.x*chiffre_dim.x+ajustement_sprite_chiffre,anim_chiffre_dizaine.y,chiffre_dim.x,chiffre_dim.y));
    plage_menu.sprite.setTextureRect(sf::IntRect(anim_plage_menu.x*plage_menu_dim.x,anim_plage_menu.y*plage_menu_dim.y,plage_menu_dim.x,plage_menu_dim.y));
 
    tile.convert(level_1_path);
    Background.load(tile_texture_path,tile_dim,tile.tiles,tile.image_dim.x,tile.image_dim.y);    
    state.Mode=0;
 }
 
 void renderer::Level::upDate(){
     if(state.Mode==0){
     window.window.setView(view.view_boutique);
     window.window.draw(background.sprite);
     window.window.draw(logo_boutique.sprite);
     window.window.draw(plage_carte_A.sprite);
     window.window.draw(plage_carte_B.sprite);
     window.window.draw(plage_carte_C.sprite);
     window.window.draw(soldat.sprite);
     window.window.draw(chiffre_unite.sprite);
     window.window.draw(chiffre_dizaine.sprite);
     window.window.draw(prix_unite.sprite);
     window.window.draw(prix_dizaine.sprite);
     window.window.draw(prix_centaine.sprite);
     window.window.draw(carte_verso_A.sprite);
     window.window.draw(carte_verso_B.sprite);
     window.window.draw(carte_verso_C.sprite);
     window.window.draw(button_add.sprite);
     window.window.draw(button_minus.sprite);
     window.window.draw(button_ok_A.sprite);
     window.window.draw(button_ok_B.sprite);
     window.window.draw(button_ok_C.sprite);
     window.window.draw(button_ok_compteur.sprite);
     window.window.draw(money.sprite);}
     
     else{
     window.window.setView(view.view_map);
     Background.setScale(1,1);
     window.window.draw(Background);

     window.window.setView(view.view_menu);
     window.window.draw(plage_menu.sprite);
     
     window.window.setView(view.view_minimap);
     Background.setScale(minimap_scale);
     window.window.draw(Background);
     }
     window.window.setView(view.view_plage_commune);
     window.window.draw(plage_commune.sprite);
     
     window.window.display();
     window.window.clear();     
 }