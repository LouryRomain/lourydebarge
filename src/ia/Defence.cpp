#include "state/State.h"
#include "Defence.h"


ia::Defence::Defence(){
    
}
ia::Defence::~Defence(){
    
}
int ia::Defence::score_defence(state::State& state){
    
}

void ia::Defence::init(state::State& state,int gang){
     list_defence.clear();

    list_score.clear();
    engine::Move_unit defence;
    int init=0;
    std::vector<state::Territory> list_territory=state.getlistterritorygang(gang);
    for(int i=0;i<list_territory.size();i++)
    for ( int j=0;j<list_territory[i].getAdajcent().size();j++)
        if(state.list_territory[list_territory[i].getAdajcent()[j]].get_gang()==gang)
            if(state.list_territory[list_territory[i].getAdajcent()[j]].get_nb_unit()<list_territory[i].get_nb_unit()){
       defence=engine::Move_unit(list_territory[i].getAdajcent()[j],list_territory[i].get_ID(),list_territory[i].get_nb_unit()-1);
        
        
        
        list_defence.push_back(defence);
        list_score.push_back(init);}
    }
    
