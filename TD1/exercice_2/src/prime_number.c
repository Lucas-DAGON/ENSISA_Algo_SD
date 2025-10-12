#include "prime_number.h"
#include "const.h"


bool prime_num_naive(unsigned int n) {
    if (n <= 1) return false; // 0 and 1 are not prime numbers
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false; // Found a divisor, not prime
    }
    return true; // No divisors found, it's prime
}

bool prime_num(unsigned int n) { 
    if (n <= 1) return false; // 0 and 1 are not prime numbers  
    if (n <= 3) return true; // 2 and 3 are prime numbers
    if (n % 2 == 0 || n % 3 == 0) return false; // Eliminate multiples of 2 and 3

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false; // Check for factors of the form 6k ± 1
    }
    return true; // No divisors found, it's prime
}