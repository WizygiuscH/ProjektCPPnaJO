#ifndef OBIEKT_H
#define OBIEKT_H

#include <string>
#include <vector>
#include "Miejsce.h"
using namespace std;

// klasa ogolna dla autobusu, kina i stadionu
// zeby nie pisac wszystkiego 3 razy, reszta klas po niej dziedziczy
class Obiekt {
protected:
    string nazwa;              // np. "Autobus"
    vector<string> typyBiletow; // jakie sa rodzaje biletow
    vector<Miejsce> miejsca;    // wszystkie miejsca w obiekcie

public:
    Obiekt(string nazwa);
    virtual ~Obiekt() {}

    string getNazwa() const;
    vector<string> getTypyBiletow() const;
    int getLiczbaMiejsc() const;

    // kazdy obiekt wyswietla miejsca po swojemu, dlatego "virtual"
    virtual void wyswietlMiejsca() const = 0;
};

#endif
