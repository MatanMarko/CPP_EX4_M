// Matan Markovits 322318080
// matanmarkovits@gmail.com

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Complex
{
    private:
        double real; // Real part
        double imag; // Imaginary part

    public:
        // Magnitude of the complex number
        double magnitude() const;

        // Constructor to initialize to real + imag*i
        Complex(double r, double i);

        // Copy constructor
        Complex(const Complex &other);

        // Less than operator
        bool operator<(const Complex &other) const;

        // Greater than operator
        bool operator>(const Complex &other) const;

        // Greater than or equal operator
        bool operator>=(const Complex &other) const;

        // Less than or equal operator
        bool operator<=(const Complex &other) const;

        // Inequality operator
        bool operator!=(const Complex &other) const;

        // Getter for real part
        double getReal() const;

        // Getter for imaginary part
        double getImaginary() const;

        // Setter for real part
        void setReal(double r);

        // Setter for imaginary part
        void setImaginary(double i);

        // Equality operator
        bool operator==(const Complex &other) const;

        // Addition operator for two complex numbers
        Complex operator+(const Complex &other) const;

        // Subtraction operator for two complex numbers
        Complex operator-(const Complex &other) const;

        // Division operator for complex number by scalar
        Complex operator/(double scalar) const;

        // Multiplication operator for complex number by scalar
        Complex operator*(double scalar) const;

        // Division operator for two complex numbers
        Complex operator/(const Complex &other) const;

        // Multiplication operator for two complex numbers
        Complex operator*(const Complex &other) const;

        // Convert Complex to string
        string to_string();

        // Stream insertion operator
        friend ostream &operator<<(ostream &os, const Complex &complex);

        // Default constructor
        Complex();
};

#endif
