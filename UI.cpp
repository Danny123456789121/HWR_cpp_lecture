# pragma once
# include "Koordinate.h"
# include "ZeichenElement.h"
# include "Kreis.h"
# include "Rechteck.h"
# include <iostream>
#include "UI.h"
using namespace std;

void UI::run() {
    while (true) {
        cout << "1. Zeichenelement erstellen" << endl;
        cout << "2. Anzeigen" << endl;
        cout << "3. Programm beenden" << endl;
        handleChoice();
    }

}

void UI::handleChoice() {
    int choice = 0;
    while (choice != 4) {
        cin >> choice;
        switch (choice) {
            case 1: {
                int choice2;
                cout << "1. Kreis \n 2. Rechteck" << endl;
                cin >> choice2;
                if (choice2 == 1){
                    double radius;
                    cout << "Enter the radius: ";
                    cin >> radius;
                    Kreis kreis(radius);
                }
                else if (choice2 == 2){
                    double breite, hoehe;
                    cout << "Enter the width: ";
                    cin >> breite;
                    cout << "Enter the height: ";
                    cin >> hoehe;
                    Rechteck rechteck(breite, hoehe);
                }
                handler();
            }
            case 2: {
                double choice2;
                cout << "1. Reihenfolge gemischt \n 2. Reihenfolge sortiert" << endl;
                cin >> choice2;
                if (choice2 == 1){

                }
                else if (choice2 == 2){
                    // ZeichenElement::printSorted();
                }
                handler();
            }
            case 3: {
                exit(0);
            }

        }
    }
}

void UI::handler(){
    cout << "\nWant to do another action?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;

    int choice;
    cin >> choice;
    if (choice == 1){
        run();
    }
    else{
        exit(0);
    }
}