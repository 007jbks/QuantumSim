#include "Hadamard.h"
#include "xgate.h"
#include "ygate.h"
#include "zgate.h"
#include "qbit.h"
#include <complex>
#include <iostream>
#include <cmath>
using namespace std;

// Utility for printing separator lines
void printSeparator(const string& title) {
    cout << "\n==============================================\n";
    cout << "▶ " << title << endl;
    cout << "==============================================\n";
}

int main() {

    complex<double> a(1/sqrt(2),0);
    complex<double> b(1/sqrt(2),0);

    Qbit bit(a,b);

    bit.applyGate(Hadamard());
    bit.applyGate(XGate());

    bit.printCircuit();

    return 0;
}
