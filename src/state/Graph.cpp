/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Graph.h"
#include "Adjacent.h"
#include "Territory.h"

namespace state {
    
    Graph::Graph (Territory* summit,Adjacent* adjacent){
        
        list_summit.push_back(summit);
        list_adjacent.push_back(adjacent);
        
    }
    Graph::~Graph (){
while(list_summit[0]) delete list_summit[0];
while(list_adjacent[0]) delete list_adjacent[0];
        }
    
    
    
    void Graph::add_summit (Territory* summit){
        list_summit.push_back(summit);
    }
    
    
    void Graph::delete_summit (Territory* summit){
    }
    
    
    
    void Graph::delete_adjacent (Territory* territory_1,Territory* territory_2){
    }
    
    
    void Graph::add_adjacent (Adjacent* adjacent){
        list_adjacent.push_back(adjacent);
    }
    
  };
