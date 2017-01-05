

#include "Territory.h"

state::Territory::Territory() {
    nb_unit = new int;
    *nb_unit=0;
    gang=new int;
    *gang=-1;
    old_gang.push_back(-1);
    
}

state::Territory::~Territory() {

}

int state::Territory::get_nb_unit() const {
    return *nb_unit;
}

void state::Territory::set_nb_unit(int nb_unit) {
    if  (nb_unit < 100) {
       
        *(this->nb_unit) = nb_unit;
    }
    else {
        *(this->nb_unit) = 99;}
}

int state::Territory::get_gang() const{
    return *gang;
}


void state::Territory::set_gang(int gang) {
  
    this->old_gang.push_back(*this->gang);
  
    *this->gang=gang;
    
}

int state::Territory::get_old_gang() const{
    
    return old_gang[old_gang.size()-1];
   
}

void state::Territory::set_old_gang(int gang) {
   
    this->old_gang.push_back(gang);
    
}

int state::Territory::get_ID() const {
    return ID;
}

void state::Territory::set_ID(int ID) {
    this->ID = ID;
}

bool state::Territory::get_QG() const {
    return QG;
}

void state::Territory::set_QG(bool boolean_QG) {
    this->QG = boolean_QG;
}

std::vector<int> state::Territory::getAdajcent() const {
    return Adjacent;
}

state::Territory state::Territory::clone() const{
    state::Territory ter(*nb_unit,ID,QG,*gang);
    return ter;
    
    
}

void state::Territory::addAdjacent(int adjacent) {
    this->Adjacent.push_back(adjacent);
}



state::Territory::Territory(int nb_unit, int Id, bool QG, int owner) {
    this->QG = QG;
    gang=new int;
    *gang = owner;
    this->nb_unit = new int;
    *(this->nb_unit) = nb_unit;
   
    old_gang.push_back(owner);
    this->ID = Id;
    if (Id == 0) {
        Adjacent.push_back(2);
        Adjacent.push_back(3);
        Adjacent.push_back(4);
        Adjacent.push_back(1);


    }
    if (Id == 1) {
        Adjacent.push_back(0);
        Adjacent.push_back(6);
        Adjacent.push_back(7);
        Adjacent.push_back(5);

    }
    if (Id == 2) {
        Adjacent.push_back(0);
        Adjacent.push_back(3);
        Adjacent.push_back(8);
        Adjacent.push_back(9);


    }
    if (Id == 3) {
        Adjacent.push_back(0);
        Adjacent.push_back(2);
        Adjacent.push_back(8);
        Adjacent.push_back(4);


    }
    if (Id == 4) {
        Adjacent.push_back(0);
        Adjacent.push_back(3);
        Adjacent.push_back(8);
        Adjacent.push_back(12);
        Adjacent.push_back(6);

    }
    if (Id == 5) {
        Adjacent.push_back(1);
        Adjacent.push_back(7);
        Adjacent.push_back(13);
        Adjacent.push_back(17);


    }
    if (Id == 6) {
        Adjacent.push_back(4);
        Adjacent.push_back(7);
        Adjacent.push_back(1);
        Adjacent.push_back(12);
        Adjacent.push_back(13);

    }
    if (Id == 7) {
        Adjacent.push_back(5);
        Adjacent.push_back(6);
        Adjacent.push_back(1);
        Adjacent.push_back(13);


    }
    if (Id == 8) {
        Adjacent.push_back(3);
        Adjacent.push_back(2);
        Adjacent.push_back(4);
        Adjacent.push_back(11);
        Adjacent.push_back(10);

    }
    if (Id == 9) {
        Adjacent.push_back(2);
        Adjacent.push_back(10);
        Adjacent.push_back(18);
        Adjacent.push_back(27);

    }
    if (Id == 10) {
        Adjacent.push_back(11);
        Adjacent.push_back(8);
        Adjacent.push_back(9);
        Adjacent.push_back(20);
        Adjacent.push_back(18);

    }
    if (Id == 11) {
        Adjacent.push_back(8);
        Adjacent.push_back(10);
        Adjacent.push_back(12);
        Adjacent.push_back(14);
        Adjacent.push_back(19);

    }
    if (Id == 12) {
        Adjacent.push_back(4);
        Adjacent.push_back(6);
        Adjacent.push_back(11);
        Adjacent.push_back(15);
        Adjacent.push_back(14);

    }
    if (Id == 13) {
        Adjacent.push_back(6);
        Adjacent.push_back(7);
        Adjacent.push_back(16);
        Adjacent.push_back(15);
        Adjacent.push_back(5);

    }
    if (Id == 14) {
        Adjacent.push_back(11);
        Adjacent.push_back(12);
        Adjacent.push_back(15);
        Adjacent.push_back(21);
        Adjacent.push_back(19);
        

    }
    if (Id == 15) {
        Adjacent.push_back(14);
        Adjacent.push_back(16);
        Adjacent.push_back(12);
        Adjacent.push_back(21);
        Adjacent.push_back(13);

    }
    if (Id == 16) {
        Adjacent.push_back(13);
        Adjacent.push_back(15);
        Adjacent.push_back(24);
        Adjacent.push_back(22);
        Adjacent.push_back(17);

    }
    if (Id == 17) {
        Adjacent.push_back(22);
        Adjacent.push_back(16);
        Adjacent.push_back(30);
        Adjacent.push_back(5);


    }

    if (Id == 18) {
        Adjacent.push_back(10);
        Adjacent.push_back(20);
        Adjacent.push_back(27);
        Adjacent.push_back(9);

    }
    if (Id == 19) {
        Adjacent.push_back(20);
        Adjacent.push_back(23);
        Adjacent.push_back(11);
        Adjacent.push_back(21);

    }
    if (Id == 20) {
        Adjacent.push_back(18);
        Adjacent.push_back(19);
        Adjacent.push_back(27);
        Adjacent.push_back(10);
        Adjacent.push_back(23);

    }
    if (Id == 21) {
        Adjacent.push_back(25);
        Adjacent.push_back(19);
        Adjacent.push_back(14);
        Adjacent.push_back(15);
        Adjacent.push_back(24);
    }
    if (Id == 22) {
        Adjacent.push_back(24);
        Adjacent.push_back(16);
        Adjacent.push_back(17);
        Adjacent.push_back(30);

    }
    if (Id == 23) {
        Adjacent.push_back(20);
        Adjacent.push_back(25);
        Adjacent.push_back(19);
        Adjacent.push_back(26);
        Adjacent.push_back(28);

    }
    if (Id == 24) {
        Adjacent.push_back(21);
        Adjacent.push_back(16);
        Adjacent.push_back(22);
        Adjacent.push_back(30);
        Adjacent.push_back(25);

    }
    if (Id == 25) {
        
        Adjacent.push_back(23);
        Adjacent.push_back(24);
        Adjacent.push_back(26);
        Adjacent.push_back(29);
        Adjacent.push_back(21);

    }
    if (Id == 26) {
        Adjacent.push_back(23);
        Adjacent.push_back(28);
        Adjacent.push_back(29);
        Adjacent.push_back(25);

    }
    if (Id == 27) {
        Adjacent.push_back(9);
        Adjacent.push_back(18);
        Adjacent.push_back(28);
        Adjacent.push_back(20);

    }
    if (Id == 28) {
        Adjacent.push_back(27);
        Adjacent.push_back(23);
        Adjacent.push_back(26);
        Adjacent.push_back(29);

    }
    if (Id == 29) {
        Adjacent.push_back(30);
        Adjacent.push_back(26);
        Adjacent.push_back(28);
        Adjacent.push_back(25);


    }
    if (Id == 30) {
        Adjacent.push_back(29);
        Adjacent.push_back(24);
        Adjacent.push_back(22);
        Adjacent.push_back(17);

    }

}