#include <stdio.h>
#include <time.h>
#include "prime_number.h"
#include "const.h"

int main () {
    unsigned int n;
    clock_t start, end;
    float cpu_time_used;
    unsigned int count = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    bool is_prime[n+1]; // Array to track prime status
    
    for (int i = 0; i <= n; i++) {
        is_prime[i] = false;
    }

    // Naive
    start = clock();
    for (int i = 2; i <= n; i++) {
        if (prime_num_naive(i)) {
            is_prime[i] = true;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            count++;
        }
    }

    end = clock();
    cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
    printf("Naive: Number of primes up to %i is %i\n", n, count);
    printf("Time taken (naive): %f seconds\n", cpu_time_used);

    // Optimized
    // reset array and count
    count = 0;
    for (int i = 0; i <= n; i++) {
        is_prime[i] = false;
    }

    start = clock();
    for (int i = 2; i <= n; i++) {
        if (prime_num(i)) {
            is_prime[i] = true;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            count++;
        }
    }

    end = clock();
    cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
    printf("Optimized: Number of primes up to %i is %i\n", n, count);
    printf("Time taken (optimized): %f seconds\n", cpu_time_used);

    return 0;
}