#pragma once

#include "ZeichenElemente.h"

class Rechteck : public ZeichenElemente {

public:
    Rechteck();
    Rechteck(int x, int y, int breite, int hoehe);
    ~Rechteck();

    void zeichnen();

    int getBreite();
    int getHoehe();

    void setBreite(int breite);
    void setHoehe(int hoehe);

};
