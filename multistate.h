#ifndef MULTISTATE_H
#define MULTISTATE_H

#include<complex>
#include<vector>

class MultiState{
    private:
    std::vector<std::complex<double>> StateVector;
    public:
    MultiState(std::vector<std::complex<double>> input );
    const std::vector<std::complex<double>>& getState() const { return StateVector; }
    friend std::ostream& operator<<(std::ostream& out, const MultiState& obj);
};


#endif
