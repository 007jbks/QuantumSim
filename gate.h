#ifndef GATE_H
#define GATE_H

#include <vector>
#include <complex>
#include <string>
#include <stdexcept>
#include <cmath>

class Gate {
protected:
    std::vector<std::vector<std::complex<double>>> matrix; // 2x2 or 4x4 etc.
    std::string name;
    int numQubits;

public:
    Gate(const std::string& n, int nq) : name(n), numQubits(nq) {}
    virtual ~Gate() = default;

    std::string getName() const { return name; }
    int getNumQubits() const { return numQubits; }

    const std::vector<std::vector<std::complex<double>>>& getMatrix() const { return matrix; }

    virtual void defineMatrix() = 0;

    std::vector<std::complex<double>> apply(const std::vector<std::complex<double>>& state) const {
        if (matrix.empty())
            throw std::runtime_error("Gate matrix not defined.");

        size_t dim = matrix.size();
        if (state.size() != dim)
            throw std::invalid_argument("State vector size does not match gate matrix dimension.");

        std::vector<std::complex<double>> result(dim, {0, 0});

        for (size_t i = 0; i < dim; ++i) {
            for (size_t j = 0; j < dim; ++j) {
                result[i] += matrix[i][j] * state[j];
            }
        }
        return result;
    }
};

#endif
