#include <stdio.h>

int fibonacci_naive(int n) {
    if (n == 1 || n == 0)
        return n;
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

void main() {
    int n;
    
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Error! Fibonacci of a negative number doesn't exist.");
    } else {
        printf("Fibonacci of %d = %d", n, fibonacci_naive(n));
    }
    scanf("%d", &n); // To keep the console window open
}