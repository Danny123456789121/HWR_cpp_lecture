#include <cmath>
#include "Kreis.h"

double Kreis::getUmfang() const {
    return 2 * M_PI * m_radius;
}

double Kreis::getFlaeche() const {
    return M_PI * m_radius * m_radius;
}
