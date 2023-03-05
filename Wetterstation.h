#pragma once

#include <vector>
#include <iostream>
#include "Messure.h"
using namespace std;
class Wetterstation {
public:

    Wetterstation() = default;
    void addMesswert(Messure m);

    string getMesswerte() const;
    string getLightnings() const;
    string getTemperatures() const;



private:

    std::vector<Messure> messures;

};
