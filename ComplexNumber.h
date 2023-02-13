#pragma once
#include <iostream>

class ComplexNumber {
private:
    double real, imag, magnitude, phase;

public:

    struct Float{
        float x,y;
    };

    struct Double{
        float x,y;
    };

    struct PolarForm {
        double magnitude, phase;
    };

    struct CartesianForm {
        double real, imag;
    };

    explicit ComplexNumber(const PolarForm& params);

    explicit ComplexNumber(const CartesianForm& params);

    ComplexNumber(double real);

    ComplexNumber() = default;

    double getReal() const;

    double getImaginary() const;

    void setReal(double real);

    void setImaginary(double imag);

    void setMagnitude(double magnitude);

    void setPhase(double phase);

    void updateCartesianForm(double real, double imag);

    void updatePolarForm(double magnitude, double phase);

    std::string printCartesian() const;

    std::string printPolarForm() const;

    std::string printComplexNumber() const;
};