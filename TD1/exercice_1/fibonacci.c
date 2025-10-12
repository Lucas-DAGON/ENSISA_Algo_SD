#include <stdio.h>
#include <fibonacci.h>

int fibonacci(int n, int DPFib[]) {
    if (n <= 1) return n;

    if (DPFib[n] != -1) return DPFib[n];

    DPFib[n] = fibonacci(n - 1, DPFib) + fibonacci(n - 2, DPFib);
    return DPFib[n];

}

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}
