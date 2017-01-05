#include "Fifo.h"
#include <iostream>
#include <SFML/Network.hpp>
#include <json/json.h>




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
        Json::Value data;
        data["name"]="Jean";
        data["age"]=47;

     sf::Http::Request request;
     request.setMethod(sf::Http::Request::Put);
     request.setUri("/user");
     request.setHttpVersion(1, 1);
     request.setField("Content-Type", "application/x-www-form-urlencoded");
     request.setBody(data.toStyledString());

     sf::Http http("http://localhost",8080);
     sf::Http::Response response = http.sendRequest(request);
     std::cout<<response.getStatus()<<std::endl;
        mutex.lock();
    list_commande[0]->make(state);
    
    list_commande.erase(list_commande.begin()); 
    
    std::cout<<"On a executé une commande avec le thread du moteur"<<std::endl;
    mutex.unlock();
    }}
}
