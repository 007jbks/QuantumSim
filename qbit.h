#ifndef QBIT_H
#define QBIT_H

#include <vector>

class Complex{
    public:
    double real;
    double img;
    Complex(double a , double b);
    friend std::ostream& operator<<(std::ostream out, Complex& obj);
};

class Qbit{
    private:
        Complex alpha;
        Complex beta;
    public:
        Qbit(Complex a,Complex b);
        Complex getalpha() const ;
        Complex getbeta() const ;
        void setalpha(const Complex& n);
        void setbeta(const Complex& n);

        friend std::ostream& operator<<(std::ostream& out,const  Qbit& obj);
};

#endif
