#include "gate.h"
#include<iostream>
// static member
std::vector<std::string> Gate::gates = {};

Gate::Gate(const std::string& n, int nq)
    : name(n), numQubits(nq)
{
}

std::vector<std::complex<double>> Gate::apply(const std::vector<std::complex<double>>& state) const {
    if (matrix.empty())
        throw std::runtime_error("Gate matrix not defined.");

    size_t dim = matrix.size();
    if (state.size() != dim)
        throw std::invalid_argument("State vector size does not match gate matrix dimension.");

    std::vector<std::complex<double>> result(dim, {0, 0});

    for (size_t i = 0; i < dim; ++i)
        for (size_t j = 0; j < dim; ++j)
            result[i] += matrix[i][j] * state[j];

    return result;
}

std::vector<std::string> Gate::getCircuit() {
    return gates;
}

void Gate::printCircuit() {
    if (gates.empty()) {
        std::cout << "No gates in the circuit yet.\n";
        return;
    }

    std::cout << "\nQuantum Circuit:\n";

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
