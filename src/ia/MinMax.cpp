#include "state/State.h"
#include "MinMax.h"
#include "Attack.h"
#include "Defence.h"
#include <iostream>

ia::MinMax::MinMax() {


}

ia::MinMax::~MinMax() {

}

void ia::MinMax::create_tree(const state::State& state, int gang, int depth) {
    state_tmp = state.clone();
    std::vector<engine::Move_unit> record;

    ia::Node origine(0, 0, 1);
    tree.push_back(origine);



    if (state.getListGang()[1].getAction_done() == 0) {
        this->recursive(1, state_tmp, 1, record, depth);




    } else if (state.getListGang()[1].getAction_done() == 1) {
        this->recursive(1, state_tmp, 2, record, depth);




    } else if (state.getListGang()[1].getAction_done() == 2) {
        this->recursive(1, state_tmp, 3, record, depth);



    }


    std::cout << "le nombre de noeud :" << tree.size() << std::endl;
}

void ia::MinMax::recursive(int depth, state::State& state, int depart, std::vector<engine::Move_unit> record, int ordre) {

    if (ordre > 0) {
      
        std::vector<engine::Move_unit> list_action;
        ia::Attack attack;
        attack.init(state, (depart/3)%2+1);


        ia::Defence defence;
        defence.init(state, (depart/3)%2+1);
        for (int k = 0; k < defence.list_defence.size(); k++)
            list_action.push_back(defence.list_defence[k]);
        for (int k = 0; k < attack.list_attack.size(); k++)
            list_action.push_back(attack.list_attack[k]);
        
        
        
        
        tree[tree.size()-1].nb_child=list_action.size();

        for (int ki = 0; ki < list_action.size(); ki++) {


            list_action[ki].make(state, record);

            ia::Node node2(depth, ki, (depart/3)%2+1);

            if(ordre==1)
                this->score(node2, state_tmp,1 );
                //std::cout<<node2.get_score()<<"    "<<ordre<<" "<<node2.depth<<std::endl;
            tree.push_back(node2);
            this->recursive(depth + 1, state, depart+1, record, ordre - 1);


            list_action[ki].demake(state, record);
        }


    }
}

void ia::MinMax::score(ia::Node& node, const state::State& state, int gang) {

    node.set_score(state.getlistterritorygang(gang).size());
    

}

int ia::MinMax::solve(const state::State& state, int gang,std::vector<ia::Node> tree) {
    int depth = 3;
    
   
    std::vector<int> layer_child;
    std::vector<ia::Node> layer_parent;
    while(depth>0){
        std::cout<<depth<<std::endl;
       
        
        for(int j=0;j<tree.size();j++)
                    if(tree[j].depth==depth-1){
                        layer_parent.push_back(tree[j]);
                        }
        //std::cout<<"la taille de la iste des parents est "<<layer_parent.size()<<std::endl;
        for(int i=0;i< layer_parent.size();i++){
            
            
           
                    
                int ind=0;
                for(int j=0;j<tree[i].width;j++)
                        ind=ind+layer_parent[j].nb_child;
                
                        
                for(int j=0;j<tree.size();j++){
                    
                    if(tree[j].depth==depth){
                        //std::cout<<tree[j].width<<"  "<<j<<std::endl;
                        layer_child.push_back(j);
                        
                    }
                        }
                
                //std::cout<<"la taille de la iste des enfant est "<<layer_child.size()<<tree[i].nb_child<<std::endl;
  
                //std::cout<<"le gang du noeud est "<<tree[i].gang<<std::endl;
                if( layer_parent[i].gang==1){
                int max=0;
                //std::cout<<ind<<std::endl;
                for(int j=ind;j<ind+ layer_parent[i].nb_child;j++){
                    //std::cout<<tree[layer_child[j]].get_score()<<std::endl;
                    if(tree[layer_child[j]].get_score()>=max){
                        //std::cout<<layer_child[j].get_score()<<std::endl;
                        max=tree[layer_child[j]].get_score();
                         layer_parent[i].set_score(max);
                       
                         layer_parent[i].set_ind_sol(j-ind);
                    }}
                
                layer_child.clear();
                }
                //std::cout<<tree[i].gang<<std::endl;
                if( layer_parent[i].gang==2){
                   // std::cout<<depth<<std::endl;
                int min=100;
                for(int j=ind;j<ind+ layer_parent[i].nb_child;j++){
                     
                    if(tree[layer_child[j]].get_score()<=min){
                       //std::cout<<layer_child[j].get_score()<<std::endl;
                        min=tree[layer_child[j]].get_score();
                         layer_parent[i].set_score(min);
                       
                         layer_parent[i].set_ind_sol(j-ind);
                    }}
                //std::cout<<min<<std::endl;
                layer_child.clear();
                }
                        
                    
                
                
                
                    }
        
        
        layer_parent.clear();
        depth--;
    }
   
    return tree[0].get_ind_sol();
}
