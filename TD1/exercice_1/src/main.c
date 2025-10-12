#include <stdio.h>
#include "..\include\fibonacci.h"
#include <time.h>

int main() {
    unsigned int n;
    clock_t start, end;
    float cpu_runtime;
    
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
        printf("Fibonacci of %i = %lld", n, fibonacci_naive(n));
    }
    end = clock();
    cpu_runtime = ((float)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken (naive): %f seconds\n", cpu_runtime);

    //DPFib
    start = clock();
    if (n < 0) {
        printf("Error! Fibonacci of a negative number doesn't exist.");
    } else {
        printf("Fibonacci of %i = %lld", n, fibonacci(n, DPFib));
    }
    end = clock();
    cpu_runtime = ((float)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken (DP): %f seconds\n", cpu_runtime);

    return 0;
}