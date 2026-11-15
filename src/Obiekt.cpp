#include "Obiekt.h"

Obiekt::Obiekt(string nazwa) {
    this->nazwa = nazwa;
}

string Obiekt::getNazwa() const {
    return nazwa;
}

vector<string> Obiekt::getTypyBiletow() const {
    return typyBiletow;
}

int Obiekt::getLiczbaMiejsc() const {
    return miejsca.size();
}
