#pragma once

#include "UI.h"
#include <iostream>

using namespace std;

void UI::run() {
    int choice = 0;
    double, imaginaryPart, magnitude, phase;
    while (choice != 5) {
        cin >> choice;
        switch (choice) {
            case 1: {
                double realPart;
                cout << "Enter the new real part: ";
                cin >> realPart;
                complexNumber.setRealPart(realPart);
                break;
            }
            case 2: {
                double imaginaryPart;
                cout << "Enter the new imaginary part: ";
                cin >> imaginaryPart;
                complexNumber.setImaginaryPart(imaginaryPart);
                break;
            }
            case 3: {
                double magnitude;
                cout << "Enter the new magnitude: ";
                cin >> magnitude;
                complexNumber.setMagnitude(magnitude);
                break;
            }
            case 4: {
                double phase;
                cout << "Enter the new phase: ";
                cin >> phase;
                complexNumber.setPhase(phase);
                break;
            }
            case 5: {
                exit(0);
            }
        }
    }
}

void displayComplexNumber() {
    cout << "Complex number: ";
    cout << complexNumber.getRealPart() << " + " << complexNumber.getImaginaryPart() << "i" << endl;
    cout << "In polar form: ";
    cout << complexNumber.getMagnitude() << " * e^(i * " << complexNumber.getPhase() << ")" << endl;
}