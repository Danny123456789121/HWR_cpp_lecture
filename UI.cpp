#include "UI.h"
#include <iostream>

using namespace std;

void UI::run() {
    while (true) {
        cout << "1. Set real part" << endl;
        cout << "2. Set imaginary part" << endl;
        cout << "3. Set magnitude" << endl;
        cout << "4. Set phase" << endl;
        cout << "5. Create complex number in polar form" << endl;
        cout << "6. Create complex number in cartesian form" << endl;
        cout << "7. Print both forms" << endl;
        cout << "8. Print cartesian form" << endl;
        cout << "9. Print polar form" << endl;
        cout << "10. Exit" << endl;
        handleChoice();
    }

}

void UI::handleChoice() {
    int choice = 0;
    while (choice != 10) {
        cin >> choice;
        switch (choice) {
            case 1: {
                double realPart;
                cout << "Enter the new real part: ";
                cin >> realPart;
                complexNumber.setReal(realPart);
                handler();
            }
            case 2: {
                double imaginaryPart;
                cout << "Enter the new imaginary part: ";
                cin >> imaginaryPart;
                complexNumber.setImaginary(imaginaryPart);
                handler();
            }
            case 3: {
                double magnitude;
                cout << "Enter the new magnitude: ";
                cin >> magnitude;
                complexNumber.setMagnitude(magnitude);
                handler();
            }
            case 4: {
                double phase;
                cout << "Enter the new phase: ";
                cin >> phase;
                complexNumber.setPhase(phase);
                handler();
            }
            case 5: {
                double magnitude, phase;
                cout << "Enter the new magnitude: ";
                cin >> magnitude;
                cout << "Enter the new phase: ";
                cin >> phase;
                ComplexNumber(ComplexNumber::PolarForm{magnitude,phase});
                handler();

            }
            case 6: {
                double realPart, imaginaryPart;
                cout << "Enter the new real part: ";
                cin >> realPart;
                cout << "Enter the new imaginary part: ";
                cin >> imaginaryPart;
                ComplexNumber(ComplexNumber::CartesianForm{realPart,imaginaryPart});
                handler();
            }
            case 7: {
                complexNumber.printComplexNumber();
                handler();
            }
            case 8: {
                complexNumber.printCartesian();
                handler();

            }
            case 9: {
                complexNumber.printPolarForm();
                handler();
            }
            case 10: {
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
