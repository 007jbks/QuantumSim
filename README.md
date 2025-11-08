# QuantumSim
### A Single-Qubit Quantum Computing Simulation Library in C++

---

##  Overview

**QuantumSim** is a lightweight and extensible C++ library designed to simulate and visualize the behavior of **single-qubit quantum systems**.
It provides a modular, object-oriented framework to represent qubits, apply quantum gates, and visualize gate sequences as readable circuit diagrams in the command line.

The project is built with mathematical correctness and extensibility in mind — serving both as a learning tool and as a foundation for larger quantum simulation frameworks.

---

## Features

### 1. Qubit Representation
- Models a single qubit state as:
  \[
  |\psi⟩ = \alpha|0⟩ + \beta|1⟩
  \]
  with the normalization condition \( |\alpha|^2 + |\beta|^2 = 1 \).
- Supports **complex-valued amplitudes** (`std::complex<double>`).
- Performs **automatic normalization check** on creation and after every gate operation.

---

### 2. Quantum Gate Framework
- Implements a polymorphic base class `Gate` defining the common interface for all quantum gates.
- Derived gate classes (Hadamard, Pauli-X, Pauli-Y, Pauli-Z) initialize their respective **2×2 unitary matrices**.
- Each gate performs standard **matrix–vector multiplication** on the qubit state.

#### Supported Gates

| Gate | Matrix | Description |
|------|---------|-------------|
| **Hadamard (H)** | \( \frac{1}{\sqrt{2}}\begin{bmatrix}1 & 1 \\ 1 & -1\end{bmatrix} \) | Creates and destroys superposition |
| **Pauli-X (X)** | \( \begin{bmatrix}0 & 1 \\ 1 & 0\end{bmatrix} \) | Bit-flip (NOT gate) |
| **Pauli-Y (Y)** | \( \begin{bmatrix}0 & -i \\ i & 0\end{bmatrix} \) | Bit-flip with phase rotation |
| **Pauli-Z (Z)** | \( \begin{bmatrix}1 & 0 \\ 0 & -1\end{bmatrix} \) | Phase-flip on |1⟩ |

Each gate enforces proper dimensionality and throws exceptions on invalid application.

---
### 3. Qubit Operations

QuantumSim allows you to manipulate qubit states by applying quantum gates directly through the `applyGate()` method.

#### Example: Basic Gate Application
```cpp
#include "Hadamard.h"
#include "XGate.h"
#include "ZGate.h"
#include "Qbit.h"
#include <iostream>
using namespace std;

int main() {
    Hadamard H;
    XGate X;
    ZGate Z;

    Qbit q({1,0}, {0,0}); // Initialize |0⟩

    cout << "Initial: " << q << endl;

    q.applyGate(H);  // Create superposition
    q.applyGate(X);  // Flip amplitudes
    q.applyGate(Z);  // Apply phase flip

    cout << "Final: " << q << endl;
    q.printCircuit();  // Visualize applied sequence
}
