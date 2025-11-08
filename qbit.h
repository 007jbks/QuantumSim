#ifndef QBIT_H
#define QBIT_H

#include <iostream>
#include <vector>
#include <complex>



class Qbit {
private:
    std::complex<double> alpha;
    std::complex<double> beta;
public:
    Qbit(std::complex<double> a, std::complex<double> b);
    std::complex<double> getalpha() const;
    std::complex<double> getbeta() const;
    void setalpha(const std::complex<double>& n);
    void setbeta(const std::complex<double>& n);
    friend std::ostream& operator<<(std::ostream& out, const Qbit& obj);
};


class Qbits{
    private:
        std::vector<std::complex<double>> stateVector;
    public:
        Qbits(std::vector<std::complex<double>> vector);
};

#endif
