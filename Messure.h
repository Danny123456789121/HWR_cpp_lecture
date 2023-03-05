#pragma once

#include <vector>
#include <ostream>

class Messure {
public:

    Messure(int flash, int temp) : flash(flash), temp(temp) {}

    float getFlash() const {
        return flash;
    }

    int getTemp() const {
        return temp;
    }

private:
    float flash;
    int temp;
};

