/*
write a program to find the prime numbers from 1 to n employing parallel for directive. record both series and parallel execution timers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Serial execution
    double start_time = omp_get_wtime();
    printf("Prime numbers (serial): ");
    for (int i = 1; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    double end_time = omp_get_wtime();
    printf("\nSerial execution time: %f seconds\n", end_time - start_time);

    // Parallel execution
    start_time = omp_get_wtime();
    printf("Prime numbers (parallel): ");
    #pragma omp parallel for
    for (int i = 1; i <= n; i++) {
        if (is_prime(i)) {
            #pragma omp critical
            printf("%d ", i);
        }
    }
    end_time = omp_get_wtime();
    printf("\nParallel execution time: %f seconds\n", end_time - start_time);

    return 0;
}