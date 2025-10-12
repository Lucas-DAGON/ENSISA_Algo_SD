#include <stdio.h>
#include "..\include\fibonacci.h"

#include <inttypes.h>
uint64_t fibonacci(unsigned int n, uint64_t DPFib[]) {
    if (n <= 1) return n;
    if (DPFib[n] != (uint64_t)-1) return DPFib[n];

    DPFib[n] = fibonacci(n - 1, DPFib) + fibonacci(n - 2, DPFib);
    return DPFib[n];
}

uint64_t fibonacci_naive(unsigned int n) {
    if (n <= 1)
        return n;
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}
