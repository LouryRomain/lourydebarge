#ifdef SFML_STATIC 
#endif 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <state.h>
#include <renderer/Texture.h>

#include "renderer/Tile.h"
#include "renderer/Window.h"
#include "renderer/Level.h"



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

