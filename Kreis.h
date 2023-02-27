#pragma once
#include "Koordinate.h"
#include "ZeichenElement.h"
#include <exception>

class Kreis : public ZeichenElement{
    public:
        Kreis(const Koordinate &position = Koordinate{}, double radius = 1.0);
        virtual double getUmfang() const;
        virtual double getFlaeche() const;
        virtual void zeichnen() const;
    private:
        double m_radius;

    void setRadius(double radius);
};

class InvalidRadiusException : public std::exception {
public:
    const char *what() const noexcept override;
};
