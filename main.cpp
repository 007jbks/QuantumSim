#include "Hadamard.h"
#include "xgate.h"
#include "ygate.h"
#include "zgate.h"
#include "qbit.h"
#include <complex>
#include <iostream>

using namespace std;

int main() {
    Hadamard h;
    XGate x;
    YGate y;
    ZGate z;

    complex<double> a(1/sqrt(2),0);
    complex<double> b(1/sqrt(2),0);

    Qbit bit1(a,b);

    bit1.applyGate(h);
    bit1.applyGate(x);

    bit1.printCircuit();

    Qbit bit2(a,b);

    bit2.applyGate(z);
    bit2.applyGate(y);
    bit2.printCircuit();


}
