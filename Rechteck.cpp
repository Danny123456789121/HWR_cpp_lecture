#include "Rechteck.h"

double Rechteck::getUmfang() const {
    return 2 * (m_breite + m_hoehe);
}

double Rechteck::getFlaeche() const {
    return m_breite * m_hoehe;
}
