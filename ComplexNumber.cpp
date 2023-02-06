#pragma once
#include <cmath>
#include <iostream>
#include "ComplexNumber.h"

using namespace std;

ComplexNumber::ComplexNumber() {

}

ComplexNumber::ComplexNumber(double real, double imag) {
    this->real = real;
    this->imag = imag;
}

ComplexNumber::ComplexNumber(double magnitude, double phase, bool polar) {
    this->magnitude = magnitude;
    this->phase = phase;
}

double ComplexNumber::getReal() const {
    return real
}

double ComplexNumber::getImaginaryPart() {
    return imag
}

double ComplexNumber::getMagnitude() {
    return magnitude;
}

double ComplexNumber::getPhase() {
    return phase;
}

void ComplexNumber::setRealPart(double real) {

}

void ComplexNumber::setImaginaryPart(double imag) {

}

void ComplexNumber::setMagnitude(double magnitude) {

}

void ComplexNumber::setPhase(double phase) {

}

void ComplexNumber::setComplexNumber(double real, double imag) {

}

void ComplexNumber::setComplexNumber(double magnitude, double phase, bool polar) {

}

void ComplexNumber::setReal() {
    this->real = magnitude * cos(phase);
}

void ComplexNumber::setImag() {
    this->imag = magnitude * sin(phase);
}

void ComplexNumber::updateCartesianForm(double real, double imag) {
    this->real = magnitude * cos(phase);
    this->imag = magnitude * sin(phase);
}

void ComplexNumber::updatePolarForm(double magnitude, double phase) {
    this->magnitude = sqrt(pow(real, 2) + pow(imag, 2));
    this->phase = atan(imag / real);
}

void ComplexNumber::printComplexNumber() {
    cout << "Complex number: ";
    cout << real << " + " << imag << "i" << endl;
}

void ComplexNumber::printPolarForm() {
    cout << "In polar form: ";
    cout << getMagnitude() << " * e^(i * " << getPhase() << ")" << endl;
}