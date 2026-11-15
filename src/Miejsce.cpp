#include "Miejsce.h"

// na poczatku kazde miejsce jest wolne
Miejsce::Miejsce(string oznaczenie) {
    this->oznaczenie = oznaczenie;
    zajete = false;
}

string Miejsce::getOznaczenie() const {
    return oznaczenie;
}

bool Miejsce::czyZajete() const {
    return zajete;
}

void Miejsce::zajmij() {
    zajete = true;
}

void Miejsce::zwolnij() {
    zajete = false;
}
