#pragma once

class Koordinate {
public:
    Koordinate(double x = 0.0 , double y = 0.0): m_x(x), m_y(y) {};
    void setX(double x) {
        this->m_x = x;
    };
    void setY(double y) {
        this->m_y = y;
    };
    double getX() const {
        return this->m_x;
    };
    double getY() const {
        return this->m_y;
    };
private:
    double m_x;
    double m_y;
};
