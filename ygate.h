#ifndef YGATE_H
#define YGATE_H

#include "gate.h"
#include <complex>

class YGate : public Gate {
public:
    YGate() : Gate("Y", 1) { defineMatrix(); }
    void defineMatrix() override {
        matrix = {
            {{0,0}, {0,-1}},
            {{0,1}, {0,0}}
        };
    }
};

#endif
