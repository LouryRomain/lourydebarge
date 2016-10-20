#ifdef SFML_STATIC 
#endif 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <state.h>
#include <renderer/Texture.h>

#include "renderer/Tile.h"
#include "renderer/Window.h"
#include "renderer/Level.h"





/*class TileMap : public sf::Drawable, public sf::Transformable
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
#pragma region variables

/////initialisation

////All the time 
//plage commune
renderer::Texture plage_commune;
sf::Sprite sprite_plage_commune;
std::string plage_commune_path="/home/utilisateur/Documents/PLT/res/autres/plage_commune.png";
int plage_commune_width=235;
float plage_commune_pos_Y=0;
sf::Vector2f plage_commune_dim(235,128);
sf::View view_plage_commune;
sf::FloatRect view_plage_commune_set(0.804f,0,1,0.18f);

//state
state::State game;

//window
/*sf::RenderWindow window;
int window_width=1200;
int window_heigth=700;
sf::Vector2i pos_window(0,0);
int frame_fps_limit=60;
std::string window_title="Gang War";

//gestion clavier
bool Update_boutique=true;

/////Mode0
//bacground
//renderer::Texture background;
//sf::Sprite sprite_background;
//std::string background_path="/home/utilisateur/Documents/PLT/res/surfaces/background.png";

//bouton add
renderer::Texture button;
sf::Sprite sprite_button_add;
sf::Sprite sprite_button_minus;
sf::Vector2i anim_button_add(1,0);
sf::Vector2i anim_button_minus(0,0);
std::string button_path="/home/utilisateur/Documents/PLT/res/autres/boutton_add.png";
sf::Vector2f button_add_pos(625,150);
sf::Vector2f button_minus_pos(505,150);
sf::Vector2f button_dim(25,25);
float button_scale=2;
sf::Vector2f offset_button_origin(8,10);
sf::Vector2f offset_button_exte(8,5);

//bouton ok
renderer::Texture button_ok;
sf::Sprite sprite_button_ok_A;
sf::Sprite sprite_button_ok_B;
sf::Sprite sprite_button_ok_C;
sf::Sprite sprite_button_ok_compteur;
sf::Vector2i anim_button_ok_A(0,0);
sf::Vector2i anim_button_ok_B(0,0);
sf::Vector2i anim_button_ok_C(0,0);
sf::Vector2i anim_button_ok_compteur(0,0);
std::string button_ok_path="/home/utilisateur/Documents/PLT/res/autres/boutton_ok.png";
float button_ok_scale=1.5f;
sf::Vector2f button_ok_dim(64,22);
float decalage_carte_ok=5;
float decalage_nombre_ok=15;


//carte verso
renderer::Texture carte_verso;
sf::Sprite sprite_carte_verso_A;
sf::Sprite sprite_carte_verso_B;
sf::Sprite sprite_carte_verso_C;
sf::Vector2f carte_A_pos(30,350);
sf::Vector2f carte_B_pos(490,350);
sf::Vector2f carte_C_pos(930,350);
std::string carte_verso_path="/home/utilisateur/Documents/PLT/res/autres/carte_verso.png";
float carte_verso_scale=0.75f;
sf::Vector2f carte_verso_dim(261,406);

//chiffre
renderer::Texture alphabet;
sf::Sprite sprite_chiffre_unite;
sf::Sprite sprite_chiffre_dizaine;
sf::Sprite sprite_prix_unite;
sf::Sprite sprite_prix_dizaine;
sf::Sprite sprite_prix_centaine;
sf::Vector2i anim_chiffre_unite(9,72);
sf::Vector2i anim_chiffre_dizaine(9,72);
sf::Vector2i anim_prix_unite(9,72);
sf::Vector2f chiffre_dim(17,17);
float chiffre_scale=2;
float prix_scale=1.6f;
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
sf::Vector2f perso_pos(window_width/2,window_heigth/2);

//logo boutique
renderer::Texture logo_boutique;
sf::Sprite sprite_logo_boutique;
std::string logo_boutique_path="/home/utilisateur/Documents/PLT/res/autres/logo.png";

//money
renderer::Texture money;
sf::Sprite sprite_money;
std::string money_path="/home/utilisateur/Documents/PLT/res/autres/money.png";
float money_scale=0.75f;
sf::Vector2f pos_money(630,100);

//plage carte
renderer::Texture plage_carte;
sf::Sprite sprite_plage_carte_A;
sf::Sprite sprite_plage_carte_B;
sf::Sprite sprite_plage_carte_C;
std::string plage_carte_path="/home/utilisateur/Documents/PLT/res/autres/plage_carte.png";
sf::Vector2f  select_plage_carte_A(0,0);
sf::Vector2f  select_plage_carte_B(0,1);
sf::Vector2f  select_plage_carte_C(0,2);
sf::Vector2f plage_carte_dim(228,76);


//soldat
renderer::Texture soldat;
sf::Sprite sprite_soldat;
sf::Vector2i anim_soldat(0,0);
float homme_scale=1.5f;
std::string homme_path="/home/utilisateur/Documents/PLT/res/mechants/homme.png";
sf::Vector2f soldat_pos(700,110);
sf::Vector2f soldat_dim(80,80);
int Udpadated_clock_soldat=100;

//souris
sf::Vector2i positionSouris;

//view
sf::View view_boutique;

////Mode 1

//minimap
sf::RectangleShape rectangle(sf::Vector2f(window_width*0.25,window_heigth*0.25f));
sf::View view_minimap;
int thickness_rectangle=3;
sf::Vector2f minimap_scale(0.25f,0.25f);

//plage menu
renderer::Texture plage_menu;
sf::Sprite sprite_plage_menu;
sf::Vector2i anim_plage_menu(1,0);
std::string plage_menu_path="/home/utilisateur/Documents/PLT/res/autres/plage_menu.png";
sf::Vector2i plage_menu_dim(358,700);
sf::Vector2f plage_menu_scale(3.3f,1);
sf::FloatRect view_menu_set(0,0,0.3f,1);


//scrolling
sf::View view_menu;
sf::View view_map;
sf::Vector2f position(window_width/2,window_heigth/2);


//tile


std::string level_1_path="/home/utilisateur/Documents/PLT/res/autres/level1.png";
std::string tile_texture_path="/home/utilisateur/Documents/PLT/res/surfaces/cailloux_gravier.png";
sf::Vector2u tile_dim(28,28);
TileMap Background;

//tour 
renderer::Texture tour;
sf::Sprite sprite_tour;
std::string tour_path="/home/utilisateur/Documents/PLT/res/tours/tours.png";
sf::Vector2i tour_dim(68,68);
sf::Vector2f tour_scale(2,2);





///////variables composées


//Mode 0
//bouton add
sf::Vector2f mouse_add_origin(button_add_pos.x+offset_button_origin.x,button_add_pos.y+offset_button_origin.y);
sf::Vector2f mouse_add_exte(button_add_pos.x+button_dim.x*button_scale-offset_button_exte.x,button_add_pos.y+button_dim.y*button_scale-offset_button_origin.y);
sf::Vector2f mouse_minus_origin(button_minus_pos.x+offset_button_exte.x,button_minus_pos.y+offset_button_origin.y);
sf::Vector2f mouse_minus_exte(button_minus_pos.x+button_dim.x*button_scale-offset_button_origin.x,button_minus_pos.y+button_dim.y*button_scale-offset_button_exte.y);

//bouton ok
sf::Vector2f button_ok_A_pos(carte_A_pos.x+carte_verso_dim.x/2*carte_verso_scale-button_ok_dim.x*button_ok_scale/2,carte_A_pos.y+carte_verso_dim.y*carte_verso_scale+decalage_carte_ok);
sf::Vector2f button_ok_B_pos(carte_B_pos.x+carte_verso_dim.x/2*carte_verso_scale-button_ok_dim.x*button_ok_scale/2,carte_B_pos.y+carte_verso_dim.y*carte_verso_scale+decalage_carte_ok);
sf::Vector2f button_ok_C_pos(carte_C_pos.x+carte_verso_dim.x/2*carte_verso_scale-button_ok_dim.x*button_ok_scale/2,carte_C_pos.y+carte_verso_dim.y*carte_verso_scale+decalage_carte_ok);
sf::Vector2f button_ok_compteur_pos(chiffre_nb_soldat_unite_pos.x-button_ok_dim.x*button_ok_scale/2,chiffre_nb_soldat_unite_pos.y+chiffre_dim.y*chiffre_scale+decalage_nombre_ok);
sf::Vector2f mouse_limit_button_ok_A(button_ok_A_pos.x+button_ok_dim.x*button_ok_scale,button_ok_A_pos.y+button_ok_dim.y*button_ok_scale);
sf::Vector2f mouse_limit_button_ok_B(button_ok_B_pos.x+button_ok_dim.x*button_ok_scale,button_ok_B_pos.y+button_ok_dim.y*button_ok_scale);
sf::Vector2f mouse_limit_button_ok_C(button_ok_C_pos.x+button_ok_dim.x*button_ok_scale,button_ok_C_pos.y+button_ok_dim.y*button_ok_scale);
sf::Vector2f mouse_limit_button_ok_compteur(button_ok_compteur_pos.x+button_ok_dim.x*button_ok_scale,button_ok_compteur_pos.y+button_ok_dim.y*button_ok_scale);


//chiffre
sf::Vector2f chiffre_nb_soldat_dizaine_pos(chiffre_nb_soldat_unite_pos.x-chiffre_dim.x*chiffre_scale,chiffre_nb_soldat_unite_pos.y);
sf::Vector2f prix_nb_soldat_dizaine_pos(prix_nb_soldat_unite_pos.x-chiffre_dim.x*prix_scale,prix_nb_soldat_unite_pos.y);
sf::Vector2f prix_nb_soldat_centaine_pos(prix_nb_soldat_unite_pos.x-chiffre_dim.x*prix_scale*2,prix_nb_soldat_unite_pos.y);

//plage carte
sf::Vector2f plage_carte_A_pos(carte_A_pos.x+carte_verso_dim.x/2*carte_verso_scale-plage_carte_dim.x/2,carte_A_pos.y-plage_carte_dim.y);
sf::Vector2f plage_carte_B_pos(carte_B_pos.x+carte_verso_dim.x/2*carte_verso_scale-plage_carte_dim.x/2,carte_B_pos.y-plage_carte_dim.y);
sf::Vector2f plage_carte_C_pos(carte_C_pos.x+carte_verso_dim.x/2*carte_verso_scale-plage_carte_dim.x/2,carte_C_pos.y-plage_carte_dim.y);

//Mode 1




//All the time
//plage commune
sf::Vector2f plage_commune_pos(window_width-plage_commune_width,plage_commune_pos_Y);

#pragma endregion variables

#pragma region prototype

void gestion_clavier();
void gestion_souris();
const int* convert_paint_tab(sf::Image image);


#pragma endregion prototype




/*
int main()
{
    //All the time 
    window.create(sf::VideoMode(window_width,window_heigth),window_title);
    window.setPosition(pos_window);
    window.setFramerateLimit(frame_fps_limit);
    
    sprite_perso.setPosition(perso_pos);
     
     sprite_plage_commune=plage_commune.load_texture(plage_commune_path,plage_commune_pos);
    
    
     
    /////////////////////////////////Mode 0 ///////////////////////////////////////////
     sf::Clock time_soldat;
    
    sprite_background=background.load_texture(background_path,sf::Vector2f(0,0));
    
    sprite_money=money.load_texture(money_path,pos_money);
    sprite_money.setScale(money_scale,money_scale);
    
   
    
     sprite_plage_carte_A=plage_carte.load_texture(plage_carte_path,plage_carte_A_pos);
     sprite_plage_carte_B=plage_carte.load_texture(plage_carte_path,plage_carte_B_pos);
     sprite_plage_carte_C=plage_carte.load_texture(plage_carte_path,plage_carte_C_pos);
    
    sprite_plage_carte_A.setTextureRect(sf::IntRect(plage_carte_dim.x*select_plage_carte_A.x,plage_carte_dim.y*select_plage_carte_A.y,plage_carte_dim.x,plage_carte_dim.y));
    sprite_plage_carte_B.setTextureRect(sf::IntRect(plage_carte_dim.x*select_plage_carte_B.x,select_plage_carte_B.y*plage_carte_dim.y,plage_carte_dim.x,plage_carte_dim.y));;
    sprite_plage_carte_C.setTextureRect(sf::IntRect(plage_carte_dim.x*select_plage_carte_C.x,select_plage_carte_C.y*plage_carte_dim.y,plage_carte_dim.x,plage_carte_dim.y));;
       
   
    sprite_logo_boutique=logo_boutique.load_texture(logo_boutique_path,sf::Vector2f(0,0));
    
    
    
     sprite_carte_verso_A=carte_verso.load_texture(carte_verso_path,carte_A_pos);
      sprite_carte_verso_B=carte_verso.load_texture(carte_verso_path,carte_B_pos);
       sprite_carte_verso_C=carte_verso.load_texture(carte_verso_path,carte_C_pos);
    
    sprite_carte_verso_A.scale(carte_verso_scale,carte_verso_scale);
    sprite_carte_verso_B.scale(carte_verso_scale,carte_verso_scale);
    sprite_carte_verso_C.scale(carte_verso_scale,carte_verso_scale);
    
    sprite_button_add=button.load_texture(button_path,button_add_pos);
      sprite_button_minus=button.load_texture(button_path,button_minus_pos);
      sprite_button_add.scale(button_scale,button_scale);
    sprite_button_minus.scale(button_scale,button_scale);
  
    sprite_button_ok_A=button_ok.load_texture(button_ok_path,button_ok_A_pos);
    sprite_button_ok_B=button_ok.load_texture(button_ok_path,button_ok_B_pos);
    sprite_button_ok_C=button_ok.load_texture(button_ok_path,button_ok_C_pos);
    sprite_button_ok_compteur=button_ok.load_texture(button_ok_path,button_ok_compteur_pos);
    
    
    sprite_button_ok_A.scale(1.5f,1.5f);
    sprite_button_ok_B.scale(button_ok_scale,button_ok_scale);
    sprite_button_ok_C.scale(button_ok_scale,button_ok_scale);
    sprite_button_ok_compteur.scale(button_ok_scale,button_ok_scale);
    
    sprite_soldat=soldat.load_texture(homme_path,soldat_pos);
    sprite_soldat.setScale(homme_scale,homme_scale);
    
    sprite_chiffre_unite=alphabet.load_texture(chiffre_path,chiffre_nb_soldat_unite_pos);
    sprite_chiffre_dizaine=alphabet.load_texture(chiffre_path,chiffre_nb_soldat_dizaine_pos);
    sprite_prix_unite=alphabet.load_texture(chiffre_path,prix_nb_soldat_unite_pos);
    sprite_prix_dizaine=alphabet.load_texture(chiffre_path,prix_nb_soldat_dizaine_pos);
    sprite_prix_centaine=alphabet.load_texture(chiffre_path,prix_nb_soldat_centaine_pos);
    
    sprite_chiffre_unite.setScale(chiffre_scale,chiffre_scale);
   
    
    sprite_chiffre_dizaine.setScale(chiffre_scale,chiffre_scale);
    
    
    sprite_prix_unite.setScale(prix_scale,prix_scale);
    sprite_prix_unite.setColor(sf::Color::Green);
   
    
    sprite_prix_dizaine.setScale(prix_scale,prix_scale);
    sprite_prix_dizaine.setColor(sf::Color::Green);
    
    
    sprite_prix_centaine.setScale(prix_scale,prix_scale);
    sprite_prix_centaine.setColor(sf::Color::Green);
    
     
    
    /////////////////////Mode 1//////////////////////////////
    
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(thickness_rectangle);
    
    
    sprite_plage_menu=plage_menu.load_texture(plage_menu_path,sf::Vector2f(0,0));
    
    sprite_plage_menu.setScale(plage_menu_scale);
    
    sprite_tour=tour.load_texture(tour_path,sf::Vector2f(0,0));
    //if (!tour.loadFromFile(tour_path, sf::IntRect(0,0,tour_dim.x,tour_dim.y)))
    
    sprite_tour.setScale(tour_scale);
    // on définit le niveau à l'aide de numéro de tuiles
    
    
        
    renderer::Tile tile;
    tile.convert(level_1_path);
    
      sf::Vector2u image_dim(tile.image.getSize());
    
    if (!Background.load(tile_texture_path,tile_dim,tile.tiles,image_dim.x,image_dim.y))
        return -1;
    
    for(unsigned j=0;j<image_dim.y;j++)
        for(unsigned i=0;i<image_dim.x;i++)
        
            if(static_cast<int>(tile.image.getPixel(i,j).r)==150)
                
                sprite_tour.setPosition(i,j);
        sf::Vector2f tour_1_pos(sprite_tour.getPosition());
        
      
      
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type==sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                Update_dragon=true;
            }
            else
                Update_dragon=false;
        }
        
       
        
        
        
        //gestion 
        gestion_clavier();
      
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        if(game.Mode==0){
        gestion_souris();
     if(time_soldat.getElapsedTime().asMilliseconds()>=Udpadated_clock_soldat)
        {
            anim_soldat.x++;
            if(anim_soldat.x * soldat_dim.x >= soldat.getSize().x)
            anim_soldat.x=0;
            time_soldat.restart();
        }
        
        
        
        
        sprite_button_add.setTextureRect(sf::IntRect(anim_button_add.x*button_dim.x,anim_button_add.y*button_dim.y,button_dim.x,button_dim.y));
        sprite_button_minus.setTextureRect(sf::IntRect(anim_button_minus.x*button_dim.x,anim_button_minus.y*button_dim.y,button_dim.x,button_dim.y));
        sprite_button_ok_A.setTextureRect(sf::IntRect(anim_button_ok_A.x*button_ok_dim.x,anim_button_ok_A.y*button_ok_dim.y,button_ok_dim.x,button_ok_dim.y));
        sprite_button_ok_B.setTextureRect(sf::IntRect(anim_button_ok_B.x*button_ok_dim.x,anim_button_ok_B.y*button_ok_dim.y,button_ok_dim.x,button_ok_dim.y));
        sprite_button_ok_C.setTextureRect(sf::IntRect(anim_button_ok_C.x*button_ok_dim.x,anim_button_ok_C.y*button_ok_dim.y,button_ok_dim.x,button_ok_dim.y));
        sprite_button_ok_compteur.setTextureRect(sf::IntRect(anim_button_ok_compteur.x*button_ok_dim.x,anim_button_ok_compteur.y*button_ok_dim.y,button_ok_dim.x,button_ok_dim.y));
        sprite_soldat.setTextureRect(sf::IntRect(anim_soldat.x*soldat_dim.x,anim_soldat.y*soldat_dim.y,soldat_dim.x,soldat_dim.y));
        sprite_chiffre_unite.setTextureRect(sf::IntRect(anim_chiffre_unite.x*chiffre_dim.x+ajustement_sprite_chiffre,anim_chiffre_unite.y,chiffre_dim.x,chiffre_dim.y));
        sprite_chiffre_dizaine.setTextureRect(sf::IntRect(anim_chiffre_dizaine.x*chiffre_dim.x+ajustement_sprite_chiffre,anim_chiffre_dizaine.y,chiffre_dim.x,chiffre_dim.y));
        sprite_prix_unite.setTextureRect(sf::IntRect(anim_prix_unite.x*chiffre_dim.x+ajustement_sprite_chiffre,anim_prix_unite.y,chiffre_dim.x,chiffre_dim.y));
        sprite_prix_dizaine.setTextureRect(sf::IntRect(anim_chiffre_unite.x*chiffre_dim.x+ajustement_sprite_chiffre,anim_chiffre_unite.y,chiffre_dim.x,chiffre_dim.y));
        sprite_prix_centaine.setTextureRect(sf::IntRect(anim_chiffre_dizaine.x*chiffre_dim.x+ajustement_sprite_chiffre,anim_chiffre_dizaine.y,chiffre_dim.x,chiffre_dim.y));
        
        view_boutique.reset(sf::FloatRect(0,0,window_width,window_heigth));
            view_boutique.setViewport(sf::FloatRect(0,0,1,1));
             window.setView(view_boutique);
        
          
             
         window.draw(sprite_background);
         window.draw(sprite_logo_boutique);
         window.draw(sprite_plage_carte_A);
         window.draw(sprite_plage_carte_B);
         window.draw(sprite_plage_carte_C);
         window.draw(sprite_soldat);
         window.draw(sprite_chiffre_unite);
         window.draw(sprite_chiffre_dizaine);
         window.draw(sprite_prix_unite);
         window.draw(sprite_prix_dizaine);
         window.draw(sprite_prix_centaine);
         window.draw(sprite_carte_verso_A);
         window.draw(sprite_carte_verso_B);
         window.draw(sprite_carte_verso_C);
         window.draw(sprite_button_add);
         window.draw(sprite_button_minus);
         window.draw(sprite_button_ok_A);
         window.draw(sprite_button_ok_B);
         window.draw(sprite_button_ok_C);
         window.draw(sprite_button_ok_compteur);
         window.draw(sprite_money);
         
         view_plage_commune.reset(sf::FloatRect(window_width-plage_commune_dim.x,0,window_width,plage_commune_dim.y));
            view_plage_commune.setViewport(view_plage_commune_set);
             window.setView(view_plage_commune);
             window.draw(sprite_plage_commune);
         
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        if(game.Mode==1)
        {
            sprite_plage_menu.setTextureRect(sf::IntRect(anim_plage_menu.x*plage_menu_dim.x,anim_plage_menu.y*plage_menu_dim.y,plage_menu_dim.x,plage_menu_dim.y));
            
            
          
              
            
            //scrolling
            //view_map.reset(sf::FloatRect(0,0,window_width,window_heigth));
            position.x=sprite_perso.getPosition().x - window_width/2;
            position.y=sprite_perso.getPosition().y - window_heigth/2;
            /*if(position.x<-window_width/2)
                position.x=-window_width/2;
            if(position.y<-window_heigth/2)
                position.y=-window_heigth/2;
            if(position.x>window_width/2)
                position.x=window_width/2;
            if(position.y>window_heigth/2)
                position.y=window_heigth/2;*
            rectangle.setPosition((position.x)*minimap_scale.x,(position.y)*minimap_scale.y);
            view_map.reset(sf::FloatRect(position.x,position.y,window_width,window_heigth));
            
            
            
            window.setView(view_map);
            //elements qui bougent
             Background.setScale(1,1);
             sprite_tour.setPosition(tour_1_pos);
             sprite_tour.setScale(tour_scale);
            window.draw(Background);
            window.draw(sprite_tour);
            
            view_menu.reset(sf::FloatRect(0,0,window_width,window_heigth));
            view_menu.setViewport(view_menu_set);
             window.setView(view_menu);
              window.draw(sprite_plage_menu);
              
              view_plage_commune.reset(sf::FloatRect(window_width-plage_commune_dim.x,0,window_width,plage_commune_dim.y));
            view_plage_commune.setViewport(view_plage_commune_set);
           window.setView(view_plage_commune);
             window.draw(sprite_plage_commune);
             
            view_minimap.reset(sf::FloatRect(0,0,image_dim.x*tile_dim.x,image_dim.y*tile_dim.y));
            view_minimap.setViewport(sf::FloatRect(0.75f,0.75f,1,1));
            
           window.setView(view_minimap);
           Background.setScale(minimap_scale);
           sprite_tour.setPosition(tour_1_pos.x*minimap_scale.x/tour_scale.x,tour_1_pos.y*minimap_scale.y);
           sprite_tour.setScale(0.7f,1);
             window.draw(Background);
             window.draw(sprite_tour);
             window.draw(rectangle);
        
        }
       
         
        
        
        
        
        window.display();
         window.clear();
    }
    
   
    return 0;
}

//gestion de clavier

void gestion_clavier(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            
           
            anim_dragon.y=Up;
            sprite_perso.move(0,-speed);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {   
            anim_dragon.y=Down;
            sprite_perso.move(0,speed);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            
            anim_dragon.y=Left;
            sprite_perso.move(-speed,0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
          
            anim_dragon.y=Right;
            sprite_perso.move(speed,0);
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        {if(Update_boutique==true)
        if(game.Mode==0) 
            game.Mode=1;
        
        else 
            game.Mode=0;
        Update_boutique=false;}
    else Update_boutique=true; 
    
        
    /*if(sprite_perso.getPosition().x<=0)
        sprite_perso.setPosition(sf::Vector2f(0,sprite_perso.getPosition().y));
        
    if(sprite_perso.getPosition().y<=0)
        sprite_perso.setPosition(sf::Vector2f(sprite_perso.getPosition().x,0));
        
        if(sprite_perso.getPosition().x>window_width)
        sprite_perso.setPosition(sf::Vector2f(window_width,sprite_perso.getPosition().y));
        
    if(sprite_perso.getPosition().y>window_heigth)
        
        sprite_perso.setPosition(sf::Vector2f(sprite_perso.getPosition().x,window_heigth));*/
        /*
}

//gestion souris

void gestion_souris(){
     if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
         {
             positionSouris= sf::Mouse::getPosition(window);
             //std::cout << "Mouse.x" << positionSouris.x << "Mouse.y" << positionSouris.y << std::endl;
             int mouseX=positionSouris.x;
             int mouseY=positionSouris.y;
            
             
          // gestion compteur   
         if((mouseX>mouse_add_origin.x) && (mouseX<mouse_add_exte.x) && (mouseY>mouse_add_origin.y) && (mouseY<mouse_add_exte.y))
         { anim_button_add.y=1;
         
       
         if (anim_chiffre_dizaine.x==9)
         {
             if (anim_chiffre_unite.x==9) anim_chiffre_unite.x=0;
         if(anim_chiffre_unite.x!=9) anim_chiffre_unite.x++;
            
         if(anim_chiffre_unite.x==8)
         {
             anim_chiffre_dizaine.x=0;
             anim_chiffre_unite.x++;
         }
         
         }
         else
         {
            if (anim_chiffre_unite.x==8)
            {
                anim_chiffre_unite.x++; 
                anim_chiffre_dizaine.x++;
            }
            
            if (anim_chiffre_unite.x==9) anim_chiffre_unite.x=0;
            else anim_chiffre_unite.x++;
         }
        
         }
             
         else anim_button_add.y=0; 
             
         if((mouseX>mouse_minus_origin.x) && (mouseX<mouse_minus_exte.x) && (mouseY>mouse_minus_origin.y) && (mouseY<mouse_minus_exte.y))
         {anim_button_minus.y=1;
         if (anim_chiffre_dizaine.x==0)
         {
             if(anim_chiffre_unite.x!=0) anim_chiffre_unite.x--;
             if (anim_chiffre_unite.x==0) anim_chiffre_unite.x=9;
         
            
         if(anim_chiffre_unite.x==9)
         {
             anim_chiffre_dizaine.x=9;
             anim_chiffre_unite.x--;
         }
         
         }
         else
         {
            if (anim_chiffre_unite.x==9)
            {
                anim_chiffre_unite.x--; 
                anim_chiffre_dizaine.x--;
            }
            
            if (anim_chiffre_unite.x==0) anim_chiffre_unite.x=9;
            else anim_chiffre_unite.x--;
         }
        
         }
             else anim_button_minus.y=0;
        
             //gestion des bouton ok
     //boutton ok A
     if((mouseX>button_ok_A_pos.x) && (mouseX<mouse_limit_button_ok_A.x) && (mouseY>button_ok_A_pos.y) && (mouseY<mouse_limit_button_ok_A.y))
      anim_button_ok_A.x=1;
         else anim_button_ok_A.x=0;
             
     //boutton ok B
     if((mouseX>button_ok_B_pos.x) && (mouseX<mouse_limit_button_ok_B.x) && (mouseY>button_ok_B_pos.y) && (mouseY<mouse_limit_button_ok_B.y))
      anim_button_ok_B.x=1;
         else anim_button_ok_B.x=0;
            
             //boutton ok C
     if((mouseX>button_ok_C_pos.x) && (mouseX<mouse_limit_button_ok_C.x) && (mouseY>button_ok_C_pos.y) && (mouseY<mouse_limit_button_ok_C.y))
      anim_button_ok_C.x=1;
         else anim_button_ok_C.x=0;
             
             //boutton ok compteur 
     if((mouseX>button_ok_compteur_pos.x) && (mouseX<mouse_limit_button_ok_compteur.x) && (mouseY>button_ok_compteur_pos.y) && (mouseY<mouse_limit_button_ok_compteur.y))
      anim_button_ok_compteur.x=1;
     else anim_button_ok_compteur.x=0;
     
         
     }
     else {
       
         
         anim_button_add.y=0;
         anim_button_minus.y=0;
         anim_button_ok_A.x=0;
         anim_button_ok_B.x=0;
         anim_button_ok_C.x=0;
         anim_button_ok_compteur.x=0;
     }
                 
     }
             
    
*/

int main()
{   
    
    renderer::Level level;
    level.level_init();

    while (level.window.window.isOpen())
    {   

        sf::Event event;
        while (level.window.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                level.window.window.close();
        }
       
        level.upDate();
        
    }

    return 0;
}

