#include "Node.h"

ia::Node::Node (){
    score=new int;
    *score=0;
    ind_sol=new int;
    *ind_sol=-1;
}
ia::Node::~Node (){
   
}
ia::Node::Node (int depth){
    this->depth=depth;
}
ia::Node::Node (int depth,int width,int gang){
    this->depth=depth;
    this->width=width;
    this->gang=gang;
 
   score=new int;
    *score=0;
    ind_sol=new int;
    *ind_sol=-1;
    nb_child=0;
    
}

int ia::Node::get_ind_sol(){
    return *ind_sol;
}

int ia::Node::get_score(){
    return *score;
}
void ia::Node::set_ind_sol(int ind_sol){
    *this->ind_sol=ind_sol;
}

void ia::Node::set_score(int score){
 
    *this->score=score;
}