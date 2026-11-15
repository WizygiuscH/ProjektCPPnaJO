#include <iostream>
#include <limits>
#include "Autobus.h"
#include "Kino.h"
#include "Stadion.h"
using namespace std;

// wczytuje liczbe od uzytkownika i pyta dopoki nie poda dobrej (od min do max)
int wczytajWybor(int min, int max) {
    int wybor;
    while (true) {
        cout << "Twoj wybor: ";
        cin >> wybor;

        if (cin.fail() || wybor < min || wybor > max) {
            cin.clear(); // czyscimy blad
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // wyrzucamy zle znaki
            cout << "Zly wybor, sprobuj jeszcze raz.\n";
        } else {
            return wybor;
        }
    }
}

int main() {
    cout << "=== SYSTEM REZERWACJI ===\n";
    cout << "Jaki typ miejsca chcesz zarezerwowac?\n";
    cout << "1. Autobus\n";
    cout << "2. Kino\n";
    cout << "3. Stadion\n";

    int typ = wczytajWybor(1, 3);

    // tworzymy odpowiedni obiekt
    Obiekt* obiekt = nullptr;
    if (typ == 1) {
        //obiekt = new Autobus();
    } else if (typ == 2) {
        obiekt = new Kino();
    } else {
        //obiekt = new Stadion();
    }

    // pytamy o rodzaj biletu (stadion jeszcze nie ma biletow)
    vector<string> bilety = obiekt->getTypyBiletow();
    if (bilety.size() > 0) {
        cout << "\nWybierz rodzaj biletu:\n";
        for (int i = 0; i < (int)bilety.size(); i++) {
            cout << i + 1 << ". " << bilety[i] << "\n";
        }
        int wybranyBilet = wczytajWybor(1, bilety.size());
        cout << "\nWybrany bilet: " << bilety[wybranyBilet - 1] << "\n";
    }

    // pokazujemy siatke miejsc
    obiekt->wyswietlMiejsca();

    delete obiekt; // sprzatamy pamiec
    return 0;
}
