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
    Hadamard H;
    XGate X;
    YGate Y;
    ZGate Z;

    // ─────────────────────────────────────────────
    // TEST 1: Basic single-qubit gates from |0>
    // ─────────────────────────────────────────────
    printSeparator("TEST 1: Single-qubit gates on |0>");

    Qbit q1({1,0}, {0,0}); // |0>
    cout << "Initial: " << q1 << endl;

    q1.applyGate(H);
    cout << "After H: " << q1 << endl;

    q1.applyGate(X);
    cout << "After X: " << q1 << endl;

    q1.applyGate(Z);
    cout << "After Z: " << q1 << endl;

    q1.printCircuit();

    // ─────────────────────────────────────────────
    // TEST 2: Single-qubit gates from |1>
    // ─────────────────────────────────────────────
    printSeparator("TEST 2: Single-qubit gates on |1>");

    Qbit q2({0,0}, {1,0}); // |1>
    cout << "Initial: " << q2 << endl;

    q2.applyGate(H);
    cout << "After H: " << q2 << endl;

    q2.applyGate(Y);
    cout << "After Y: " << q2 << endl;

    q2.applyGate(X);
    cout << "After X: " << q2 << endl;

    q2.printCircuit();

    // ─────────────────────────────────────────────
    // TEST 3: Superposition state (|0> + |1>)/√2
    // ─────────────────────────────────────────────
    printSeparator("TEST 3: Superposition (|0> + |1>)/√2");

    complex<double> a(1/sqrt(2), 0);
    complex<double> b(1/sqrt(2), 0);
    Qbit q3(a,b);

    cout << "Initial: " << q3 << endl;

    q3.applyGate(Z);
    cout << "After Z: " << q3 << endl;

    q3.applyGate(X);
    cout << "After X: " << q3 << endl;

    q3.applyGate(H);
    cout << "After H: " << q3 << endl;

    q3.printCircuit();

    // ─────────────────────────────────────────────
    // TEST 4: Phase-style test (complex coefficients)
    // ─────────────────────────────────────────────
    printSeparator("TEST 4: Complex phase state |ψ> = (i/√2)|0> + (1/√2)|1>");

    Qbit q4({0, 1/sqrt(2)}, {1/sqrt(2), 0}); // (i/√2)|0> + (1/√2)|1>
    cout << "Initial: " << q4 << endl;

    q4.applyGate(Y);
    cout << "After Y: " << q4 << endl;

    q4.applyGate(Z);
    cout << "After Z: " << q4 << endl;

    q4.applyGate(H);
    cout << "After H: " << q4 << endl;

    q4.printCircuit();

    // ─────────────────────────────────────────────
    // TEST 5: Randomized sequences for stress testing
    // ─────────────────────────────────────────────
    printSeparator("TEST 5: Randomized sequences");

    vector<Gate*> gates = {&H, &X, &Y, &Z};
    string names[] = {"H", "X", "Y", "Z"};

    for (int i = 1; i <= 3; ++i) {
        cout << "\n--- Random Circuit " << i << " ---" << endl;
        Qbit q({1,0}, {0,0}); // reset to |0>

        for (int j = 0; j < 5; ++j) {
            int idx = rand() % 4;
            q.applyGate(*gates[idx]);
            cout << "Applied " << names[idx] << ", State: " << q << endl;
        }

        q.printCircuit();
    }

    cout << "\n✅ All tests executed successfully.\n";
    return 0;
}
