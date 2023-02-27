#include "Rechteck.h"
#include <iostream>
using namespace std;

double Rechteck::getUmfang() const {
    return 2 * (m_breite + m_hoehe);
}

double Rechteck::getFlaeche() const {
    return m_breite * m_hoehe;
}

void Rechteck::zeichnen() const {
    cout << "Rechteck\tPosition: " << m_position.getX() << "/" << m_position.getY() << " Breite: " << m_breite << " Hoehe: " << m_hoehe;
    cout << " Umfang: " << this->getUmfang() << " Flaeche: " << this->getFlaeche() << "\n" << endl;
}

Rechteck::Rechteck(const Koordinate &position, double breite, double hoehe) : ZeichenElement(position) {
    if(breite <= 0 || hoehe <= 0) {
        throw InvalidDimensionException();
    } else {
        m_breite = breite;
        m_hoehe = hoehe;
    }
}

const char *InvalidDimensionException::what() const noexcept {
    return "Invalid dimension. Dimension must be greater than zero.";
}
