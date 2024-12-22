#include <iostream>
#include <cstdlib>
#include <pybind11/pybind11.h>

namespace py = pybind11;

// Function that calculates n'th Fibonacci number using recursion
long double fibonacci_recursive(int n) {
    if (n < 2) {
        return n;
    } else {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}

// Function that calculates n'th Fibonacci number using iteration
long double fibonacci_iterative(int n) {
    long double n0, n1, n2;
    n0 = 0;
    n1 = 1;
    n2 = 0;
    for (int i = 0; i <= n; i++) {
        if (i < 2) {
            n0 = i;
        } else {
            n0 = n1 + n2;
            n2 = n1;
            n1 = n0;
        }
    }
    return n0;
}

// Pybind11 module definition
PYBIND11_MODULE(fibonacci, m) {
    m.doc() = "Fibonacci module implemented in C++"; // Optional module docstring

    m.def("fibonacci_recursive", &fibonacci_recursive, "Calculate Fibonacci number recursively");
    m.def("fibonacci_iterative", &fibonacci_iterative, "Calculate Fibonacci number iteratively");
}
