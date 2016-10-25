#include <renderer/Level.h>

#include <renderer/Texture.h>
#include <renderer/View.h>
#include<iostream>

#include "View.h"
#include "Tile.h"
#include "control/Clavier.h"
#include "control/Clock.h"
#include "control/Souris.h"
#include "state/Territory.h"




/////initialisation

//bouton add
sf::Vector2f offset_button_origin(8,10);
sf::Vector2f offset_button_exte(8,5);

//bouton ok
float decalage_carte_ok=5;
float decalage_nombre_ok=15;
float decalage_nombre_ok_1=10;

sf::Vector2f pos_default(0,0);

sf::Vector2f scale_default(1,1);
sf::Vector2f button_ok_scale(1.5f,1.5f);
sf::Vector2f minimap_scale1(0.25f,0.25f);
sf::Vector2f chiffre_scale(2,2);
sf::Vector2f prix_scale(1.6f,1.6f);
sf::Vector2f carte_verso_scale(0.75f,0.75f);

sf::Vector2i plage_commune_dim(235,128);
sf::Vector2i button_ok_dim(64,22);
sf::Vector2i plage_carte_dim(228,76);
enum type{rien,button_ok_type,plage_menu_type,carte_verso_type,soldat_type,plage_commune_type,button_add_type,button_minus_type,chiffre_unite_type,chiffre_dizaine_type,prix_unite_type,prix_dizaine_type,prix_centaine_type,plage_carte_A_type,plage_carte_B_type,plage_carte_C_type,tour_type};
//copier dans listelement et souris

state::Element background("/home/utilisateur/Documents/PLT/res/surfaces/background.png",pos_default,scale_default);
state::Element plage_menu("/home/utilisateur/Documents/PLT/res/autres/plage_menu.png",pos_default,sf::Vector2f(1,1),sf::Vector2i(0,0),sf::Vector2i(358,700),plage_menu_type);
state::Element carte_verso_A("/home/utilisateur/Documents/PLT/res/autres/carte_verso.png",sf::Vector2f(30,350),carte_verso_scale,sf::Vector2i(0,0),sf::Vector2i(261,406),carte_verso_type);
state::Element carte_verso_B("/home/utilisateur/Documents/PLT/res/autres/carte_verso.png",sf::Vector2f(490,350),carte_verso_scale,sf::Vector2i(0,0),sf::Vector2i(261,406),carte_verso_type);
state::Element carte_verso_C("/home/utilisateur/Documents/PLT/res/autres/carte_verso.png",sf::Vector2f(930,350),carte_verso_scale,sf::Vector2i(0,0),sf::Vector2i(261,406),carte_verso_type);
state::Element soldat("/home/utilisateur/Documents/PLT/res/mechants/homme.png",sf::Vector2f(700,110),sf::Vector2f(1.5f,1.5f),sf::Vector2i(0,0),sf::Vector2i(80,80),soldat_type);
state::Element plage_commune("/home/utilisateur/Documents/PLT/res/autres/plage_commune.png",sf::Vector2f(1200-plage_commune_dim.x,0),scale_default,sf::Vector2i(0,0),sf::Vector2i(235,128),plage_commune_type);
state::Element button_add("/home/utilisateur/Documents/PLT/res/autres/boutton_add.png",sf::Vector2f(625,150),sf::Vector2f(2,2),sf::Vector2i(1,0),sf::Vector2i(25,25),button_add_type);
state::Element button_minus("/home/utilisateur/Documents/PLT/res/autres/boutton_add.png",sf::Vector2f(505,150),sf::Vector2f(2,2),sf::Vector2i(0,0),sf::Vector2i(25,25),button_minus_type);
state::Element chiffre_unite("/home/utilisateur/Documents/PLT/res/lettres/alphabet.png",sf::Vector2f(590,160),sf::Vector2f(2,2),sf::Vector2i(9,72),sf::Vector2i(17,17),chiffre_unite_type);
state::Element chiffre_dizaine("/home/utilisateur/Documents/PLT/res/lettres/alphabet.png",sf::Vector2f(chiffre_unite.pos.x-chiffre_unite.getDim().x*chiffre_scale.x,chiffre_unite.pos.y),sf::Vector2f(2,2),sf::Vector2i(9,72),sf::Vector2i(17,17),chiffre_dizaine_type);
state::Element prix_unite("/home/utilisateur/Documents/PLT/res/lettres/alphabet.png",sf::Vector2f(590,110),sf::Vector2f(1.6f,1.6f),sf::Vector2i(9,72),sf::Vector2i(17,17),prix_unite_type);
state::Element prix_dizaine("/home/utilisateur/Documents/PLT/res/lettres/alphabet.png",sf::Vector2f(prix_unite.pos.x-chiffre_unite.getDim().x*prix_scale.x,prix_unite.pos.y),sf::Vector2f(1.6f,1.6f),sf::Vector2i(9,72),sf::Vector2i(17,17),prix_dizaine_type);
state::Element prix_centaine("/home/utilisateur/Documents/PLT/res/lettres/alphabet.png",sf::Vector2f(prix_unite.pos.x-chiffre_unite.getDim().x*prix_scale.x*2,prix_unite.pos.y),sf::Vector2f(1.6f,1.6f),sf::Vector2i(9,72),sf::Vector2i(17,17),prix_centaine_type);
state::Element button_ok_A("/home/utilisateur/Documents/PLT/res/autres/boutton_ok.png",sf::Vector2f(carte_verso_A.pos.x+carte_verso_A.getDim().x/2*carte_verso_scale.x-button_ok_dim.x*button_ok_scale.x/2,carte_verso_A.pos.y+carte_verso_A.getDim().y*carte_verso_scale.y+decalage_carte_ok),button_ok_scale,sf::Vector2i(0,0),sf::Vector2i(64,22),button_ok_type);
state::Element button_ok_B("/home/utilisateur/Documents/PLT/res/autres/boutton_ok.png",sf::Vector2f(carte_verso_B.pos.x+carte_verso_A.getDim().x/2*carte_verso_scale.x-button_ok_dim.x*button_ok_scale.x/2,carte_verso_B.pos.y+carte_verso_A.getDim().y*carte_verso_scale.y+decalage_carte_ok),button_ok_scale,sf::Vector2i(0,0),sf::Vector2i(64,22),button_ok_type);
state::Element button_ok_C("/home/utilisateur/Documents/PLT/res/autres/boutton_ok.png",sf::Vector2f(carte_verso_C.pos.x+carte_verso_A.getDim().x/2*carte_verso_scale.x-button_ok_dim.x*button_ok_scale.x/2,carte_verso_C.pos.y+carte_verso_A.getDim().y*carte_verso_scale.y+decalage_carte_ok),button_ok_scale,sf::Vector2i(0,0),sf::Vector2i(64,22),button_ok_type);
state::Element button_ok_compteur("/home/utilisateur/Documents/PLT/res/autres/boutton_ok.png",sf::Vector2f(chiffre_unite.pos.x-button_ok_dim.x*button_ok_scale.x/2,chiffre_unite.pos.y+chiffre_unite.getDim().y*chiffre_scale.y+decalage_nombre_ok),button_ok_scale,sf::Vector2i(0,0),sf::Vector2i(64,22),button_ok_type);
state::Element logo_boutique("/home/utilisateur/Documents/PLT/res/autres/logo.png",pos_default,scale_default);
state::Element money("/home/utilisateur/Documents/PLT/res/autres/money.png",sf::Vector2f(630,100),sf::Vector2f(0.75f,0.75f));
state::Element plage_carte_A("/home/utilisateur/Documents/PLT/res/autres/plage_carte.png",sf::Vector2f(carte_verso_A.pos.x+carte_verso_A.getDim().x/2*carte_verso_scale.x-plage_carte_dim.x/2,carte_verso_A.pos.y-plage_carte_dim.y),scale_default,sf::Vector2i(0,0),sf::Vector2i(228,76),plage_carte_A_type);
state::Element plage_carte_B("/home/utilisateur/Documents/PLT/res/autres/plage_carte.png",sf::Vector2f(carte_verso_B.pos.x+carte_verso_A.getDim().x/2*carte_verso_scale.x-plage_carte_dim.x/2,carte_verso_B.pos.y-plage_carte_dim.y),scale_default,sf::Vector2i(0,0),sf::Vector2i(228,76),plage_carte_B_type);
state::Element plage_carte_C("/home/utilisateur/Documents/PLT/res/autres/plage_carte.png",sf::Vector2f(carte_verso_C.pos.x+carte_verso_A.getDim().x/2*carte_verso_scale.x-plage_carte_dim.x/2,carte_verso_C.pos.y-plage_carte_dim.y),scale_default,sf::Vector2i(0,0),sf::Vector2i(228,76),plage_carte_C_type);
state::Element tour("/home/utilisateur/Documents/PLT/res/tours/tours.png",pos_default,sf::Vector2f(2,2),sf::Vector2i(0,0),sf::Vector2i(68,68),tour_type);


state::Element button_add_1("/home/utilisateur/Documents/PLT/res/autres/boutton_add.png",sf::Vector2f(190,405),sf::Vector2f(2,2),sf::Vector2i(1,0),sf::Vector2i(25,25),button_add_type);
state::Element button_minus_1("/home/utilisateur/Documents/PLT/res/autres/boutton_add.png",sf::Vector2f(80,405),sf::Vector2f(2,2),sf::Vector2i(0,0),sf::Vector2i(25,25),button_minus_type);
state::Element chiffre_unite_1("/home/utilisateur/Documents/PLT/res/lettres/alphabet.png",sf::Vector2f(160,415),sf::Vector2f(2,2),sf::Vector2i(9,72),sf::Vector2i(17,17),chiffre_unite_type);
state::Element chiffre_dizaine_1("/home/utilisateur/Documents/PLT/res/lettres/alphabet.png",sf::Vector2f(chiffre_unite_1.pos.x-chiffre_unite_1.getDim().x*chiffre_scale.x,chiffre_unite_1.pos.y),sf::Vector2f(2,2),sf::Vector2i(9,72),sf::Vector2i(17,17),chiffre_dizaine_type);
state::Element button_ok_compteur_1("/home/utilisateur/Documents/PLT/res/autres/boutton_ok.png",sf::Vector2f(chiffre_unite_1.pos.x-button_ok_dim.x*button_ok_scale.x/2,chiffre_unite_1.pos.y+chiffre_unite.getDim().y*chiffre_scale.y+decalage_nombre_ok_1),button_ok_scale,sf::Vector2i(0,0),sf::Vector2i(64,22),button_ok_type);
sf::String text("yo");


renderer::View view;
control::Clavier clavier;
control::Clock clock_soldat;
control::Souris souris;
state::ListElement list_boutique;
state::ListElement list_map;
state::ListElement list_plage_menu;

state::ListElement list_minimap;
state::ListElement list_plage_commmune;
state::ListTerritory list_territoire;





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
std::string tile_texture_path="/home/utilisateur/Documents/PLT/res/surfaces/gravier_herbe.png";
sf::Vector2u tile_dim(28,28);

 renderer::Level::Level (){
     
 }
 renderer::Level::~Level (){
     
 }
 
 void renderer::Level::level_init(){
     
     window.Window_init();
     view.View_init(state);
     plage_commune.init();
     list_boutique.add_element(background);
     list_boutique.add_element(money);
     list_boutique.add_element(plage_carte_A);
     list_boutique.add_element(plage_carte_B);
     list_boutique.add_element(plage_carte_C);
     list_boutique.add_element(logo_boutique);
     list_boutique.add_element(carte_verso_A);
     list_boutique.add_element(carte_verso_B);
     list_boutique.add_element(carte_verso_C);
     list_boutique.add_element(button_add);
     list_boutique.add_element(button_minus);
     list_boutique.add_element(button_ok_A);
     list_boutique.add_element(button_ok_B);
     list_boutique.add_element(button_ok_C);
     list_boutique.add_element(button_ok_compteur);
     list_boutique.add_element(chiffre_unite);
     list_boutique.add_element(chiffre_dizaine);
     list_boutique.add_element(prix_unite);
     list_boutique.add_element(prix_dizaine);
     list_boutique.add_element(prix_centaine);
     soldat.init();
     list_boutique.init();
   
     list_boutique.upDate(souris,window.window,view.view_boutique,list_territoire);
    
    /////////////////////Mode 1//////////////////////////////
    /*button_add.pos=sf::Vector2f(190,405);
     button_minus.pos=sf::Vector2f(80,405);
     chiffre_unite.pos=sf::Vector2f(160,415);
     chiffre_dizaine.pos=sf::Vector2f(chiffre_unite.pos.x-chiffre_unite.getDim().x*chiffre_scale.x,chiffre_unite.pos.y);
    */ 
    list_plage_menu.add_element(plage_menu);
    list_plage_menu.add_element(button_add_1);
    list_plage_menu.add_element(button_minus_1);
    list_plage_menu.add_element(chiffre_unite_1);
    list_plage_menu.add_element(chiffre_dizaine_1);
    list_plage_menu.add_element(button_ok_compteur_1);
   
    list_plage_menu.init();
   
    
    tile.convert(level_1_path);
    Background.load(tile_texture_path,tile_dim,tile.tiles,tile.image_dim.x,tile.image_dim.y);    
    
    state.nb_territory=tile.size;
    
    for(int i=0;i<state.nb_territory;i++){
        
        state::Territory territory;
        state::Element tour("/home/utilisateur/Documents/PLT/res/tours/tours.png",tile.pos_tour[i],sf::Vector2f(2,2),sf::Vector2i(0,0),sf::Vector2i(68,68),tour_type);
        territory.tour=tour;
        
        list_territoire.list_territory.push_back(territory);
        
    }
     list_territoire.init();
     
 }
 
 void renderer::Level::upDate(){
     
     
     
     clavier.gestion_clavier(state);
     view.View_UpDate(state);
     
     souris.gestion_souris(window.window);
     if(*(state.Mode)==0){
        
         soldat.sprite.setTextureRect(sf::IntRect(soldat.getAnim().x*soldat.getDim().x,soldat.getAnim().y*soldat.getDim().y,soldat.getDim().x,soldat.getDim().y));
         clock_soldat.action(soldat);
         if(*(souris.Update)==1)
         {
             
         list_boutique.upDate(souris,window.window,view.view_boutique,list_territoire);
        list_plage_menu.upDate(souris,window.window,view.view_menu,list_territoire);
         
           delete souris.Update;
      souris.Update=new int;
      *(souris.Update)=0;}
     
     window.window.setView(view.view_boutique);
     
     list_boutique.draw(window.window,list_territoire,state);
    
     window.window.draw(soldat.sprite);
     }
     
     if(*(state.Mode)==1)
     {
     if(*(souris.Update)==1)
         {
         
             list_territoire.Update(souris,window.window,view.view_map);
         list_plage_menu.upDate(souris,window.window,view.view_menu,list_territoire);
         
           delete souris.Update;
      souris.Update=new int;
      *(souris.Update)=0;}
         
   
    
         
         
     window.window.setView(view.view_map);
     Background.setScale(1,1);
     window.window.draw(Background);
     list_territoire.draw(window.window);


     window.window.setView(view.view_menu);
     list_plage_menu.draw(window.window,list_territoire,state);
     
     
     window.window.setView(view.view_minimap);
     Background.setScale(minimap_scale1);
     window.window.draw(Background);
     window.window.draw(view.rectangle);
     }
     window.window.setView(view.view_plage_commune);
     window.window.draw(plage_commune.sprite);
     
     window.window.display();
     window.window.clear();     
 }