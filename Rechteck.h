#pragma once

#include "ZeichenElement.h"

class Rechteck : public ZeichenElement {
public:
    Rechteck(const Koordinate &position = Koordinate{}, double breite = 1.0, double hoehe = 1.0) : ZeichenElement(position), m_breite(breite), m_hoehe(hoehe) {};
    virtual double getUmfang() const;
    virtual double getFlaeche() const;

private:
    double m_breite;
    double m_hoehe;
};
