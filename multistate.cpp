#include "multistate.h"

#include "multistate.h"
#include <cmath>
#include <stdexcept>

MultiState::MultiState(std::vector<std::complex<double>> input)
    : StateVector(input)
{
    size_t n = input.size();

    // return error if user tries to assign type Qbit to multistate
    if(n==2) {
        throw std::invalid_argument("Qbit is not multistate assign a type Qbit instead.");
    }

    // Check for empty state
    if (n == 0)
        throw std::invalid_argument("State vector cannot be empty.");

    // Check if n is a power of 2
    if ((n & (n - 1)) != 0)
        throw std::invalid_argument("Invalid state vector length: must be 2^n for some n.");

    // check normalization
    double norm = 0.0;
    for (auto& amp : input) norm += std::norm(amp);
    if (std::abs(norm - 1.0) > 1e-9)
        throw std::invalid_argument("Invalid state: amplitudes must be normalized (|ψ|² = 1).");
}


std::ostream& operator<<(std::ostream& out, const MultiState& obj)
{
    size_t n = obj.StateVector.size();
    int numQubits = static_cast<int>(std::log2(n));

    for (size_t i = 0; i < n; ++i) {
        out << "(" << obj.StateVector[i] << ")|";

        // print binary representation of i as basis state
        for (int j = numQubits - 1; j >= 0; --j)
            out << ((i >> j) & 1);

        out << ">";
        if (i != n - 1) out << " + ";
    }

    return out;
}
