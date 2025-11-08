#ifndef ZGATE_H
#define ZGATE_H

#include "gate.h"
#include <complex>

// Zgate constructor
class ZGate : public Gate {
public:
    ZGate() : Gate("Z", 1) {
        matrix = {
            {{1,0}, {0,0}},
            {{0,0}, {-1,0}}
        };
    }

    void defineMatrix() override {}
};

#endif
