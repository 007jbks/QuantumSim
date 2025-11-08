#ifndef HADAMARD_H
#define HADAMARD_H

#include "gate.h"
#include <cmath>

class Hadamard : public Gate {
public:
    Hadamard() : Gate("Hadamard", 1) {
        Gate::gates.push_back("H");
        defineMatrix(); }
    void defineMatrix() override {
        double s = 1.0 / std::sqrt(2.0);
        matrix = {
            {{s,0}, {s,0}},
            {{s,0}, {-s,0}}
        };
    }
};

#endif
