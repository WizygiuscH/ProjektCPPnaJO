#include <iostream>
#include "Kino.h"
using namespace std;

Kino::Kino() : Obiekt("Kino") {
    // w kinie sa 4 rodzaje biletu
    typyBiletow.push_back("Bilet normalny");
    typyBiletow.push_back("Bilet ulgowy");
    typyBiletow.push_back("Bilet dla dzieci");
    typyBiletow.push_back("Bilet dla seniorow");

    // tworzymy miejsca: A1, A2 ... A10, B1 ... O10
    for (int rzad = 0; rzad < 15; rzad++) {
        char litera = 'A' + rzad;
        for (int numer = 1; numer <= 10; numer++) {
            miejsca.push_back(Miejsce(string(1, litera) + to_string(numer)));
        }
    }

    // na probe zajmujemy kilka miejsc zeby bylo widac [x]
    // (czasowo zajmujemy miejsca A1, C8 i O10)
    miejsca[0].zajmij();   // A1
    miejsca[27].zajmij();  // C8
    miejsca[149].zajmij(); // O10
}

void Kino::wyswietlMiejsca() const {
    cout << "\n=== KINO - plan miejsc ===\n";
    cout << "          E K R A N\n\n";

    // numery siedzen nad siatka
    cout << "    ";
    for (int numer = 1; numer <= 10; numer++) {
        cout << " " << numer << (numer < 10 ? "  " : " ");
    }
    cout << "\n";

    for (int rzad = 0; rzad < 15; rzad++) {
        // co 5 rzedow zaczyna sie nowy sektor
        if (rzad % 5 == 0) {
            cout << "\n--- Sektor " << rzad / 5 + 1 << " ---\n";
        }

        cout << (char)('A' + rzad) << "   "; // litera rzedu

        for (int numer = 0; numer < 10; numer++) {
            // rzad * 10 + numer to numer miejsca w wektorze
            if (miejsca[rzad * 10 + numer].czyZajete()) {
                cout << "[x] ";
            } else {
                cout << "[o] ";
            }
        }
        cout << "\n";
    }

    cout << "\n[o] - wolne, [x] - zajete\n";
}
