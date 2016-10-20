/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <renderer/Level.h>

#include <renderer/Texture.h>
#include <renderer/View.h>
#include<iostream>

#include "View.h"
#include "Tile.h"



/////initialisation

////All the time 
//plage commune
state::Element plage_commune;
renderer::Texture plage_commune_texture;
sf::Sprite sprite_plage_commune;
std::string plage_commune_path="/home/utilisateur/Documents/PLT/res/autres/plage_commune.png";
int plage_commune_width=235;
float plage_commune_pos_Y=0;
sf::Vector2f plage_commune_dim(235,128);
sf::View view_plage_commune;




//bouton add
state::Element button_add;
state::Element button_minus;
renderer::Texture button_texture;
sf::Vector2i anim_button_add(1,0);
sf::Vector2i anim_button_minus(0,0);
std::string button_path="/home/utilisateur/Documents/PLT/res/autres/boutton_add.png";
sf::Vector2f button_add_pos(625,150);
sf::Vector2f button_minus_pos(505,150);
sf::Vector2f button_dim(25,25);
sf::Vector2f button_scale(2,2);
sf::Vector2f offset_button_origin(8,10);
sf::Vector2f offset_button_exte(8,5);

//bouton ok
state::Element button_ok_A;
state::Element button_ok_B;
state::Element button_ok_C;
state::Element button_ok_compteur;

renderer::Texture button_ok_texture;
sf::Vector2i anim_button_ok_A(0,0);
sf::Vector2i anim_button_ok_B(0,0);
sf::Vector2i anim_button_ok_C(0,0);
sf::Vector2i anim_button_ok_compteur(0,0);
std::string button_ok_path="/home/utilisateur/Documents/PLT/res/autres/boutton_ok.png";
sf::Vector2f button_ok_scale(1.5f,1.5f);
sf::Vector2f button_ok_dim(64,22);
float decalage_carte_ok=5;
float decalage_nombre_ok=15;


//carte verso
state::Element carte_verso_B;
state::Element carte_verso_C;
sf::Vector2f carte_A_pos(30,350);
sf::Vector2f carte_B_pos(490,350);
sf::Vector2f carte_C_pos(930,350);
std::string carte_verso_path="/home/utilisateur/Documents/PLT/res/autres/carte_verso.png";
sf::Vector2f carte_verso_scale(0.75f,0.75f);
sf::Vector2f carte_verso_dim(261,406);
state::Element carte_verso_A("/home/utilisateur/Documents/PLT/res/autres/carte_verso.png",sf::Vector2f(30,350),sf::Vector2f(0.75f,0.75f));

//chiffre
state::Element chiffre_unite;
state::Element chiffre_dizaine;
state::Element prix_unite;
state::Element prix_dizaine;
state::Element prix_centaine;
renderer::Texture alphabet_texture;
sf::Vector2i anim_chiffre_unite(9,72);
sf::Vector2i anim_chiffre_dizaine(9,72);
sf::Vector2i anim_prix_unite(9,72);
sf::Vector2f chiffre_dim(17,17);
sf::Vector2f chiffre_scale(2,2);
sf::Vector2f prix_scale(1.6f,1.6f);
sf::Vector2f chiffre_nb_soldat_unite_pos(590,160);
sf::Vector2f prix_nb_soldat_unite_pos(590,110);
std::string chiffre_path="/home/utilisateur/Documents/PLT/res/lettres/alphabet.png";
int ajustement_sprite_chiffre=2;

//dragon
int speed=25;
renderer::Texture perso;
sf::Sprite sprite_perso;
enum Dir{Down,Left,Right,Up};
sf::Vector2i anim_dragon(0,Down);
bool Update_dragon=false;
sf::Vector2f perso_pos(600,350);

//logo boutique
state::Element logo_boutique;
renderer::Texture logo_boutique_texture;
std::string logo_boutique_path="/home/utilisateur/Documents/PLT/res/autres/logo.png";

//money
state::Element money;
renderer::Texture money_texture;
std::string money_path="/home/utilisateur/Documents/PLT/res/autres/money.png";
sf::Vector2f money_scale(0.75f,0.75f);
sf::Vector2f pos_money(630,100);

//plage carte
state::Element plage_carte_A;
state::Element plage_carte_B;
state::Element plage_carte_C;

renderer::Texture plage_carte_texture;
std::string plage_carte_path="/home/utilisateur/Documents/PLT/res/autres/plage_carte.png";
sf::Vector2f  select_plage_carte_A(0,0);
sf::Vector2f  select_plage_carte_B(0,1);
sf::Vector2f  select_plage_carte_C(0,2);
sf::Vector2f plage_carte_dim(228,76);


//soldat
state::Element soldat;
renderer::Texture soldat_texture;
sf::Vector2i anim_soldat(0,0);
sf::Vector2f homme_scale(1.5f,1.5f);
std::string homme_path="/home/utilisateur/Documents/PLT/res/mechants/homme.png";
sf::Vector2f soldat_pos(700,110);
sf::Vector2f soldat_dim(80,80);

//view
sf::View view_boutique;

////Mode 1
//minimap
sf::Vector2f minimap_scale(0.25f,0.25f);

//plage menu

renderer::Texture plage_menu_texture;
sf::Vector2i anim_plage_menu(1,0);
sf::Vector2i plage_menu_dim(358,700);


//tour 
state::Element tour;
renderer::Texture tour_texture;
std::string tour_path="/home/utilisateur/Documents/PLT/res/tours/tours.png";
sf::Vector2i tour_dim(68,68);
sf::Vector2f tour_scale(2,2);

///////variables composées
//bouton ok
sf::Vector2f button_ok_A_pos(carte_A_pos.x+carte_verso_dim.x/2*carte_verso_scale.x-button_ok_dim.x*button_ok_scale.x/2,carte_A_pos.y+carte_verso_dim.y*carte_verso_scale.y+decalage_carte_ok);
sf::Vector2f button_ok_B_pos(carte_B_pos.x+carte_verso_dim.x/2*carte_verso_scale.x-button_ok_dim.x*button_ok_scale.x/2,carte_B_pos.y+carte_verso_dim.y*carte_verso_scale.y+decalage_carte_ok);
sf::Vector2f button_ok_C_pos(carte_C_pos.x+carte_verso_dim.x/2*carte_verso_scale.x-button_ok_dim.x*button_ok_scale.x/2,carte_C_pos.y+carte_verso_dim.y*carte_verso_scale.y+decalage_carte_ok);
sf::Vector2f button_ok_compteur_pos(chiffre_nb_soldat_unite_pos.x-button_ok_dim.x*button_ok_scale.x/2,chiffre_nb_soldat_unite_pos.y+chiffre_dim.y*chiffre_scale.y+decalage_nombre_ok);

//chiffre
sf::Vector2f chiffre_nb_soldat_dizaine_pos(chiffre_nb_soldat_unite_pos.x-chiffre_dim.x*chiffre_scale.x,chiffre_nb_soldat_unite_pos.y);
sf::Vector2f prix_nb_soldat_dizaine_pos(prix_nb_soldat_unite_pos.x-chiffre_dim.x*prix_scale.x,prix_nb_soldat_unite_pos.y);
sf::Vector2f prix_nb_soldat_centaine_pos(prix_nb_soldat_unite_pos.x-chiffre_dim.x*prix_scale.x*2,prix_nb_soldat_unite_pos.y);

//plage carte
sf::Vector2f plage_carte_A_pos(carte_A_pos.x+carte_verso_dim.x/2*carte_verso_scale.x-plage_carte_dim.x/2,carte_A_pos.y-plage_carte_dim.y);
sf::Vector2f plage_carte_B_pos(carte_B_pos.x+carte_verso_dim.x/2*carte_verso_scale.x-plage_carte_dim.x/2,carte_B_pos.y-plage_carte_dim.y);
sf::Vector2f plage_carte_C_pos(carte_C_pos.x+carte_verso_dim.x/2*carte_verso_scale.x-plage_carte_dim.x/2,carte_C_pos.y-plage_carte_dim.y);


//All the time
//plage commune
sf::Vector2f plage_commune_pos(1200-plage_commune_width,plage_commune_pos_Y);
sf::Vector2f pos_default(0,0);
sf::Vector2f scale_default(1,1);

renderer::Texture carte_verso_texture;

state::Element background("/home/utilisateur/Documents/PLT/res/surfaces/background.png",pos_default,scale_default);
state::Element plage_menu("/home/utilisateur/Documents/PLT/res/autres/plage_menu.png",pos_default,sf::Vector2f(3.3f,1));
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
      
     plage_commune.sprite=plage_commune_texture.load_texture(plage_commune_path,plage_commune_pos,sf::Vector2f(1,1));
    /////////////////////////////////Mode 0 ///////////////////////////////////////////
     
    background.init();
    
    money.sprite=money_texture.load_texture(money_path,pos_money,money_scale);
    
    plage_carte_A.sprite=plage_carte_texture.load_texture(plage_carte_path,plage_carte_A_pos,sf::Vector2f(1,1));
    plage_carte_B.sprite=plage_carte_texture.load_texture(plage_carte_path,plage_carte_B_pos,sf::Vector2f(1,1));
    plage_carte_C.sprite=plage_carte_texture.load_texture(plage_carte_path,plage_carte_C_pos,sf::Vector2f(1,1));
    
    plage_carte_A.sprite.setTextureRect(sf::IntRect(plage_carte_dim.x*select_plage_carte_A.x,plage_carte_dim.y*select_plage_carte_A.y,plage_carte_dim.x,plage_carte_dim.y));
    plage_carte_B.sprite.setTextureRect(sf::IntRect(plage_carte_dim.x*select_plage_carte_B.x,select_plage_carte_B.y*plage_carte_dim.y,plage_carte_dim.x,plage_carte_dim.y));;
    plage_carte_C.sprite.setTextureRect(sf::IntRect(plage_carte_dim.x*select_plage_carte_C.x,select_plage_carte_C.y*plage_carte_dim.y,plage_carte_dim.x,plage_carte_dim.y));;
       
    logo_boutique.sprite=logo_boutique_texture.load_texture(logo_boutique_path,sf::Vector2f(0,0),sf::Vector2f(1,1));
    
    carte_verso_A.init();
    carte_verso_B.sprite=carte_verso_texture.load_texture(carte_verso_path,carte_B_pos,carte_verso_scale);
    carte_verso_C.sprite=carte_verso_texture.load_texture(carte_verso_path,carte_C_pos,carte_verso_scale);
    
    button_add.sprite=button_texture.load_texture(button_path,button_add_pos,button_scale);
    button_minus.sprite=button_texture.load_texture(button_path,button_minus_pos,button_scale);

    button_ok_A.sprite=button_ok_texture.load_texture(button_ok_path,button_ok_A_pos,button_ok_scale);
    button_ok_B.sprite=button_ok_texture.load_texture(button_ok_path,button_ok_B_pos,button_ok_scale);
    button_ok_C.sprite=button_ok_texture.load_texture(button_ok_path,button_ok_C_pos,button_ok_scale);
    button_ok_compteur.sprite=button_ok_texture.load_texture(button_ok_path,button_ok_compteur_pos,button_ok_scale);
   
    soldat.sprite=soldat_texture.load_texture(homme_path,soldat_pos,homme_scale);
    
    chiffre_unite.sprite=alphabet_texture.load_texture(chiffre_path,chiffre_nb_soldat_unite_pos,chiffre_scale);
    chiffre_dizaine.sprite=alphabet_texture.load_texture(chiffre_path,chiffre_nb_soldat_dizaine_pos,chiffre_scale);
    prix_unite.sprite=alphabet_texture.load_texture(chiffre_path,prix_nb_soldat_unite_pos,prix_scale);
    prix_dizaine.sprite=alphabet_texture.load_texture(chiffre_path,prix_nb_soldat_dizaine_pos,prix_scale);
    prix_centaine.sprite=alphabet_texture.load_texture(chiffre_path,prix_nb_soldat_centaine_pos,prix_scale);
   
    prix_unite.sprite.setColor(sf::Color::Green);
    prix_dizaine.sprite.setColor(sf::Color::Green);
    prix_centaine.sprite.setColor(sf::Color::Green);
    
    /////////////////////Mode 1//////////////////////////////
    
    plage_menu.init();
    tour.sprite=tour_texture.load_texture(tour_path,sf::Vector2f(0,0),tour_scale);
    //if (!tour.loadFromFile(tour_path, sf::IntRect(0,0,tour_dim.x,tour_dim.y)))
    

    // on définit le niveau à l'aide de numéro de tuiles
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
    
      //sf::Vector2u image_dim(tile.image.getSize());
    
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