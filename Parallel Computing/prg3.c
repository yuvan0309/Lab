/*Write a OpenMP program to calculate n fibonacci numbers using tasks*/

#include <stdio.h>
#include <omp.h>
#include <stdint.h>

int fib_omp(int n){
    int x,y;
    if (n<2){
        return n;
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
    #pragma omp parallel
    {
        #pragma omp single
        {
            printf("Fibonacci of %d is %d\n", n, fib_omp(n));
        }
    }
    end = omp_get_wtime();
    printf("Time taken: %f seconds\n", end - start);
    return 0;
}