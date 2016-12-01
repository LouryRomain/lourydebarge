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
        this->recursive(1, state_tmp, 0, record, depth);



    }


    std::cout << "le nombre de noeud :" << tree.size() << std::endl;
}

void ia::MinMax::recursive(int depth, state::State& state, int depart, std::vector<engine::Move_unit> record, int ordre) {

    if (ordre > 0) {

        std::vector<engine::Move_unit> list_action;
        ia::Attack attack;
        attack.init(state,(depart / 3) % 2 + 1);
        //std::cout<<"le gang est "<<(depart / 3) % 2 + 1<<std::endl;

        ia::Defence defence;
        defence.init(state, (depart / 3) % 2 + 1);
        for (int k = 0; k < defence.list_defence.size(); k++)
            list_action.push_back(defence.list_defence[k]);
        for (int k = 0; k < attack.list_attack.size(); k++){
            list_action.push_back(attack.list_attack[k]);
            //std::cout<<"On attaque "<<attack.list_attack[k].id_terr_to<<" avec "<<attack.list_attack[k].id_terr_from<<std::endl;
        }


        //std::cout<<attack.list_attack.size()<<std::endl;
        
        tree[tree.size() - 1].nb_child = list_action.size();

        for (int ki = 0; ki < list_action.size(); ki++) {


            list_action[ki].make(state);

            ia::Node node2(depth, ki, (depart / 3) % 2 +1);

            if (ordre == 1)
                this->score(node2, state_tmp, 1);
            //std::cout<<node2.get_score()<<"    "<<ordre<<" "<<node2.depth<<std::endl;
            tree.push_back(node2);
            this->recursive(depth + 1, state, depart + 1, record, ordre - 1);


            list_action[ki].demake(state);
        }


    }
}

void ia::MinMax::score(ia::Node& node, const state::State& state, int gang) {

    node.set_score(state.getlistterritorygang(gang).size());


}

int ia::MinMax::solve(const state::State& state, int gang, std::vector<ia::Node> tree) {
    int depth = 3;
    int ind=0;
    int max=0;
    int min=100;

   

    while (depth > 0) {
        
        std::cout << depth << std::endl;
        for(int i=0;i<tree.size();i++){
            
            if(tree[i].depth==depth-1){
                if(tree[i].gang==1){
                max=0;
                ind=0;
                for(int j=i;j<tree.size();j++){
                    if(tree[j].depth==depth){
                        ind++;
                    if(ind<tree[i].nb_child)
                        if(tree[j].get_score()>max){
                            max=tree[j].get_score();
                            tree[i].set_score(max);
                            tree[i].set_ind_sol(tree[j].width);
                            //std::cout<<"la solution est "<<tree[j].get_ind_sol()<<" pour "<<tree[i].get_ind_sol()<<std::endl;
                        }
                                
                    }
                }
                }
                if(tree[i].gang==2){
                min=100;
                ind=0;
                for(int j=i;j<tree.size();j++){
                    if(tree[j].depth==depth){
                        ind++;
                    if(ind<tree[i].nb_child)
                        if(tree[j].get_score()<min){
                            min=tree[j].get_score();
                            tree[i].set_score(min);
                            tree[i].set_ind_sol(tree[j].width);
                            //std::cout<<"la solution est "<<tree[j].get_ind_sol()<<" pour "<<tree[i].get_ind_sol()<<std::endl;
                        }
                                
                    }
                }
                }
                
                
                
            }
                
           
        }
        


        depth--;
    }
    std::cout<<"la solution est "<<tree[0].get_score()<<std::endl;
    return tree[0].get_ind_sol();
}