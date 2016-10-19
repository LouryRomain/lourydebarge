/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <renderer/Window.h>

 renderer::Window::Window (){
     
 }
 renderer::Window::~Window (){
     
 }
    void renderer::Window::Window_init (){
        
int window_width=1200;
int window_heigth=700;
sf::Vector2i pos_window(0,0);
int frame_fps_limit=60;
std::string window_title="Gang War";
        window.create(sf::VideoMode(window_width,window_heigth),window_title);
    window.setPosition(pos_window);
    window.setFramerateLimit(frame_fps_limit);
        
    }