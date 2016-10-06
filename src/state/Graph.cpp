/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Graph.h"
#include "Adjacent.h"
#include "Territory.h"

namespace state {
    
    Graph::Graph (){
    }
    Graph::~Graph (){
         for(int unsigned i=0;i<list_summit.size();i++)
            {
                delete list_summit[i];
            }
        for(int unsigned i=0;i<list_adjacent.size();i++)
            {
                delete list_adjacent[i];
            }
        }
    
    
    
    void Graph::add_summit (Territory* summit){
        list_summit.push_back(summit);
    }
    
    
    void Graph::delete_summit (int ID){
     
        for(int unsigned i=0;i<list_summit.size();i++)
            {
                delete list_summit[i];
            }
       
       
        }
    
    
    
    void Graph::delete_adjacent (int ID_1, int ID_2){
    }
    
    
    void Graph::add_adjacent (Adjacent* adjacent){
        list_adjacent.push_back(adjacent);
    }
    
  };
