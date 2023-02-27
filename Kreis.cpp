#include <cmath>
#include "Kreis.h"
#include <iostream>
using namespace std;

double Kreis::getUmfang() const {
    return 2 * M_PI * m_radius;
}

double Kreis::getFlaeche() const {
    return M_PI * m_radius * m_radius;
}

void Kreis::zeichnen() const {
    cout << "Kreis\tPosition: " << m_position.getX() << "/" << m_position.getY()<< " Radius: " << m_radius;
    cout << " Umfang: " << this->getUmfang() << " Fleache: " << this->getFlaeche() << endl;
}

Kreis::Kreis(const Koordinate &position, double radius): ZeichenElement(position) {
    if(radius <= 0) {
        throw InvalidRadiusException();
    } else {
        m_radius = radius;
    }
}

const char *InvalidRadiusException::what() const noexcept {
    return "Invalid radius. Radius must be greater than zero.";
}

