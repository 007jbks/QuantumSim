#include "gate.h"
#include<iostream>
#include "qbit.h"

Gate::Gate(const std::string& n, int nq)
    : name(n), numQubits(nq)
{
}

// std::vector<std::complex<double>> Gate::apply(const std::vector<std::complex<double>>& state) const {
//     if (matrix.empty())
//         throw std::runtime_error("Gate matrix not defined.");

//     size_t dim = matrix.size();
//     if (state.size() != dim)
//         throw std::invalid_argument("State vector size does not match gate matrix dimension.");

//     std::vector<std::complex<double>> result(dim, {0, 0});

//     for (size_t i = 0; i < dim; ++i)
//         for (size_t j = 0; j < dim; ++j)
//             result[i] += matrix[i][j] * state[j];
//     Qbit::gates.push_back(Gate::name);

//     return result;
// }
