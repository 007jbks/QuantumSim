#ifndef ZGATE_H
#define ZGATE_H

#include "gate.h"

class ZGate : public Gate {
public:
    ZGate() : Gate("Z", 1) {
        Gate::gates.push_back("Z");
        defineMatrix(); }
    void defineMatrix() override {
        matrix = {
            {{1,0}, {0,0}},
            {{0,0}, {-1,0}}
        };
    }
};

#endif
