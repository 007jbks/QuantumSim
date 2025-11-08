#include "Hadamard.h"
#include "xgate.h"
#include "ygate.h"
#include "zgate.h"
#include "qbit.h"
#include <iostream>

using namespace std;

int main() {
    Hadamard h;
    XGate x;
    YGate y;
    ZGate z;

    vector<pair<string, Qbit>> tests = {
        {"|0>", Qbit({1,0}, {0,0})},
        {"|1>", Qbit({0,0}, {1,0})}
    };

    for (auto& [label, q] : tests) {
        cout << "\n======================" << endl;
        cout << "Initial State: " << label << " → " << q << endl;

        Qbit qh = q;
        qh.applyGate(h);
        cout << "After Hadamard: " << qh << endl;

        Qbit qx = q;
        qx.applyGate(x);
        cout << "After X: " << qx << endl;

        Qbit qy = q;
        qy.applyGate(y);
        cout << "After Y: " << qy << endl;

        Qbit qz = q;
        qz.applyGate(z);
        cout << "After Z: " << qz << endl;

    }
    h.printCircuit();
}
