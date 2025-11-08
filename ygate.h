#ifndef YGATE_H
#define YGATE_H

#include "gate.h"
#include <complex>

// Ygate constructor
class YGate : public Gate {
public:
    YGate() : Gate("Y", 1) {
        matrix = {
            {{0,0}, {0,-1}},
            {{0,1}, {0,0}}
        };
    }
    void defineMatrix() override {}
};

#endif
