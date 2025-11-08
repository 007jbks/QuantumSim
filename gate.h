#ifndef  GATE_H
#define GATE_H

#include<vector>
#include<complex>

class Gate{
    protected:
    std::vector<std::vector<std::complex<double>>> matrix;
    std::string name;
    int numQbits;

    public:
    Gate(const std::string name,int nq) {}
    virtual ~Gate() = default;
    std::string getName() const { return name; }
    int getNumQubits() const { return numQbits; }
    const std::vector<std::vector<std::complex<double>>>& getMatrix() const { return matrix; }
    virtual void defineMatrix() = 0;

};




#endif
