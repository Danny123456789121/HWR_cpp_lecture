#pragma once

class ComplexNumber {
private:
    double real, imag, magnitude, phase;

public:

    double getReal() const;

    double getImaginary() const;

    void setReal(double real);

    void setImaginary(double imag);

    void setMagnitude(double magnitude);

    void setPhase(double phase);

    void updateCartesianForm(double real, double imag);

    void updatePolarForm(double magnitude, double phase);

    void printCartesian();

    void printPolarForm();

    void printComplexNumber();
};