#include "Clock.h"

control::Clock::Clock (){
    
}
control::Clock::~Clock (){
    
}
void  control::Clock::action (state::Element element){
    if(clock.getElapsedTime().asMilliseconds()>=100)
        {
            element.setAnim(sf::Vector2i(element.getAnim().x+1,element.getAnim().y));
            if(element.getAnim().x * element.getDim().x >= element.getDim().x*7)
            element.setAnim(sf::Vector2i(0,element.getAnim().y));
            clock.restart();
            
        }
}
