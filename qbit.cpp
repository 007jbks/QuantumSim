#include "qbit.h"
#include<iostream>
#include <ostream>

Qbit::Qbit(Complex a, Complex b) : alpha(a),beta(b) {}
Complex::Complex(double a, double b) : real(a), img(b) {}

std::ostream& operator<<(std::ostream& out ,const  Complex& obj){
    if(obj.real==0 && obj.img==0) {
        out<<"0";
        return out;
    }
    else if(obj.real==0 && obj.img!=0){
        out<<obj.img<<"j";
        return out;
    }
    else if(obj.real==0 && obj.img!=0){
        out<<obj.real;
        return out;
    }
    out<<obj.real<<"+"<<obj.img<<"j";
    return out;
}

Complex Qbit::getalpha() const { return alpha; }
Complex Qbit::getbeta() const { return beta; }

void Qbit::setalpha(const Complex& c) { alpha = c; }
void Qbit::setbeta(const Complex& c) { beta = c; }


std::ostream& operator<<(std::ostream& out, const Qbit& obj){
     out<<"("<<obj.alpha<<")"<<"|0> + "<<"("<<obj.beta<<")"<<"|1>"<<std::endl;
     return out;
}
