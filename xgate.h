#ifndef  XGATE_H
#define XGATE_H

#include "gate.h"
#include "qbit.h"

class XGate : public Gate {
    public:
    XGate() : Gate("X",1) {
        defineMatrix() ;
    }
    void defineMatrix() override {
        matrix = {
            {{0,0}, {1,0}},
            {{1,0}, {0,0}}
        };
    }
};

#endif
