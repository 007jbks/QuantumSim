#include "qbit.h"

//Qbit constructor
Qbit::Qbit(std::complex<double> a, std::complex<double> b) {
    double norm = std::norm(a) + std::norm(b);
    //normalization check (valid quantum states only)
    if (std::abs(norm - 1.0) > 1e-9) {
        throw std::invalid_argument("Invalid Qbit initialization: |a|^2 + |b|^2 must equal 1.");
    }
    alpha = a;
    beta = b;
}

std::complex<double> Qbit::getalpha() const { return alpha; }
std::complex<double> Qbit::getbeta() const { return beta; }

void Qbit::setalpha(const std::complex<double>& c) { alpha = c; }
void Qbit::setbeta(const std::complex<double>& c) { beta = c; }

std::ostream& operator<<(std::ostream& out, const Qbit& obj) {
    out << "(" << obj.alpha << ")|0> + (" << obj.beta << ")|1>";
    return out;
}
