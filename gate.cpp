#include "gate.h"
#include<iostream>
#include "qbit.h"


// gate constructor
Gate::Gate(const std::string& n, int nq)
    : name(n), numQubits(nq)
{
}
