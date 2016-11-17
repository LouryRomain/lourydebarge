#include <cmath>

#include "Move_unit.h"
#include "state/State.h"

engine::Move_unit::Move_unit(int id_terr_to, int id_terr_from, int nb_unit) {
    this->id_terr_to = id_terr_to;
    this->id_terr_from = id_terr_from;
    this->nb_unit = nb_unit;
}

engine::Move_unit::Move_unit() {

}

engine::Move_unit::~Move_unit() {

}

void engine::Move_unit::make(state::State& state) {



    if ((state.list_territory[id_terr_from].get_nb_unit() - nb_unit > 0)&&(state.list_territory[id_terr_to].get_nb_unit() + nb_unit < 100)) {
        state.list_territory[id_terr_from].set_nb_unit(state.list_territory[id_terr_from].get_nb_unit() - nb_unit);
        if (state.list_territory[id_terr_from].get_gang() == state.list_territory[id_terr_to].get_gang())
            state.list_territory[id_terr_to].set_nb_unit(state.list_territory[id_terr_to].get_nb_unit() + nb_unit);
        else {
            if (state.list_territory[id_terr_to].get_nb_unit() - nb_unit > 0) {
                state.list_territory[id_terr_to].set_nb_unit(state.list_territory[id_terr_to].get_nb_unit() - nb_unit);
            } else {
                state.list_territory[id_terr_to].set_nb_unit(-state.list_territory[id_terr_to].get_nb_unit() + nb_unit);
                state.list_territory[id_terr_to].set_gang(state.list_territory[id_terr_from].get_gang());

            }
        }

    }
}