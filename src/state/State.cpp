

#include "State.h"

#include <iostream>


int plage_commune_dimX = 235;


state::State::State() {
    state = new int;
    *state = 1;
}

state::State::~State() {

}

int state::State::getState() {
    return *state;
}

void state::State::setState(int state) {
    delete this->state;
    this->state = new int;
    *(this->state) = state;
}

std::vector<state::ListElement> state::State::getListListElement() {
    return list_ListElement;
}

void state::State::add_ListElement(state::ListElement ListElement) {
    this->list_ListElement.push_back(ListElement);
}

std::vector<state::Gang> state::State::getListGang() {
    return list_gang;
}

void state::State::add_Gang(state::Gang Gang) {
    this->list_gang.push_back(Gang);
}

void state::State::upDate() {
    
}

void state::State::init() {

    list_gang.push_back(player.gang);
    state::Element background(0, 0, 12);
    state::Element carte_verso_A(30, 350, 2);
    state::Element carte_verso_B(490, 350, 2);
    state::Element carte_verso_C(930, 350, 2);
    state::Element soldat(700, 110, 3);
    state::Element plage_commune(1200 - 235, 0, 4);
    state::Element button_add(625, 150, 14, 0);
    state::Element button_minus(505, 150, 15, 0);
    state::Element chiffre_unite(590, 160, 5, 0);
    state::Element chiffre_dizaine(590 - 17 * 2, 160, 6, 0);
    state::Element prix_unite(590, 110, 19);
    state::Element prix_dizaine(590 - 17 * 1.5f, 110, 20);
    state::Element prix_centaine(590 - 17 * 1.5f * 2, 110, 21);
    state::Element button_ok_A(static_cast<int> (30 + 261 / 2 * 0.75f - 64 * 1.5f / 2), static_cast<int> (350 + 406 * 0.75f + 10), 22, 0);
    state::Element button_ok_B(static_cast<int> (490 + 261 / 2 * 0.75f - 64 * 1.5f / 2), static_cast<int> (350 + 406 * 0.75f + 10), 23, 0);
    state::Element button_ok_C(static_cast<int> (930 + 261 / 2 * 0.75f - 64 * 1.5f / 2), static_cast<int> (350 + 406 * 0.75f + 10), 24, 0);
    state::Element button_ok_compteur(static_cast<int> (590 - 64 * 1.5f / 2), 160 + 17 * 2 + 10, 13, 0);
    state::Element logo_boutique(0, 0, 18);
    state::Element money(630, 100, 17);
    state::Element plage_carte_A(static_cast<int> (30 + 261 / 2 * 0.75f - 228 / 2), 350 - 76, 9);
    state::Element plage_carte_B(static_cast<int> (490 + 261 / 2 * 0.75f - 228 / 2), 350 - 76, 10);
    state::Element plage_carte_C(static_cast<int> (930 + 261 / 2 * 0.75f - 228 / 2), 350 - 76, 11);

    state::Element plage_menu(0, 0, 1);
    state::Element button_add_1(190, 405, 14, 0);
    state::Element button_minus_1(80, 405, 15, 0);
    state::Element chiffre_unite_01(160, 415, 5, 0);
    state::Element chiffre_dizaine_01(160 - 17 * 2, 415, 6, 0);
    state::Element button_ok_compteur_1(static_cast<int> (160 - 64 * 1.5f / 2), 415 + 17 * 2 + 10, 13, 0);
    state::Element chiffre_unite_02(160, 300, 5, 1);
    state::Element chiffre_dizaine_02(160 - 17 * 2, 300, 6, 1);
    state::Element chiffre_unite_sec(160, 75, 5, 2);
    state::Element chiffre_dizaine_sec(160 - 17 * 2, 75, 6, 2);


    state::Element chiffre_unite_03(1200 - 120, 25, 5, 1);
    state::Element chiffre_dizaine_03(1200 - 120 - 17 * 2, 25, 6, 1);
    state::Element chiffre_centaine_03(1200 - 120 - 17 * 2 * 2, 25, 7, 1);
    state::Element chiffre_millier_03(1200 - 120 - 17 * 2 * 3, 25, 8, 1);
    state::Element chiffre_unite_032(1200 - 120, 25 + 17 * 2 + 10, 5, 2);
    state::Element chiffre_dizaine_032(1200 - 120 - 17 * 2, 25 + 17 * 2 + 10, 6, 2);


    state::ListElement list_boutique(1);
    state::ListElement list_map(4);
    state::ListElement list_plage_commune(5);
    state::ListElement list_plage_menu(3);
    state::ListElement list_minimap(2);




    state::Element tour0(0, 0, 16, 0, 0);
    state::Element tour1(0, 0, 16, 0, 1);
    state::Element tour2(0, 0, 16, 0, 2);
    state::Element tour3(0, 0, 16, 0, 3);
    state::Element tour4(0, 0, 16, 0, 4);
    state::Element tour5(0, 0, 16, 0, 5);
    state::Element tour6(0, 0, 16, 0, 6);
    state::Element tour7(0, 0, 16, 0, 7);
    state::Element tour8(0, 0, 16, 0, 8);
    state::Element tour9(0, 0, 16, 0, 9);
    state::Element tour10(0, 0, 16, 0, 10);
    state::Element tour11(0, 0, 16, 0, 11);
    state::Element tour12(0, 0, 16, 0, 12);
    state::Element tour13(0, 0, 16, 0, 13);
    state::Element tour14(0, 0, 16, 0, 14);
    state::Element tour15(0, 0, 16, 0, 15);
    state::Element tour16(0, 0, 16, 0, 16);
    state::Element tour17(0, 0, 16, 0, 17);
    state::Element tour18(0, 0, 16, 0, 18);
    state::Element tour19(0, 0, 16, 0, 19);
    state::Element tour20(0, 0, 16, 0, 20);
    state::Element tour21(0, 0, 16, 0, 21);
    state::Element tour22(0, 0, 16, 0, 22);
    state::Element tour23(0, 0, 16, 0, 23);
    state::Element tour24(0, 0, 16, 0, 24);
    state::Element tour25(0, 0, 16, 0, 25);
    state::Element tour26(0, 0, 16, 0, 26);
    state::Element tour27(0, 0, 16, 0, 27);
    state::Element tour28(0, 0, 16, 0, 28);
    state::Element tour29(0, 0, 16, 0, 29);
    state::Element tour30(0, 0, 16, 0, 30);

    state::Element chiffre_unite_0(0, 0, 5, 0, 0);
    state::Element chiffre_unite_1(0, 0, 5, 0, 1);
    state::Element chiffre_unite_2(0, 0, 5, 0, 2);
    state::Element chiffre_unite_3(0, 0, 5, 0, 3);
    state::Element chiffre_unite_4(0, 0, 5, 0, 4);
    state::Element chiffre_unite_5(0, 0, 5, 0, 5);
    state::Element chiffre_unite_6(0, 0, 5, 0, 6);
    state::Element chiffre_unite_7(0, 0, 5, 0, 7);
    state::Element chiffre_unite_8(0, 0, 5, 0, 8);
    state::Element chiffre_unite_9(0, 0, 5, 0, 9);
    state::Element chiffre_unite_10(0, 0, 5, 0, 10);
    state::Element chiffre_unite_11(0, 0, 5, 0, 11);
    state::Element chiffre_unite_12(0, 0, 5, 0, 12);
    state::Element chiffre_unite_13(0, 0, 5, 0, 13);
    state::Element chiffre_unite_14(0, 0, 5, 0, 14);
    state::Element chiffre_unite_15(0, 0, 5, 0, 15);
    state::Element chiffre_unite_16(0, 0, 5, 0, 16);
    state::Element chiffre_unite_17(0, 0, 5, 0, 17);
    state::Element chiffre_unite_18(0, 0, 5, 0, 18);
    state::Element chiffre_unite_19(0, 0, 5, 0, 19);
    state::Element chiffre_unite_20(0, 0, 5, 0, 20);
    state::Element chiffre_unite_21(0, 0, 5, 0, 21);
    state::Element chiffre_unite_22(0, 0, 5, 0, 22);
    state::Element chiffre_unite_23(0, 0, 5, 0, 23);
    state::Element chiffre_unite_24(0, 0, 5, 0, 24);
    state::Element chiffre_unite_25(0, 0, 5, 0, 25);
    state::Element chiffre_unite_26(0, 0, 5, 0, 26);
    state::Element chiffre_unite_27(0, 0, 5, 0, 27);
    state::Element chiffre_unite_28(0, 0, 5, 0, 28);
    state::Element chiffre_unite_29(0, 0, 5, 0, 29);
    state::Element chiffre_unite_30(0, 0, 5, 0, 30);


    state::Element chiffre_dizaine_0(0, 0, 6, 0, 0);
    state::Element chiffre_dizaine_1(0, 0, 6, 0, 1);
    state::Element chiffre_dizaine_2(0, 0, 6, 0, 2);
    state::Element chiffre_dizaine_3(0, 0, 6, 0, 3);
    state::Element chiffre_dizaine_4(0, 0, 6, 0, 4);
    state::Element chiffre_dizaine_5(0, 0, 6, 0, 5);
    state::Element chiffre_dizaine_6(0, 0, 6, 0, 6);
    state::Element chiffre_dizaine_7(0, 0, 6, 0, 7);
    state::Element chiffre_dizaine_8(0, 0, 6, 0, 8);
    state::Element chiffre_dizaine_9(0, 0, 6, 0, 9);
    state::Element chiffre_dizaine_10(0, 0, 6, 0, 10);
    state::Element chiffre_dizaine_11(0, 0, 6, 0, 11);
    state::Element chiffre_dizaine_12(0, 0, 6, 0, 12);
    state::Element chiffre_dizaine_13(0, 0, 6, 0, 13);
    state::Element chiffre_dizaine_14(0, 0, 6, 0, 14);
    state::Element chiffre_dizaine_15(0, 0, 6, 0, 15);
    state::Element chiffre_dizaine_16(0, 0, 6, 0, 16);
    state::Element chiffre_dizaine_17(0, 0, 6, 0, 17);
    state::Element chiffre_dizaine_18(0, 0, 6, 0, 18);
    state::Element chiffre_dizaine_19(0, 0, 6, 0, 19);
    state::Element chiffre_dizaine_20(0, 0, 6, 0, 20);
    state::Element chiffre_dizaine_21(0, 0, 6, 0, 21);
    state::Element chiffre_dizaine_22(0, 0, 6, 0, 22);
    state::Element chiffre_dizaine_23(0, 0, 6, 0, 23);
    state::Element chiffre_dizaine_24(0, 0, 6, 0, 24);
    state::Element chiffre_dizaine_25(0, 0, 6, 0, 25);
    state::Element chiffre_dizaine_26(0, 0, 6, 0, 26);
    state::Element chiffre_dizaine_27(0, 0, 6, 0, 27);
    state::Element chiffre_dizaine_28(0, 0, 6, 0, 28);
    state::Element chiffre_dizaine_29(0, 0, 6, 0, 29);
    state::Element chiffre_dizaine_30(0, 0, 6, 0, 30);
    state::Element chiffre_unite_pris(0, 0, 5, 3);
    state::Element chiffre_dizaine_pris(0, 0, 6, 3);

    state::Element chiffre_gang(140, 200, 5, 4);



    list_map.add_element(tour0);
    list_map.add_element(tour1);
    list_map.add_element(tour2);
    list_map.add_element(tour3);
    list_map.add_element(tour4);
    list_map.add_element(tour5);
    list_map.add_element(tour6);
    list_map.add_element(tour7);
    list_map.add_element(tour8);
    list_map.add_element(tour9);
    list_map.add_element(tour10);
    list_map.add_element(tour11);
    list_map.add_element(tour12);
    list_map.add_element(tour13);
    list_map.add_element(tour14);
    list_map.add_element(tour15);
    list_map.add_element(tour16);
    list_map.add_element(tour17);
    list_map.add_element(tour18);
    list_map.add_element(tour19);
    list_map.add_element(tour20);
    list_map.add_element(tour21);
    list_map.add_element(tour22);
    list_map.add_element(tour23);
    list_map.add_element(tour24);
    list_map.add_element(tour25);
    list_map.add_element(tour26);
    list_map.add_element(tour27);
    list_map.add_element(tour28);
    list_map.add_element(tour29);
    list_map.add_element(tour30);


    list_map.add_element(chiffre_unite_0);
    list_map.add_element(chiffre_unite_1);
    list_map.add_element(chiffre_unite_2);
    list_map.add_element(chiffre_unite_3);
    list_map.add_element(chiffre_unite_4);
    list_map.add_element(chiffre_unite_5);
    list_map.add_element(chiffre_unite_6);
    list_map.add_element(chiffre_unite_7);
    list_map.add_element(chiffre_unite_8);
    list_map.add_element(chiffre_unite_9);
    list_map.add_element(chiffre_unite_10);
    list_map.add_element(chiffre_unite_11);
    list_map.add_element(chiffre_unite_12);
    list_map.add_element(chiffre_unite_13);
    list_map.add_element(chiffre_unite_14);
    list_map.add_element(chiffre_unite_15);
    list_map.add_element(chiffre_unite_16);
    list_map.add_element(chiffre_unite_17);
    list_map.add_element(chiffre_unite_18);
    list_map.add_element(chiffre_unite_19);
    list_map.add_element(chiffre_unite_20);
    list_map.add_element(chiffre_unite_21);
    list_map.add_element(chiffre_unite_22);
    list_map.add_element(chiffre_unite_23);
    list_map.add_element(chiffre_unite_24);
    list_map.add_element(chiffre_unite_25);
    list_map.add_element(chiffre_unite_26);
    list_map.add_element(chiffre_unite_27);
    list_map.add_element(chiffre_unite_28);
    list_map.add_element(chiffre_unite_29);
    list_map.add_element(chiffre_unite_30);

    list_map.add_element(chiffre_dizaine_0);
    list_map.add_element(chiffre_dizaine_1);
    list_map.add_element(chiffre_dizaine_2);
    list_map.add_element(chiffre_dizaine_3);
    list_map.add_element(chiffre_dizaine_4);
    list_map.add_element(chiffre_dizaine_5);
    list_map.add_element(chiffre_dizaine_6);
    list_map.add_element(chiffre_dizaine_7);
    list_map.add_element(chiffre_dizaine_8);
    list_map.add_element(chiffre_dizaine_9);
    list_map.add_element(chiffre_dizaine_10);
    list_map.add_element(chiffre_dizaine_11);
    list_map.add_element(chiffre_dizaine_12);
    list_map.add_element(chiffre_dizaine_13);
    list_map.add_element(chiffre_dizaine_14);
    list_map.add_element(chiffre_dizaine_15);
    list_map.add_element(chiffre_dizaine_16);
    list_map.add_element(chiffre_dizaine_17);
    list_map.add_element(chiffre_dizaine_18);
    list_map.add_element(chiffre_dizaine_19);
    list_map.add_element(chiffre_dizaine_20);
    list_map.add_element(chiffre_dizaine_21);
    list_map.add_element(chiffre_dizaine_22);
    list_map.add_element(chiffre_dizaine_23);
    list_map.add_element(chiffre_dizaine_24);
    list_map.add_element(chiffre_dizaine_25);
    list_map.add_element(chiffre_dizaine_26);
    list_map.add_element(chiffre_dizaine_27);
    list_map.add_element(chiffre_dizaine_28);
    list_map.add_element(chiffre_dizaine_29);
    list_map.add_element(chiffre_dizaine_30);
    list_map.add_element(chiffre_unite_pris);
    list_map.add_element(chiffre_dizaine_pris);

    list_boutique.add_element(background);
    list_boutique.add_element(money);
    list_boutique.add_element(plage_carte_A);
    list_boutique.add_element(plage_carte_B);
    list_boutique.add_element(plage_carte_C);
    list_boutique.add_element(logo_boutique);
    list_boutique.add_element(carte_verso_A);
    list_boutique.add_element(carte_verso_B);
    list_boutique.add_element(carte_verso_C);
    list_boutique.add_element(button_add);
    list_boutique.add_element(button_minus);
    list_boutique.add_element(button_ok_A);
    list_boutique.add_element(button_ok_B);
    list_boutique.add_element(button_ok_C);
    list_boutique.add_element(button_ok_compteur);
    list_boutique.add_element(chiffre_unite);
    list_boutique.add_element(chiffre_dizaine);
    list_boutique.add_element(prix_unite);
    list_boutique.add_element(prix_dizaine);
    list_boutique.add_element(prix_centaine);
    list_boutique.add_element(soldat);

    list_plage_menu.add_element(plage_menu);
    list_plage_menu.add_element(button_add_1);
    list_plage_menu.add_element(button_minus_1);
    list_plage_menu.add_element(chiffre_unite_01);
    list_plage_menu.add_element(chiffre_dizaine_01);
    list_plage_menu.add_element(button_ok_compteur_1);
    list_plage_menu.add_element(chiffre_unite_02);
    list_plage_menu.add_element(chiffre_dizaine_02);
    list_plage_menu.add_element(chiffre_unite_sec);
    list_plage_menu.add_element(chiffre_dizaine_sec);
    list_plage_menu.add_element(chiffre_gang);


    list_plage_commune.add_element(plage_commune);
    list_plage_commune.add_element(chiffre_unite_03);
    list_plage_commune.add_element(chiffre_dizaine_03);
    list_plage_commune.add_element(chiffre_centaine_03);
    list_plage_commune.add_element(chiffre_millier_03);
    list_plage_commune.add_element(chiffre_unite_032);
    list_plage_commune.add_element(chiffre_dizaine_032);



    this->add_ListElement(list_map);
    this->add_ListElement(list_minimap);
    this->add_ListElement(list_boutique);
    this->add_ListElement(list_plage_menu);
    this->add_ListElement(list_plage_commune);


    state::Territory territory_0(45, 0, 0, 3);

    state::Territory territory_1(10, 1, 0, -1);
    state::Territory territory_2(10, 2, 0, -1);
    state::Territory territory_3(34, 3, 0, -1);
    state::Territory territory_4(10, 4, 1, 2);
    state::Territory territory_5(10, 5, 0, -1);
    state::Territory territory_6(10, 6, 0, -1);
    state::Territory territory_7(10, 7, 0, -1);
    state::Territory territory_8(10, 8, 0, -1);
    state::Territory territory_9(10, 9, 0, -1);
    state::Territory territory_10(10, 10, 0, -1);
    state::Territory territory_11(10, 11, 0, -1);
    state::Territory territory_12(10, 12, 0, -1);
    state::Territory territory_13(10, 13, 0, -1);
    state::Territory territory_14(10, 14, 0, -1);
    state::Territory territory_15(10, 15, 0, -1);
    state::Territory territory_16(10, 16, 0, -1);
    state::Territory territory_17(10, 17, 0, -1);
    state::Territory territory_18(10, 18, 0, -1);
    state::Territory territory_19(10, 19, 0, -1);
    state::Territory territory_20(10, 20, 0, -1);
    state::Territory territory_21(10, 21, 0, -1);
    state::Territory territory_22(10, 22, 0, -1);
    state::Territory territory_23(10, 23, 0, -1);
    state::Territory territory_24(10, 24, 0, -1);
    state::Territory territory_25(45, 25, 1, 1);
    state::Territory territory_26(10, 26, 0, -1);
    state::Territory territory_27(10, 27, 0, -1);
    state::Territory territory_28(10, 28, 0, -1);
    state::Territory territory_29(10, 29, 0, -1);
    state::Territory territory_30(10, 30, 0, -1);


    //a ajouter en premier sinon modifier animation
    list_territory.push_back(territory_0);
    list_territory.push_back(territory_1);
    list_territory.push_back(territory_2);
    list_territory.push_back(territory_3);
    list_territory.push_back(territory_4);
    list_territory.push_back(territory_5);
    list_territory.push_back(territory_6);
    list_territory.push_back(territory_7);
    list_territory.push_back(territory_8);
    list_territory.push_back(territory_9);
    list_territory.push_back(territory_10);
    list_territory.push_back(territory_11);
    list_territory.push_back(territory_12);
    list_territory.push_back(territory_13);
    list_territory.push_back(territory_14);
    list_territory.push_back(territory_15);
    list_territory.push_back(territory_16);
    list_territory.push_back(territory_17);
    list_territory.push_back(territory_18);
    list_territory.push_back(territory_19);
    list_territory.push_back(territory_20);
    list_territory.push_back(territory_21);
    list_territory.push_back(territory_22);
    list_territory.push_back(territory_23);
    list_territory.push_back(territory_24);
    list_territory.push_back(territory_25);
    list_territory.push_back(territory_26);
    list_territory.push_back(territory_27);
    list_territory.push_back(territory_28);
    list_territory.push_back(territory_29);
    list_territory.push_back(territory_30);

    for (int i = 0; i < list_territory.size(); i++) {
        if (list_territory[i].get_QG() == 1)
            for (int j = 0; j < list_territory[i].getAdajcent().size(); j++)
                list_territory[list_territory[i].getAdajcent()[j]].set_gang(list_territory[i].get_gang());

    }
}