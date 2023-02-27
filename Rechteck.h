#pragma once

#include "ZeichenElement.h"

class Rechteck : public ZeichenElement {
public:
    Rechteck(const Koordinate &position = Koordinate{}, double breite = 1.0, double hoehe = 1.0);
    virtual double getUmfang() const;
    virtual double getFlaeche() const;
    virtual void zeichnen() const;

private:
    double m_breite;
    double m_hoehe;
};

class InvalidDimensionException : public std::exception {
public:
    const char *what() const noexcept override;
};
