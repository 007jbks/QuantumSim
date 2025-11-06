#ifndef QBIT_H
#define QBIT_H

#include <iostream>
#include <vector>

class Complex {
public:
    double real;
    double img;

    Complex(double a = 0, double b = 0);

    friend std::ostream& operator<<(std::ostream& out, const Complex& obj);
};

class Qbit {
private:
    Complex alpha;
    Complex beta;

public:
    Qbit(Complex a, Complex b);

    Complex getalpha() const;
    Complex getbeta() const;

    void setalpha(const Complex& n);
    void setbeta(const Complex& n);

    friend std::ostream& operator<<(std::ostream& out, const Qbit& obj);
};


class Qbits{
    private:
        std::vector<Complex> stateVector;
    public:
        Qbits(std::vector<Complex> vector);
};

#endif
