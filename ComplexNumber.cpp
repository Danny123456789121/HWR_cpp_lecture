#include <cmath>
#include <iostream>
#include <sstream>
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

string ComplexNumber::printCartesian() const {
    ostringstream os;
    cout << "\nIn cartesian form: "<< this->real << " + " << this->imag << "i" << endl;
    return os.str();
}

string ComplexNumber::printPolarForm() const {
    ostringstream os;
    os << "The polar form is: " << this->magnitude << " * (cos(" << this->phase << ") + sin(" << this->phase << ")i)" << endl;
    return os.str();
}

string ComplexNumber::printComplexNumber() const {
    ostringstream os;
    os << printPolarForm() << printCartesian();
    return os.str();
}

ComplexNumber::ComplexNumber(const ComplexNumber::PolarForm &params) : magnitude(params.magnitude),
                                                                       phase(params.phase) {
    updatePolarForm(params.magnitude, params.phase);
}

ComplexNumber::ComplexNumber(const ComplexNumber::CartesianForm &params) : real(params.real), imag(params.imag) {
    updateCartesianForm(params.real, params.imag);
}

ComplexNumber::ComplexNumber(double real) {
    double angle = (real >= 0) ? 45 : -45;
    this->real = real * cos(angle);
    this->imag = real * sin(angle);
}
