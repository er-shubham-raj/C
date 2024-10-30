#include <stdio.h>

// Function to compute Fibonacci numbers using Dynamic Programming
int fibonacci(int n) {
    // Array to store Fibonacci numbers
    int fib[n + 1];
    fib[0] = 0;  // Base case: fib(0) = 0
    fib[1] = 1;  // Base case: fib(1) = 1

    // Fill the array from bottom-up
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

// Driver code to test the function
int main() {
    int n = 10;  // Find the 10th Fibonacci number
    printf("The %dth Fibonacci number is %d\n", n, fibonacci(n));
    return 0;
}
