/*Write a OpenMP program to calculate n fibonacci numbers using tasks*/

#include <stdio.h>
#include <omp.h>
#include <stdint.h>

// Sequential fibonacci for small values
int fib_seq(int n) {
    if (n < 2) return n;
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int fib_omp(int n){
    int x,y;
    if (n<2){
        return n;
    }
    // Use sequential computation for small values to reduce task overhead
    if (n < 20) {
        return fib_seq(n);
    }
    #pragma omp task shared(x)
    {
        x = fib_omp(n-1);
    }
    #pragma omp task shared(y)
    {
        y = fib_omp(n-2);
    }
    #pragma omp taskwait
    return x+y;
}

int main(){
    //int n = 10;
    int n;
    printf("Enter the number of Fibonacci numbers to calculate: ");
    scanf("%d", &n);
    double start,end;
    start = omp_get_wtime();
    int num_threads = 0;
    #pragma omp parallel
    {
        #pragma omp single
        {
            num_threads = omp_get_num_threads();
            printf("Number of threads used: %d\n", num_threads);
            printf("Fibonacci of %d is %d\n", n, fib_omp(n));
        }
    }
    end = omp_get_wtime();
    printf("Time taken: %f seconds\n", end - start);
    return 0;
}