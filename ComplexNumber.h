#pragma once

class ComplexNumber {
private:
    double real, imag, magnitude, phase;

public:

    struct PolarForm {
        double magnitude, phase;
    };

    struct CartesianForm {
        double real, imag;
    };

    ComplexNumber() = default;

    explicit ComplexNumber(const PolarForm& params);

    explicit ComplexNumber(const CartesianForm& params);

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