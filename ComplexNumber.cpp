#include <cmath>
#include <iostream>
#include "ComplexNumber.h"

using namespace std;

double ComplexNumber::getReal() const {
    return real;
}

double ComplexNumber::getImaginary() const {
    return imag;
}

void ComplexNumber::setReal(double real) {
    updateCartesianForm(real, this->imag);
}

void ComplexNumber::setImaginary(double imag) {
    updateCartesianForm(this->real, imag);
}

void ComplexNumber::setMagnitude(double magnitude) {
    updatePolarForm(magnitude, this->phase);
}

void ComplexNumber::setPhase(double phase) {
    updatePolarForm(this->magnitude, phase);
}

void ComplexNumber::updateCartesianForm(double real, double imag) {
    this->real = real;
    this->imag = imag;
    this->magnitude = sqrt(pow(real, 2) + pow(imag, 2));
    this->phase = atan(imag / real);
}

void ComplexNumber::updatePolarForm(double magnitude, double phase) {
    this->magnitude = magnitude;
    this->phase = phase;
    this->real = magnitude * cos(phase);
    this->imag = magnitude * sin(phase);
}

void ComplexNumber::printCartesian() {
    cout << "\nIn cartesian form: ";
    cout << real << " + " << imag << "i" << endl;
}

void ComplexNumber::printPolarForm() {
    double r = sqrt(pow(getReal(), 2) + pow(getImaginary(), 2));
    double theta = atan2(getImaginary(), getReal());
    cout << "The polar form is: " << r << " * (cos(" << theta << ") + i * sin(" << theta << "))" << endl;
}

void ComplexNumber::printComplexNumber() {
    printCartesian();
    printPolarForm();
}

ComplexNumber::ComplexNumber(const ComplexNumber::PolarForm &params) : magnitude(params.magnitude),
                                                                       phase(params.phase) {
    updatePolarForm(params.magnitude, params.phase);
}

ComplexNumber::ComplexNumber(const ComplexNumber::CartesianForm &params) : real(params.real), imag(params.imag) {
    updateCartesianForm(params.real, params.imag);
}
