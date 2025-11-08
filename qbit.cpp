#include "qbit.h"
#include "gate.h"

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

//getter and setter
std::complex<double> Qbit::getalpha() const { return alpha; }
std::complex<double> Qbit::getbeta() const { return beta; }

void Qbit::setalpha(const std::complex<double>& c) { alpha = c; }
void Qbit::setbeta(const std::complex<double>& c) { beta = c; }

//operator overloading  to print qubit
std::ostream& operator<<(std::ostream& out, const Qbit& obj) {
    out << "(" << obj.alpha << ")|0> + (" << obj.beta << ")|1>";
    return out;
}

// gate application function
void Qbit::applyGate(const Gate& gate) {
    const auto& mat = gate.getMatrix();

    // ensure 1 qubit system
    if (mat.size() != 2 || mat[0].size() != 2)
        throw std::invalid_argument("Gate is not a single-qubit (2x2) gate.");

    // tensor product
    std::complex<double> newAlpha = mat[0][0] * alpha + mat[0][1] * beta;
    std::complex<double> newBeta  = mat[1][0] * alpha + mat[1][1] * beta;

    alpha = newAlpha;
    beta  = newBeta;

    // Renormalization
    double norm = std::sqrt(std::norm(alpha) + std::norm(beta));
    alpha /= norm;
    beta  /= norm;

    // Track gate usage
    Qbit::gates.push_back(gate.getName());
}

// Utility function to print circuit
    void Qbit::printCircuit() {
        if (gates.empty()) {
            std::cout << "No gates in the circuit yet.\n";
            return;
        }

        std::cout << "\nQuantum Circuit:\n";
        // simple pattern building
        for (size_t i = 0; i < gates.size(); ++i) {
            std::cout << "┌";
            for (int j = 0; j < gates[i].size() + 2; ++j) std::cout << "─";
            std::cout << "┐   ";
        }
        std::cout << "\n";

        for (size_t i = 0; i < gates.size(); ++i) {
            std::cout << "│ " << gates[i] << " │";
            if (i != gates.size() - 1)
                std::cout << "──▶";
            else
                std::cout << "   ";
        }
        std::cout << "\n";

        for (size_t i = 0; i < gates.size(); ++i) {
            std::cout << "└";
            for (int j = 0; j < gates[i].size() + 2; ++j) std::cout << "─";
            std::cout << "┘   ";
        }
        std::cout << "\n";
    }
