// Matan Markovits 322318080
// matanmarkovits@gmail.com

#include <cmath>
#include <stdexcept>
#include "Complex.hpp"

// Constructor - initializes to 0 + 0i
Complex::Complex() : real(0), imag(0) {}

// Constructor - initializes with given real and imaginary parts
Complex::Complex(double realPart, double imagPart) : real(realPart), imag(imagPart) {}

// Copy constructor - clone another Complex
Complex::Complex(const Complex &other) : real(other.real), imag(other.imag) {}

// Getters for real and imaginary parts
double Complex::getReal() const { return real; }
double Complex::getImaginary() const { return imag; }

// Setters for real and imaginary parts
void Complex::setReal(double realPart) { real = realPart; }
void Complex::setImaginary(double imagPart) { imag = imagPart; }

// Add two complex numbers
Complex Complex::operator+(const Complex &other) const {
    return Complex(real + other.real, imag + other.imag);
}

// Subtract two complex numbers
Complex Complex::operator-(const Complex &other) const {
    return Complex(real - other.real, imag - other.imag);
}

// Multiply complex number by a scalar
Complex Complex::operator*(double scalar) const {
    double newReal = real * scalar;
    double newImag = imag * scalar;
    return Complex(newReal, newImag);
}

// Divide complex number by scalar
Complex Complex::operator/(double scalar) const {
    if (scalar == 0) throw invalid_argument("Division by zero error");
    return Complex(real / scalar, imag / scalar);
}

// Multiply two complex numbers
Complex Complex::operator*(const Complex &other) const {
    return Complex(
        (real * other.real - imag * other.imag),
        (real * other.imag + imag * other.real)
    );
}

// Divide two complex numbers
Complex Complex::operator/(const Complex &other) const {
    double denom = other.real * other.real + other.imag * other.imag;
    if (denom == 0) throw invalid_argument("Division by zero error");
    return Complex(
        (real * other.real + imag * other.imag) / denom,
        (imag * other.real - real * other.imag) / denom
    );
}

// Equality check
bool Complex::operator==(const Complex &other) const {
    return real == other.real && imag == other.imag;
}

// Inequality check
bool Complex::operator!=(const Complex &other) const {
    return !(*this == other);
}

// Magnitude (absolute value) of the complex number
double Complex::magnitude() const {
    return sqrt(real * real + imag * imag);
}

// Less than operator, compares magnitudes
bool Complex::operator<(const Complex &other) const {
    return magnitude() < other.magnitude();
}

// Greater than operator, compares magnitudes
bool Complex::operator>(const Complex &other) const {
    return magnitude() > other.magnitude();
}

// Less than or equal operator
bool Complex::operator<=(const Complex &other) const {
    return magnitude() <= other.magnitude();
}

// Greater than or equal operator
bool Complex::operator>=(const Complex &other) const {
    return magnitude() >= other.magnitude();
}

// Print complex number
ostream &operator<<(ostream &os, const Complex &complex) {
    os << complex.real;
    if (complex.imag >= 0) os << "+" << complex.imag << "i";
    else os << complex.imag << "i";
    return os;
}

// Convert Complex to string
string Complex::to_string() {
    stringstream ss;
    ss << real << (imag >= 0 ? "+" : "") << imag << "i";
    return ss.str();
}
