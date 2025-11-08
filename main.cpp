#include "Hadamard.h"
#include "xgate.h"
#include "qbit.h"
#include <iostream>

int main() {
    Qbit q({0,0}, {1,0}); // |1>
    Hadamard h;
    XGate x;

    std::cout << "Initial: " << q << std::endl;

    q.applyGate(h);
    std::cout << "After H: " << q << std::endl;

    q.applyGate(x);
    std::cout << "After X: " << q << std::endl;

}
