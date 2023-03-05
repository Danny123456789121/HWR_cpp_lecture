#include <sstream>
#include <iostream>
#include "Wetterstation.h"
using namespace std;

void Wetterstation::addMesswert(const Messure m) {
    if(m.getFlash() < 0 || m.getTemp() < -40 || m.getTemp() > 70) {
        throw invalid_argument("Messwerte sind nicht im gültigen Bereich");

    }else{
        messures.push_back(m);
    }
}

string Wetterstation::getMesswerte() const{
    ostringstream os;
    for(Messure m : this->messures){
        os << "Flash: " << m.getFlash() << " Temp: " << m.getTemp() << "\n";
    }
    return os.str();
}

string Wetterstation::getLightnings() const {
    ostringstream os;
    for(Messure m : this->messures){
        os << "Flash: " << m.getFlash() << "\n";
    }
    return os.str();
}

string Wetterstation::getTemperatures() const {
    ostringstream os;
    for(Messure m : this->messures){
        os <<"Temp: " << m.getTemp() << "\n";
    }
    return os.str();
}







