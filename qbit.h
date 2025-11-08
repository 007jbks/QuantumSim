#ifndef QBIT_H
#define QBIT_H

#include <iostream>
#include <vector>
#include <complex>
#include "gate.h"


class Qbit {
private:
    std::complex<double> alpha;
    std::complex<double> beta;
    public:
    std::vector<std::string> gates;
    void printCircuit();
    Qbit(std::complex<double> a, std::complex<double> b);
    std::complex<double> getalpha() const;
    std::complex<double> getbeta() const;
    void setalpha(const std::complex<double>& n);
    void setbeta(const std::complex<double>& n);
    void applyGate(const Gate& gate);
    friend std::ostream& operator<<(std::ostream& out, const Qbit& obj);
};

#endif
