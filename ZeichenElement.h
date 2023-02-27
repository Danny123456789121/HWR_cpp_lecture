#pragma once
#include "Koordinate.h"
#include <exception>

class ZeichenElement { ;
    Koordinate getPosition() const {
        return m_position;
    };
protected:
    ZeichenElement(const Koordinate& position) {
        m_position = position;
    }
    Koordinate m_position;

public:
    virtual double getUmfang() const = 0;
    virtual double getFlaeche() const = 0;
    virtual void zeichnen() const = 0;
    virtual ~ZeichenElement() = default;
};

