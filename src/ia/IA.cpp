#include "IA.h"
#include "engine/Move_unit.h"
#include "state/State.h"
#include <iostream>
#include <cstdlib>
#define RAND_MAX 30

  ia::IA::IA (int gang){
      this->gang=gang;
      
  }
  ia::IA::~IA (){
      
  }
  void ia::IA::play (state::State& state){
      
      int terr_from=list_territory[std::rand()%list_territory.size()];
      while(state.list_territory[terr_from].get_nb_unit()<2)
          terr_from=list_territory[std::rand()%list_territory.size()];
      int terr_to=state.list_territory[terr_from].getAdajcent()[std::rand()%state.list_territory[terr_from].getAdajcent().size()];
      int nb_unit=std::rand()%(state.list_territory[terr_from].get_nb_unit());
      if (nb_unit==0)
          nb_unit=nb_unit+1;
      
      std::cout<<"le territoire "<<terr_to<<" a été attaqué par le territoire "<<terr_from<<" avec "<<nb_unit<<" unités "<<std::endl;
      action.id_terr_from=terr_from;
     
      action.id_terr_to=terr_to;
      action.nb_unit=nb_unit;
      
      std::cout<<list_territory.size()<<std::endl;
      
  }

  int ia::IA::get_gang(){
      return gang;
  }
  
  void ia::IA::set_gang(int gang){
      this->gang=gang;
  }
  
  std::vector<int> ia::IA::get_List(){
      return list_territory;
  }
  
  void ia::IA::add_List(int territory){
      list_territory.push_back(territory);
  }
  
  void ia::IA::remote_list(){
      list_territory.clear();
  }
  
  void ia::IA::Update(state::State& state){
      this->remote_list();
      for (int i=0;i<state.list_territory.size();i++)
          if(state.list_territory[i].get_gang()==gang)
              this->add_List(state.list_territory[i].get_ID());
  }