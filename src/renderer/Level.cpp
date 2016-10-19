/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <renderer/Level.h>

#include <renderer/Texture.h>
#include<iostream>

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







//bouton add
renderer::Texture button;
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
sf::Vector2f carte_A_pos(30,350);
sf::Vector2f carte_B_pos(490,350);
sf::Vector2f carte_C_pos(930,350);
std::string carte_verso_path="/home/utilisateur/Documents/PLT/res/autres/carte_verso.png";
float carte_verso_scale=0.75f;
sf::Vector2f carte_verso_dim(261,406);

//chiffre
renderer::Texture alphabet;
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
sf::Vector2f perso_pos(600,350);

//logo boutique
renderer::Texture logo_boutique;
std::string logo_boutique_path="/home/utilisateur/Documents/PLT/res/autres/logo.png";

//money
renderer::Texture money;
std::string money_path="/home/utilisateur/Documents/PLT/res/autres/money.png";
float money_scale=0.75f;
sf::Vector2f pos_money(630,100);

//plage carte
renderer::Texture plage_carte;
std::string plage_carte_path="/home/utilisateur/Documents/PLT/res/autres/plage_carte.png";
sf::Vector2f  select_plage_carte_A(0,0);
sf::Vector2f  select_plage_carte_B(0,1);
sf::Vector2f  select_plage_carte_C(0,2);
sf::Vector2f plage_carte_dim(228,76);


//soldat
renderer::Texture soldat;
sf::Vector2i anim_soldat(0,0);
float homme_scale=1.5f;
std::string homme_path="/home/utilisateur/Documents/PLT/res/mechants/homme.png";
sf::Vector2f soldat_pos(700,110);
sf::Vector2f soldat_dim(80,80);


//souris
sf::Vector2i positionSouris;

//view
sf::View view_boutique;

////Mode 1

//minimap
sf::RectangleShape rectangle(sf::Vector2f(1200*0.25,700*0.25f));
sf::View view_minimap;
int thickness_rectangle=3;
sf::Vector2f minimap_scale(0.25f,0.25f);

//plage menu
renderer::Texture plage_menu;
sf::Vector2i anim_plage_menu(1,0);
std::string plage_menu_path="/home/utilisateur/Documents/PLT/res/autres/plage_menu.png";
sf::Vector2i plage_menu_dim(358,700);
sf::Vector2f plage_menu_scale(3.3f,1);
sf::FloatRect view_menu_set(0,0,0.3f,1);






//tour 
renderer::Texture tour;

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
sf::Vector2f plage_commune_pos(1200-plage_commune_width,plage_commune_pos_Y);

#pragma endregion variables
renderer::Texture background;
std::string background_path="/home/utilisateur/Documents/PLT/res/surfaces/background.png";
sf::Sprite sprite;

 renderer::Level::Level (){
     
 }
 renderer::Level::~Level (){
     
 }
 
 void renderer::Level::level_init(){
      window.Window_init();
     sprite_background = background.load_texture(background_path,sf::Vector2f(1,0));
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
        


 }
 
 void renderer::Level::upDate(){
     window.window.draw(sprite_background);
     window.window.draw(sprite_logo_boutique);
     window.window.draw(sprite_plage_carte_A);
     window.window.draw(sprite_plage_carte_B);
     window.window.draw(sprite_plage_carte_C);
     window.window.draw(sprite_soldat);
     window.window.draw(sprite_chiffre_unite);
     window.window.draw(sprite_chiffre_dizaine);
     window.window.draw(sprite_prix_unite);
     window.window.draw(sprite_prix_dizaine);
     window.window.draw(sprite_prix_centaine);
     window.window.draw(sprite_carte_verso_A);
     window.window.draw(sprite_carte_verso_B);
     window.window.draw(sprite_carte_verso_C);
     window.window.draw(sprite_button_add);
     window.window.draw(sprite_button_minus);
     window.window.draw(sprite_button_ok_A);
     window.window.draw(sprite_button_ok_B);
     window.window.draw(sprite_button_ok_C);
     window.window.draw(sprite_button_ok_compteur);
     window.window.draw(sprite_money);
     window.window.display();
     window.window.clear();
 }