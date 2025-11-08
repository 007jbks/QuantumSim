#ifndef CNOT_H
#define CNOT_H

#include "gate.h"

class CNOT : public Gate {
public:
    CNOT() : Gate("CNOT", 2) { defineMatrix(); }
    void defineMatrix() override {
        matrix = {
            {{1,0}, {0,0}, {0,0}, {0,0}},
            {{0,0}, {1,0}, {0,0}, {0,0}},
            {{0,0}, {0,0}, {0,0}, {1,0}},
            {{0,0}, {0,0}, {1,0}, {0,0}}
        };
    }
};

#endif
