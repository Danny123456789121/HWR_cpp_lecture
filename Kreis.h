#pragma once
#include "Koordinate.h"
#include "ZeichenElement.h"

class Kreis : public ZeichenElement{
    public:
        Kreis(const Koordinate &position = Koordinate{}, double radius = 1.0) : ZeichenElement(position), m_radius(radius) {};
        virtual double getUmfang() const;
        virtual double getFlaeche() const;

    private:
        double m_radius;
};
