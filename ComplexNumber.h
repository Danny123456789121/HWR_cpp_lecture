#pragma once

class ComplexNumber {
private:
    double real, imag, magnitude, phase;

public:
    ComplexNumber();

    ComplexNumber(double real, double imag);

    ComplexNumber(double magnitude, double phase, bool polar);

    double getReal() const;

    double getImaginaryPart();

    double getMagnitude();

    double getPhase();

    void setRealPart(double real);

    void setImaginaryPart(double imag);

    void setMagnitude(double magnitude);

    void setPhase(double phase);

    void setComplexNumber(double real, double imag);

    void setComplexNumber(double magnitude, double phase, bool polar);

    void setReal();

    void setImag();

    void updateCartesianForm(double real, double imag);

    void updatePolarForm(double magnitude, double phase);

    void printComplexNumber();

    void printPolarForm();


};