#include <stdio.h>
#include "fibonacci.h"
#include <time.h>

void main() {
    int n;
    clock_t start, end;
    
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    long long int DPFib[n + 1];
    for(int i = 0; i <= n; i++) {
        DPFib[i] = -1;
    }
    

    //naive
    start = clock();
    if (n < 0) {
        printf("Error! Fibonacci of a negative number doesn't exist.");
    } else {
        printf("Fibonacci of %d = %d", n, fibonacci_naive(n));
    }
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken (naive): %f seconds\n", time_spent);

    //DPFib
    start = clock();
    if (n < 0) {
        printf("Error! Fibonacci of a negative number doesn't exist.");
    } else {
        printf("Fibonacci of %d = %d", n, fibonacci(n, DPFib));
    }
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken (DP): %f seconds\n", time_spent);
}