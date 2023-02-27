#pragma once
#include "Koordinate.h"

class ZeichenElement { ;
    Koordinate getPosition() const {
        return m_position;
    };
protected:
    ZeichenElement(const Koordinate& position) {
        m_position = position;
    }

private:
    Koordinate m_position;

public:
    virtual double getUmfang() const = 0;
    virtual double getFlaeche() const = 0;
};
