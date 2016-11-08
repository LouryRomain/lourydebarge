#include "ListElement.h"
#include <iostream>

state::ListElement::ListElement(int id_view) {
    this->size = 0;
    this->id_view = id_view;
}

state::ListElement::~ListElement() {

}

void state::ListElement::add_element(state::Element element) {
    list_element.push_back(element);
    size++;
}

std::vector<state::Element> state::ListElement::getlist() {
    return list_element;
}

int state::ListElement::getSize() {
    return size;
}

int state::ListElement::getIdView() {
    return id_view;
}

void state::ListElement::setIdView(int id_view) {
    this->id_view = id_view;
}