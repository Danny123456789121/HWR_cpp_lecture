# pragma once
# include "Koordinate.h"
# include "ZeichenElement.h"
# include "Kreis.h"
# include "Rechteck.h"
# include <iostream>
#include "UI.h"
using namespace std;

void  UI::run() {
    ZeichenElement *elemente[10];
    int index = 0;
    while (index < 10) {
        // ZeichenElement erstellen
        cout << "1. Möchten Sie ein Zeichenobjekt erstellen  \n 2. Die Objekte Anzeigen  \n 3. Das Programm verlassen?"
             << endl;
        int auswahl;
        cin >> auswahl;
        try {
            if (auswahl == 1) {
                char zeichenElement;
                cout << "Welches Zeichenobjekt möchten Sie erstellen? (K/R): ";
                cin >> zeichenElement;
                double x, y, radius;
                cout << "Koordinate x: ";
                cin >> x;
                cout << "Koordinate y: ";
                cin >> y;
                Koordinate koordinate(x, y);
                if (zeichenElement == 'K') {
                    cout << "Radius: ";
                    cin >> radius;
                    elemente[index] = new Kreis(koordinate, radius);
                } else if (zeichenElement == 'R') {
                    double breite, hoehe;
                    cout << "Breite: ";
                    cin >> breite;
                    cout << "Hoehe: ";
                    cin >> hoehe;
                    elemente[index] = new Rechteck(koordinate, breite, hoehe);
                } else
                    cout << "Ungültige Eingabe!" << endl;
                index++;
            } else if (auswahl == 2) {
                char anzeige;
                double gesamtFlaeche = 0;
                cout << "Wähle zwischen gemischter Anzeige oder sortierter Anzeige (G/S): " << endl;
                cin >> anzeige;
                if (anzeige == 'G') {
                    // ZeichenElement anzeigen
                    cout << "Gemischte Anzeige: " << endl;
                    for (int i = 0; i < index; i++) {
                        elemente[i]->zeichnen();
                        gesamtFlaeche += elemente[i]->getFlaeche();
                    }
                } else if (anzeige == 'S') {
                    // Sortieren: erst Kreise dann Rechtecke
                    cout << "Sortierte Anzeige: " << endl;
                    double gesamtFlaecheKreis = 0;
                    double gesamtFlaecheRechteck = 0;
                    for (int i = 0; i < index; i++) {
                        if (dynamic_cast<Rechteck *>(elemente[i])) {
                            for (int j = i + 1; j < index; j++) {
                                if (dynamic_cast<Kreis *>(elemente[j])) {
                                    ZeichenElement *temp = elemente[i];
                                    elemente[i] = elemente[j];
                                    elemente[j] = temp;
                                    break;
                                }
                            }
                        }
                    }
                    for (int i = 0; i < index; i++) {
                        elemente[i]->zeichnen();
                        if (dynamic_cast<Kreis *>(elemente[i])) {
                            gesamtFlaecheKreis += elemente[i]->getFlaeche();
                        } else if (dynamic_cast<Rechteck *>(elemente[i])) {
                            gesamtFlaecheRechteck += elemente[i]->getFlaeche();
                        }
                    }
                    cout << "Gesamtfläche Kreis: " << gesamtFlaecheKreis << endl;
                    cout << "Gesamtfläche Rechteck: " << gesamtFlaecheRechteck << endl;
                } else {
                    cout << "Ungültige Eingabe!" << endl;
                }
                cout << "Gesamtfläche: " << gesamtFlaeche << endl;
                cout << endl;
            } else if (auswahl == 3) {
                exit(0);
            } else {
                std::cout << "Ungültige Eingabe!" << std::endl;
            }
        } catch (const exception &e) {
            cout << e.what() << endl;
            cout << endl;
            continue;
        }
    }
    if (index == 10) {
        std::cout << "Maximale Anzahl an Elementen erreicht!" << std::endl;
    }
    // Speicher freigeben
    for (int i = 0; i < index; i++) {
        delete elemente[i];
    }
    exit(0);
}
