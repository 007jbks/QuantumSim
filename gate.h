#ifndef GATE_H
#define GATE_H

#include <vector>
#include <complex>
#include <string>
#include <stdexcept>
#include <cmath>

class Gate {
protected:
    std::vector<std::vector<std::complex<double>>> matrix;
    std::string name;
    int numQubits;

    // Shared across all Gate objects
    static std::vector<std::string> gates;


public:
static void printCircuit();

    Gate(const std::string& n, int nq);
    virtual ~Gate() = default;

    std::string getName() const { return name; }
    int getNumQubits() const { return numQubits; }

    const std::vector<std::vector<std::complex<double>>>& getMatrix() const { return matrix; }

    virtual void defineMatrix() = 0;

    std::vector<std::complex<double>> apply(const std::vector<std::complex<double>>& state) const;

    static std::vector<std::string> getCircuit();
};

#endif
