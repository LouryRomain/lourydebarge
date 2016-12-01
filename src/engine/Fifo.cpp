#include "Fifo.h"
#include <iostream>


engine::Fifo::Fifo(){
    
}

engine::Fifo::~Fifo(){
    
    
}

void engine::Fifo::write (state::State& state,engine::Command* action){
    
    list_commande.push_back(action);
}
void engine::Fifo::read (state::State& state){
    std::cout<<"On a lancé le thread du moteur"<<std::endl;
    while(1){
        
    if(list_commande.size()!=0){
        mutex.lock();
    list_commande[0]->make(state);
    list_commande.erase(list_commande.begin());
    std::cout<<"On a executer une commande avec le thread du moteur"<<std::endl;
    mutex.unlock();
    }}
}